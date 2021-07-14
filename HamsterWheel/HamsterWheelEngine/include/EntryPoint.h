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
	app->_Renderer->ReadShaderFile("res/shader/default.shader");
	app->Run();
	
	return 0;
}