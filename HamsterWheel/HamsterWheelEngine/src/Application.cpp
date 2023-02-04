
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
		if (_window)
		{
			glfwMakeContextCurrent(_window);
		}
		else
		{
			printf("ERROR: Failed to create GLFW window\n");
		}

		glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GL_TRUE);
		_Renderer = new Renderer(_width, _height);
	}

	HW::Application::Application(int width, int height)
	{
		_width = width;
		_height = height;
	}

	void HW::Application::OnRender()
	{
		std::cout << "base render" << std::endl;
	}

	void HW::Application::Run()
	{
		Init();
		while (!glfwWindowShouldClose(_window))
		{
			OnUpdate();
			_Renderer->Render(_objectManager._gameObjects, _window);
			OnRender();
			glfwPollEvents();
		}
	}

	void HW::Application::OnUpdate()
	{
		_Renderer->_camera.Update(0);
		for (int i = 0; i < _objectManager._gameObjects.size(); i++)
		{
			_objectManager._gameObjects[i]->Update();
		}
	}

	HW::Application::~Application()
	{
		delete _Renderer;
	}
}
