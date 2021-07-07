#pragma once


#include <iostream>
#include "Application.h"

extern HW::Application* HW::CreateApplication();

int main()
{

	HW::Application* app = HW::CreateApplication();
	app->Run();

	return 0;
}