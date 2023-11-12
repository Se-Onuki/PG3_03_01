#include <Novice.h>
#include "Header/Scene/SceneManager.h"
#include "Header/Scene/TitleScene.h"
#include <imgui.h>
#include <Header/InputManager.h>

const char kWindowTitle[] = "LE2A_04_オヌキ_セイヤ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	InputManager *const inputManager = InputManager::GetInstance();

	SceneManager *const sceneManager = SceneManager::GetInstance();
	sceneManager->Init();
	sceneManager->ChangeScene(std::make_unique<TitleScene>());

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		inputManager->Update();

		///
		/// ↓更新処理ここから
		///

		const float deltaTime = ImGui::GetIO().DeltaTime;

		sceneManager->Update(deltaTime);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		sceneManager->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (inputManager->IsTrigger(DIK_ESCAPE)) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
