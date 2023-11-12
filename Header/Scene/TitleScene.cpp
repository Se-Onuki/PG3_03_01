#include "TitleScene.h"

#include <imgui.h>
#include "MyGameScene.h"

TitleScene::TitleScene() {
}

TitleScene::~TitleScene() {
}

void TitleScene::OnEnter() {
}

void TitleScene::OnExit() {
}

void TitleScene::Update([[maybe_unused]] float deltaTime) {
	if (pInputManager_->IsTrigger(DIK_SPACE)) {
		pSceneManager_->ChangeScene(std::make_unique<MyGameScene>(), 1.f);
	}
}

void TitleScene::Draw() {
	Novice::ScreenPrintf(0, 0, "TitleScene : Push SPACE");
	Novice::ScreenPrintf(0, 20, "Change Progress %.2f / %.2f",pSceneManager_->);
}
