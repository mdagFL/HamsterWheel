#pragma once

#include "Application.h"

class TheGame : public HW::Application
{
public:
	void OnUpdate() override;
	void OnRender() override;
	TheGame(int width, int height);
};
