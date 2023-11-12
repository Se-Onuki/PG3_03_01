#include "Entity.h"
#include <Novice.h>
#include "Header/InputManager.h"
#include "Header/Utils/Math.h"

void Object::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse(static_cast<int32_t>(ball_.position.x), static_cast<int32_t>(ball_.position.y), static_cast<int32_t>(ball_.radius), static_cast<int32_t>(ball_.radius), 0.f, color_, kFillModeSolid);
	}
}

void Player::Init() {
	collisionAttribute_ = static_cast<uint32_t>(CollisionType::kPlayer);
	collisionMask_ = ~static_cast<uint32_t>(CollisionType::kPlayer);

	ball_.radius = 50.f;
}

void Player::Update() {
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

}

void Player::OnCollision([[maybe_unused]] Object *const other) {
}

void Enemy::Init() {
	collisionAttribute_ = static_cast<uint32_t>(CollisionType::kEnemy);
	collisionMask_ = ~static_cast<uint32_t>(CollisionType::kEnemy);
}

void Enemy::Update() {
}

void Enemy::OnCollision([[maybe_unused]] Object *const other) {
}

void Bullet::Init() {
	collisionAttribute_ = static_cast<uint32_t>(CollisionType::kPlayer);
	collisionMask_ = ~static_cast<uint32_t>(CollisionType::kPlayer);
}

void Bullet::Update() {
}

void Bullet::OnCollision([[maybe_unused]] Object *const other) {

}
