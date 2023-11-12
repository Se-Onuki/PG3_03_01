#pragma once
#include <list>
struct Object;

class CollisionManager {
	std::list<Object*> colliderList_;
	CollisionManager() {}
	CollisionManager(const CollisionManager&) = delete;
	CollisionManager operator=(const CollisionManager&) = delete;

public:
	static CollisionManager* GetInstance() {
		static CollisionManager collisionManager;
		return &collisionManager;
	}
	void clear() { colliderList_.clear(); }
	void push_back(Object* collider) { colliderList_.push_back(collider); }

	void ChackAllCollision();
	void CheckCollisionPair(Object* A, Object* B);
};