#pragma once
#include "SceneManager.h"
class MyGameScene : public IScene {
public:
	MyGameScene();
	~MyGameScene();

	void OnEnter() override;
	void OnExit() override;

	void Update(float deltaTime) override;
	void Draw() override;

private:

};