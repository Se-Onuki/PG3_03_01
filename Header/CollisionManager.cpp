#include "CollisionManager.h"
#include "Header/Entity.h"
#include "Header/Utils/Math.h"

void CollisionManager::ChackAllCollision() {

	Object *colliderA, *colliderB;
	std::list<Object*>::iterator itrA = colliderList_.begin();
	for (; itrA != colliderList_.end(); ++itrA) {
		colliderA = *itrA;
		std::list<Object*>::iterator itrB = itrA;
		itrB++;
		for (; itrB != colliderList_.end(); ++itrB) {
			colliderB = *itrB;
			CheckCollisionPair(colliderA, colliderB);
		}
	}
}

void CollisionManager::CheckCollisionPair(Object* A, Object* B) {
	auto test = (A->collisionAttribute_ & B->collisionMask_);
	test = test;
	if ((A->collisionAttribute_ & B->collisionMask_) == 0u ||
	    (B->collisionAttribute_ & A->collisionMask_) == 0u)
		return;
	if (Length(A->ball_.position - B->ball_.position) <= A->ball_.radius + B->ball_.radius) {
		A->OnCollision(B);
		B->OnCollision(A);
	}
}
