#pragma once

#include "HWapplication.h"

class TheGame : public HW::HWapplication
{
public:
	void OnInit();
	void OnUpdate();
	void OnRender();
	TheGame();
};
