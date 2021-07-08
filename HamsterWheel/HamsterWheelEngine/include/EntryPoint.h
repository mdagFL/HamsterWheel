#pragma once


#include <iostream>
#include "Application.h"
#include "GLinterface.h"

extern HW::Application* HW::CreateApplication();

int main()
{

	HW::Application* app = HW::CreateApplication();
	HW::ReadShaderFile("res/shader/default.shader");
	app->Run();
	
	return 0;
}