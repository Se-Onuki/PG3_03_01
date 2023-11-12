#pragma once
#include "SceneManager.h"

class OverScene : public IScene {
public:
	OverScene();
	~OverScene();

	void OnEnter() override;
	void OnExit() override;

	void Update(float deltaTime) override;
	void Draw() override;
public:

private:
};