#pragma once

#define GLEW_STATIC


#include "glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "HWapplication.h"

extern HW::HWapplication* HW::CreateApp();

int main()
{
	std::cout << "hello world" << std::endl;
	if (!glfwInit())
		std::cout << "Error initializing GLFW." << std::endl;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 720, "game", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	if (!glewInit() == GLEW_OK)
		std::cout << "Error initializing GLEW." << std::endl;
	std::cout << glGetString(GL_VERSION) << std::endl;
	glClearColor(0, 0, 0, 1);

	glViewport(0, 0, 1280, 720);
	

	HW::HWapplication* app = HW::CreateApplication();

	// glfw main loop
	while (true)
	{
		glClear(GL_CLEAR);

		// immediate mode for testing
		glBegin(GL_TRIANGLES);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glVertex3f(0, -0.5f, 0.5f);
		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	

	std::cin.ignore();
	return 0;
}