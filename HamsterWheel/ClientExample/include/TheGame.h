#pragma once
#include "Application.h"
#include "GameObject.h"

class TheGame : public HW::Application
{
public:
	void OnUpdate(double deltaTime) override;
	void OnRender() override;
	void OnInit() override;
	TheGame(int width, int height);
private:
	HW::GameObject* player;
};
