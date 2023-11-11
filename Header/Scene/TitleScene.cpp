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
	if (pInputManager_->IsTrigger(DIK_A)) {
		pSceneManager_->ChangeScene(new MyGameScene{}, 1.f);
	}
}

void TitleScene::Draw() {
}
