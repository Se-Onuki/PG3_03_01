#include "MyGameScene.h"

#include <imgui.h>
#include <Novice.h>
#include "TitleScene.h"

MyGameScene::MyGameScene() {
}

MyGameScene::~MyGameScene() {

}

void MyGameScene::OnEnter() {

	AddObject(std::make_unique<Player>());

	for (auto &object : objectList_) {
		object->Init();
	}

	pCollisionManager_ = CollisionManager::GetInstance();
}

void MyGameScene::OnExit() {}

void MyGameScene::Update([[maybe_unused]] float deltaTime) {


	// オブジェクトを全て走査して、死亡していたら破棄して除外する
	objectList_.remove_if(
		[](std::unique_ptr<Object> &object) {
			// もし死んでいたら
			if (not object->isAlive_) {
				// 破棄して除外
				object.reset();
				return true;
			}
			// 死んでいないなら
			// そのまま無視
			return false;
		}
	);


#pragma region Collision

	// データの破棄
	pCollisionManager_->clear();

	// 全データの追加
	for (auto &object : objectList_) {
		pCollisionManager_->push_back(object.get());
	}

	// 当たり判定の走査
	pCollisionManager_->ChackAllCollision();

#pragma endregion

	// 全オブジェクトの更新
	for (auto &object : objectList_) {
		object->Update();
	}

	// プレイヤの一覧をオブジェクトのリストから取得して、その総数が0になったらゲーム終了とする
	if (GetAllObject<Player>().size() == 0u) {
		pSceneManager_->ChangeScene(new TitleScene{}, 1.f);
	}
}

void MyGameScene::Draw() {
	for (auto &object : objectList_) {
		object->Draw();
	}
}

void MyGameScene::AddObject(std::unique_ptr<Object> object) {
	object->pGameScene_ = this;
	objectList_.push_back(std::move(object));
}
