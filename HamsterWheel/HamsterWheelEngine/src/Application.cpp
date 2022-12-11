
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
			_Renderer->Render(_gameObjects, _window);
			OnRender();
			glfwPollEvents();
		}
	}

	void HW::Application::AddGameObject(GameObject* object)
	{
		_gameObjects.push_back(object);
	}

	void HW::Application::OnUpdate()
	{

	}

	HW::Application::~Application()
	{
		delete _Renderer;
	}
}
