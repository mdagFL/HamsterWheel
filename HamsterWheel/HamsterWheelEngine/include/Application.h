#pragma once
#define GLEW_STATIC


#include "glew.h"
#include "GLFW/glfw3.h"
#include <string>


namespace HW
{	
	
	class Application
	{
	public:
		void Render();
		virtual void OnRender() const;
		void Update();
		virtual void OnUpdate() const;
		void Init();
		void Run();
		
		
		Application(int width, int height);
	private:
		GLFWwindow* _window;
		int _width;
		int _height;
		float _aspectRatio;
	};
	
	Application* CreateApplication();
}
