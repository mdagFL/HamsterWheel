
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
		
		/// <summary>
		// TESTING
		/// </summary>
		ShaderProgram* defaultShader = new ShaderProgram();
		Texture* testTexture = new Texture("D:\\Randy's_Disk\\Pictures_D\\ahamam2.png");
		Material* testMaterial = new Material(defaultShader, testTexture);
		RenderObject* o = new RenderObject(testMaterial);
		this->AddGameObject(o);

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

			_Renderer->Render(_gameObjects, _window);

			//OnRender();
			//OnUpdate();

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
