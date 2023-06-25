#pragma once
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <string>
#include <vector>
#include "RenderObject.h"
#include "Camera.h"

namespace HW
{
	void glErrorCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
	
	class Renderer
	{
	public:		
		
		HW::Camera _camera;
		void Init(int width, int height);
		void Render(const std::vector<GameObject*> &objects, GLFWwindow* window);
		Renderer();
		Renderer(int width, int height);
		~Renderer();
		
	private:
		


	};
}
