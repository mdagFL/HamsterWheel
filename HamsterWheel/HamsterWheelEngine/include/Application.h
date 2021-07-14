#pragma once
#define GLEW_STATIC


#include "glew.h"
#include "GLFW/glfw3.h"
#include <string>
#include "Renderer.h"


namespace HW
{	
	
	class Application
	{
	public:
		
		Renderer* _Renderer;
		void Render();
		virtual void OnRender() const;
		void Update();
		virtual void OnUpdate() const;
		void Init();
		void Run();
		void ResizeWindow(int width, int height);
		
		Application(int width, int height);
		~Application();
	private:
		GLFWwindow* _window;
		int _width;
		int _height;
		float _aspectRatio;
	};
	
	Application* CreateApplication();
}
