#include "SceneManager.h"

SceneManager *const IScene::pSceneManager_ = SceneManager::GetInstance();
InputManager *const IScene::pInputManager_ = InputManager::GetInstance();


void SceneManager::Init() {
	transitionTimer_.Clear();
}

void SceneManager::Cancel() {
	nextScene_.reset();
	transitionTimer_.Clear();
}

void SceneManager::ChangeScene(std::unique_ptr<IScene> nextScene) {
	if (nextScene == nullptr) return;
	if (currentScene_) {
		// 遷移前のシーンの退室処理
		currentScene_->OnExit();
	}
	// 保持するシーンのキーとポインタを更新
	currentScene_ = std::move(nextScene);
	currentScene_->OnEnter();
}

void SceneManager::ChangeScene(std::unique_ptr<IScene> nextScene, const float transitionTime) {
	// もし、次のシーンがあったらキャンセル
	if (nextScene_ != nullptr) {
		return;
	}
	// 次のシーンのポインタを保存
	nextScene_ = std::move(nextScene);
	// 遷移タイマーを開始
	transitionTimer_.Start(transitionTime);
}

void SceneManager::Update(float deltaTime) {
	if (transitionTimer_.Update(deltaTime) && transitionTimer_.IsFinish()) {
		ChangeScene(std::move(nextScene_));
	}

	if (currentScene_) {
		currentScene_->Update(deltaTime);
	}
}

void SceneManager::Draw() const {
	if (currentScene_) {
		currentScene_->Draw();
	}
}