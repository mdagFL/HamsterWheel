
#include "HWapplication.h"

void HW::HWapplication::Render()
{
	OnRender();
}

void HW::HWapplication::Update()
{
	OnUpdate();
}

void HW::HWapplication::Init()
{
	OnInit();
}

HW::HWapplication::HWapplication()
{
	Init();
}