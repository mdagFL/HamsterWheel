
#include "Application.h"
#include <iostream>

namespace HW
{
	void HW::Application::Render()
	{
		OnRender();
	}

	void HW::Application::Update(double deltaTime)
	{
		_Renderer->_camera.Update(0);
		for (int i = 0; i < _objectManager._gameObjects.size(); i++)
		{
			_objectManager._gameObjects[i]->Update();
		}
		OnUpdate( deltaTime );
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
		OnInit();
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
		using namespace std::chrono;
		Init();
		_lastUpdate = steady_clock::now();
		while (!glfwWindowShouldClose(_window))
		{
			// update delta time
			steady_clock::duration deltaTimeDuration = steady_clock::now() - _lastUpdate;
			_lastUpdate = std::chrono::steady_clock::now();
			double deltaTime = deltaTimeDuration.count() * static_cast<double>(steady_clock::period::num) / steady_clock::period::den;

			Update(deltaTime);
			_Renderer->Render(_objectManager._gameObjects, _window);
			OnRender();
			glfwPollEvents();
		}
	}

	void HW::Application::OnUpdate(double delta_time)
	{
		
	}

	HW::Application::~Application()
	{
		delete _Renderer;
	}
}
