#pragma once
#include "SceneManager.h"
#include <Header/Entity.h>
#include <Header/CollisionManager.h>

class MyGameScene : public IScene {
public:
	MyGameScene();
	~MyGameScene();

	void OnEnter() override;
	void OnExit() override;

	void Update(float deltaTime) override;
	void Draw() override;

	/// @brief 指定した型のオブジェクトを取得する関数
	/// @tparam T オブジェクトの型
	/// @return オブジェクトのリスト
	template <typename T>
	std::list<T *> GetAllObject();

	/// @brief オブジェクトを追加
	/// @param object オブジェクト
	void AddObject(std::unique_ptr<Object> object);

private:

	std::list<std::unique_ptr<Object>> objectList_;
	CollisionManager *pCollisionManager_ = nullptr;

};

template<typename T>
inline std::list<T *> MyGameScene::GetAllObject() {
	std::list<T *> result;

	for (const auto &object : objectList_) {
		// dynamic_castを使用して、ObjectからTに変換できるか確認
		if (T *const derivedPtr = dynamic_cast<T *const>(object.get())) {
			result.push_back(derivedPtr);
		}
	}

	return result;
}