#pragma once

#include <iostream>
#include "glew.h"

#define GLEW_STATIC
#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
#include "Application.h"
#include "Renderer.h"
#include "Mat4.h"

extern HW::Application* HW::CreateApplication();

int main()
{
	HW::Application* app = HW::CreateApplication();

	app->Run();

	//HW::Vector3 vec3(2, 3, 5);
	HW::Mat4 matrix1 = HW::Mat4(
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1);
	HW::Mat4 matrix2 = HW::Mat4::Identity();
	HW::Mat4 matrix3 = HW::Mat4(
		5, 2, 6, 1,
		0, 6, 2, 0,
		3, 8, 1, 4,
		1, 8, 5, 6
	);
	HW::Mat4 matrix4 = HW::Mat4(
		7, 5, 8, 0,
		1, 8, 2, 6,
		9, 4, 3, 8,
		5, 3, 7, 9
	);
	
	matrix2 = matrix2 * 2;
	matrix2.Print();
	matrix1 = matrix1 * matrix2;
	matrix1.Print();

	HW::Mat4 matrix5 = matrix3 * matrix4;
	matrix5.Print();

	HW::Mat4 matrix6{ matrix5.Transpose() };
	matrix6.Print();
	float j[16];

	std::cout << sizeof(matrix1) << "\n";

	return 0;
}