#pragma once

#include "Application.h"

class TheGame : public HW::Application
{
public:
	void OnUpdate() const override;
	void OnRender() const override;
	TheGame(int width, int height);
};
