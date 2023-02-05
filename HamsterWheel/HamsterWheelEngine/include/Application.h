#pragma once
#define GLEW_STATIC
#include "glew.h"
#include "GLFW/glfw3.h"
#include "Renderer.h"
#include "ObjectManager.h"
#include "Camera.h"

#include <string>
#include <vector>
#include <chrono>


namespace HW
{	
	
	class Application
	{
	public:
		// Public state
		Renderer* _Renderer;
		ObjectManager _objectManager;

		// Public interface
		void Run();
		Application(int width, int height);
		~Application();

	protected:
		// Extension interface
		void Render();
		virtual void OnRender();
		void Update(double deltaTime);
		virtual void OnUpdate(double deltaTime);
		void Init();
		virtual void OnInit() {}
		void ResizeWindow(int width, int height);		

		GLFWwindow* _window;
		int _width;
		int _height;
		float _aspectRatio;
		std::chrono::steady_clock::time_point _lastUpdate;

	private:
		// Private state

	};
	
	Application* CreateApplication();
}
