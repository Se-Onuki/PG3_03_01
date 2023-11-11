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

void SceneManager::ChangeScene(IScene *const nextScene) {
	if (nextScene == nullptr) return;
	if (currentScene_) {
		// 遷移前のシーンの退室処理
		currentScene_->OnExit();
	}
	// 保持するシーンのキーとポインタを更新
	currentScene_.reset(nextScene);
	currentScene_->OnEnter();
}

void SceneManager::ChangeScene(IScene *const nextScene, const float transitionTime) {
	// もし、次のシーンがあったらキャンセル
	if (nextScene_ != nullptr) {
		delete nextScene;
		return;
	}
	// 次のシーンのポインタを保存
	nextScene_.reset(nextScene);
	// 遷移タイマーを開始
	transitionTimer_.Start(transitionTime);
}

void SceneManager::Update(float deltaTime) {
	if (transitionTimer_.Update(deltaTime) && transitionTimer_.IsFinish()) {
		ChangeScene(nextScene_.release());
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