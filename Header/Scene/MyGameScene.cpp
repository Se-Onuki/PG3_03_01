#include "MyGameScene.h"

#include <imgui.h>
#include <Novice.h>
#include "TitleScene.h"

MyGameScene::MyGameScene() {
}

MyGameScene::~MyGameScene() {

}

void MyGameScene::OnEnter() {
}

void MyGameScene::OnExit() {}

void MyGameScene::Update([[maybe_unused]] float deltaTime) {
}

void MyGameScene::Draw() {
	Novice::DrawBox(0, 0, 100, 100, 0.f, 0xFFFFFFFF, kFillModeSolid);
}