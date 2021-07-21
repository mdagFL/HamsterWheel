#pragma once

#include "glew.h"
#define GLEW_STATIC
#include <iostream>
#include "Application.h"
#include "Renderer.h"
#include "Mat4.h"

extern HW::Application* HW::CreateApplication();

int main()
{
    
	HW::Application* app = HW::CreateApplication();

	//app->Run();
	
	//HW::Vector3 vec3(2, 3, 5);
	HW::Mat4 matrix1 = HW::Mat4(
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1);
	HW::Mat4 matrix2 = HW::Mat4::Identity();
	
	matrix2 = matrix2 * 2;
	matrix2.Print();
	matrix1 = matrix1 * matrix2;
	matrix1.Print();

	float j[16];

	std::cout << sizeof(matrix1) << "\n";

	return 0;
}