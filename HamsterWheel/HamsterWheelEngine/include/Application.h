#pragma once
#define GLEW_STATIC
#include "glew.h"
#include "GLFW/glfw3.h"
#include "Renderer.h"
#include "ObjectManager.h"
#include "Camera.h"

#include <string>
#include <vector>


namespace HW
{	
	
	class Application
	{
	public:
		// Public state, to be used as extensions of public interface
		Renderer* _Renderer;
		ObjectManager _objectManager;
		Camera _camera;

		// Public interface
		void Render();
		virtual void OnRender();
		void Update();
		virtual void OnUpdate();
		void Init();
		void Run();
		void ResizeWindow(int width, int height);	
		Application(int width, int height);
		~Application();

	private:
		// Private state
		GLFWwindow* _window;
		int _width;
		int _height;
		float _aspectRatio;

	};
	
	Application* CreateApplication();
}
