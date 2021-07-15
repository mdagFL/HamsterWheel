#pragma once

#include "glew.h"
#define GLEW_STATIC
#include <iostream>
#include "Application.h"
#include "Renderer.h"

extern HW::Application* HW::CreateApplication();

int main()
{
    
	HW::Application* app = HW::CreateApplication();

	app->Run();
	
	//HW::Vector3 vec3(2, 3, 5);


	return 0;
}