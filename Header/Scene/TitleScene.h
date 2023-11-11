#pragma once
#include "SceneManager.h"

class TitleScene : public IScene {
public:
	TitleScene();
	~TitleScene();

	void OnEnter() override;
	void OnExit() override;

	void Update(float deltaTime) override;
	void Draw() override;
public:

private:
};