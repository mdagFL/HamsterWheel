
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
		
		// TESTING //
		RenderObject* o = new RenderObject();
		_gameObjects.push_back(o);

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

			_Renderer->Render(_gameObjects, _window);

			OnRender();

			glfwPollEvents();
		}
	}

	void HW::Application::AddGameObject(GameObject object)
	{
		
	}

	void HW::Application::OnUpdate() const
	{

	}

	HW::Application::~Application()
	{
		delete _Renderer;
	}
}
