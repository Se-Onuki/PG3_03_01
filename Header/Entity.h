#pragma once
#include <Vector2.h>
#include <cstdint>

class MyGameScene;

struct Ball {
	Vector2 position;
	float radius;

};

enum class CollisionType : uint32_t {
	kPlayer = 0b01,	// プレイヤ
	kEnemy = 0b10,	// エネミー

};

struct Object {
	virtual ~Object() = default;

	Ball ball_;
	// テクスチャ
	uint32_t color_ = 0xFFFFFFFF;
	bool isAlive_ = true;

	virtual void Init() = 0;
	virtual void Update(const float deltaTime) = 0;
	virtual void Draw();

	virtual void OnCollision(Object *const other) = 0;

	MyGameScene *pGameScene_ = nullptr;


	// 衝突属性(自分)
	uint32_t collisionAttribute_ = 0xFFFFFFFF;
	// 衝突マスク(相手)
	uint32_t collisionMask_ = 0xFFFFFFFF;
private:

};

struct Player : public Object {

	const float kMoveSpeed_ = 10.f;

	void Init() override;
	void Update(const float deltaTime) override;

	void OnCollision(Object *const other) override;
};

struct Enemy :public Object {

	void Init() override;
	void Update(const float deltaTime) override;

	void OnCollision(Object *const other) override;
};

struct Bullet :public Object {

	Vector2 velocity_;
	float lifeLimit_;

	void Init() override;
	void Update(const float deltaTime) override;

	void OnCollision(Object *const other) override;
};