#pragma once
#define GLEW_STATIC
#include "glew.h"
#include "GLFW/glfw3.h"
#include <string>
#include "Renderer.h"
#include <vector>


namespace HW
{	
	
	class Application
	{
	public:
		
		Renderer* _Renderer;
		void Render();
		virtual void OnRender();
		void Update();
		virtual void OnUpdate();
		void Init();
		void Run();
		void ResizeWindow(int width, int height);
		void CreateGameObject(const GameObject &objPrefab);
		void CreateGameObject(const RenderObject& objPrefab);
>>>>>>> Stashed changes
		
		Application(int width, int height);
		~Application();
	private:
		GLFWwindow* _window;
		int _width;
		int _height;
		float _aspectRatio;

		std::vector<GameObject*> _gameObjects;
	};
	
	Application* CreateApplication();
}
