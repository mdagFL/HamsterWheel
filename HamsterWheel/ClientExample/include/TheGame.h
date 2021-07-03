#pragma once

#include "HWapplication.h"

class TheGame : public HW::HWapplication
{
public:
	void OnInit() override;
	void OnUpdate() override;
	void OnRender() override;
	TheGame();
};
