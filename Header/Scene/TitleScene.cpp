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
	Novice::DrawBox(0, 0, 1280, 720, 0.f, RED, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "TitleScene : Push SPACE");
	const auto &sceneTimer = pSceneManager_->GetTimer();
	Novice::ScreenPrintf(0, 20, "Change Progress %.2f / %.2f : %3.0lf%%", sceneTimer.GetNowFlame(), sceneTimer.GetGoalFlame(), static_cast<double>(sceneTimer.GetProgress()) * 100.f);
}
