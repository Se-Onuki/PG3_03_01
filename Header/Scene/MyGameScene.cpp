#include "MyGameScene.h"

#include <imgui.h>
#include <Novice.h>
#include "TitleScene.h"
#include "OverScene.h"

MyGameScene::MyGameScene() {
}

MyGameScene::~MyGameScene() {

}

void MyGameScene::OnEnter() {

	pCollisionManager_ = CollisionManager::GetInstance();
	// プレイヤを追加
	auto *player = this->AddObject(std::make_unique<Player>());	// AddObjectで、ObjectのInitが呼ばれる
	player->ball_.position = Vector2{ 50.f,350.f };

	// エネミー追加と初期化
	for (uint32_t i = 0u; i < 3u; ++i) {
		auto enemy = std::make_unique<Enemy>();
		enemy->ball_.position = Vector2{ 500.f, 200.f + i * 150.f };

		this->AddObject(std::move(enemy));
	}
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
		object->Update(deltaTime);
	}

	// プレイヤの一覧をオブジェクトのリストから取得して、その総数が0になったらゲーム終了とする
	// 敵の総数も同様
	if (this->GetAllObject<Player>().size() == 0u || this->GetAllObject<Enemy>().size() == 0u) {
		pSceneManager_->ChangeScene(std::make_unique<OverScene>(), 1.f);
	}
}

void MyGameScene::Draw() {

	Novice::DrawBox(0, 0, 1280, 720, 0.f, BLACK, kFillModeSolid);

	Novice::ScreenPrintf(0, 0, "GameScene : Push SPACE");
	const auto &sceneTimer = pSceneManager_->GetTimer();
	Novice::ScreenPrintf(0, 20, "Change Progress %.2f / %.2f : %3.0lf%%", sceneTimer.GetNowFlame(), sceneTimer.GetGoalFlame(), static_cast<double>(sceneTimer.GetProgress()) * 100.f);

	Novice::ScreenPrintf(0, 40, "WASD : Move / SPACE : Fire");
	Novice::ScreenPrintf(0, 60, "All enemy kill / Player Die : Change Scene");
	for (auto &object : objectList_) {
		object->Draw();
	}
}

Object *const MyGameScene::AddObject(std::unique_ptr<Object> object) {
	// ゲームシーンのポインタを渡し、初期化する。
	// 本来はObjectManagerとか作ってやるべき。
	object->pGameScene_ = this;
	object->Init();
	// データを登録して、ポインタを返す。
	objectList_.push_back(std::move(object));
	return objectList_.back().get();
}
