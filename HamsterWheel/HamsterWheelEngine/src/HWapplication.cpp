
#include "HWapplication.h"
#include <iostream>

namespace HW
{
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

	void HW::HWapplication::OnInit()
	{
		std::cout << "base init" << std::endl;
	}

	void HW::HWapplication::OnRender()
	{

	}

	void HW::HWapplication::OnUpdate()
	{

	}
}
