#include "Entity.h"
#include <Novice.h>
#include "Header/InputManager.h"
#include "Header/Utils/Math.h"
#include "Header/Scene/MyGameScene.h"

void Object::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse(static_cast<int32_t>(ball_.position.x), static_cast<int32_t>(ball_.position.y), static_cast<int32_t>(ball_.radius), static_cast<int32_t>(ball_.radius), 0.f, color_, kFillModeSolid);
	}
}

void Player::Init() {
	collisionAttribute_ = static_cast<uint32_t>(CollisionType::kPlayer);
	collisionMask_ = ~static_cast<uint32_t>(CollisionType::kPlayer);

	ball_.radius = 50.f;
	color_ = 0x0000FFFF;
}

void Player::Update([[maybe_unused]] const float deltaTime) {
	static auto *const inputManager = InputManager::GetInstance();
	Vector2 inputVec{};
	// 入力方向の取得
	if (inputManager->IsPress(DIK_W)) {
		--inputVec.y;
	}
	if (inputManager->IsPress(DIK_S)) {
		++inputVec.y;
	}

	if (inputManager->IsPress(DIK_A)) {
		--inputVec.x;
	}
	if (inputManager->IsPress(DIK_D)) {
		++inputVec.x;
	}
	// 正規化
	inputVec = Normalize(inputVec) * kMoveSpeed_;

	ball_.position += inputVec;

	if (inputManager->IsTrigger(DIK_SPACE)) {
		auto *const bullet = dynamic_cast<Bullet *const>(pGameScene_->AddObject(std::make_unique<Bullet>()));
		if (bullet) {
			bullet->ball_.position = this->ball_.position;
			bullet->velocity_ = Vector2{ 5.f,0.f };
			bullet->lifeLimit_ = 5.f;
		}
	}

}

void Player::OnCollision([[maybe_unused]] Object *const other) {
	// 死亡させる
	isAlive_ = false;
}

void Enemy::Init() {
	collisionAttribute_ = static_cast<uint32_t>(CollisionType::kEnemy);
	collisionMask_ = ~static_cast<uint32_t>(CollisionType::kEnemy);
	ball_.radius = 20.f;
	color_ = 0x00FF00FF;
}

void Enemy::Update([[maybe_unused]] const float deltaTime) {
}

void Enemy::OnCollision([[maybe_unused]] Object *const other) {
	// 死亡させる
	isAlive_ = false;
}

void Bullet::Init() {
	collisionAttribute_ = static_cast<uint32_t>(CollisionType::kPlayer);
	collisionMask_ = ~static_cast<uint32_t>(CollisionType::kPlayer);
	ball_.radius = 10.f;
	color_ = 0xFF0000FF;
}

void Bullet::Update([[maybe_unused]] const float deltaTime) {
	// もし寿命が0を下回ったら死亡
	if (lifeLimit_ <= 0.f) {
		isAlive_ = false;
	}
	// 寿命を削る
	lifeLimit_ -= deltaTime;

	// 移動
	ball_.position += velocity_;
}

void Bullet::OnCollision([[maybe_unused]] Object *const other) {
	// 死亡させる
	isAlive_ = false;
}
