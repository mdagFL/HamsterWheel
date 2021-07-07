
#include "Application.h"
#include <iostream>

namespace HW
{
	void HW::Application::Render()
	{
		OnRender();
	}

	void HW::Application::Update()
	{
		OnUpdate();
	}

	void HW::Application::Init()
	{
		std::cout << "hello world" << std::endl;
		if (!glfwInit())
			std::cout << "Error initializing GLFW." << std::endl;

		_window = glfwCreateWindow(_width, _height, "game", nullptr, nullptr);
		glfwMakeContextCurrent(_window);

		if (!glewInit() == GLEW_OK)
			std::cout << "Error initializing GLEW." << std::endl;
		std::cout << glGetString(GL_VERSION) << std::endl;
		glClearColor(0, 0, 0, 1);

		glViewport(0, 0, _width, _height);

	}

	HW::Application::Application(int width, int height)
	{
		_width = width;
		_height = height;
		Init();
	}

	void HW::Application::OnRender() const
	{
		std::cout << "base render" << std::endl;
	}

	void HW::Application::Run()
	{
		while (!glfwWindowShouldClose(_window))
		{
			glClear(GL_CLEAR);

			// immediate mode for testing
			glBegin(GL_TRIANGLES);
			glVertex3f(-0.5f, 0.5f, 0.5f);
			glVertex3f(0.5f, 0.7f, 0.5f);
			glVertex3f(-0.8, -0.5f, 0.5f);
			glEnd();

			glfwSwapBuffers(_window);

			OnRender();

			glfwPollEvents();
		}
	}

	

	void HW::Application::OnUpdate() const
	{

	}
}
