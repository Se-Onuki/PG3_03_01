#include "OverScene.h"

#include <imgui.h>
#include "MyGameScene.h"
#include "TitleScene.h"

OverScene::OverScene() {
}

OverScene::~OverScene() {
}

void OverScene::OnEnter() {
}

void OverScene::OnExit() {
}

void OverScene::Update([[maybe_unused]] float deltaTime) {
	if (pInputManager_->IsTrigger(DIK_SPACE)) {
		pSceneManager_->ChangeScene(std::make_unique<TitleScene>(), 1.f);
	}
}

void OverScene::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.f, GREEN, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "GameOverScene : Push SPACE");
	const auto &sceneTimer = pSceneManager_->GetTimer();
	Novice::ScreenPrintf(0, 20, "Change Progress %.2f / %.2f : %3.0lf%%", sceneTimer.GetNowFlame(), sceneTimer.GetGoalFlame(), static_cast<double>(sceneTimer.GetProgress()) * 100.f);
}
