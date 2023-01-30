#include "Renderer.h"

#include <iostream>

using namespace HW;

void HW::glErrorCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	switch (severity)
	{
	case GL_DEBUG_SEVERITY_NOTIFICATION:
		std::cout << "[GL NOTIFICATION]: ";
		break;
	case GL_DEBUG_SEVERITY_LOW:
		std::cout << "[GL LOW-SEVERITY ERROR]: ";
		break;
	case GL_DEBUG_SEVERITY_MEDIUM:
		std::cout << "[GL MEDIUM-SEVERITY ERROR]: ";
		break;
	case GL_DEBUG_SEVERITY_HIGH:
		std::cout << "[GL HIGH-SEVERITY ERROR]: ";
		break;
	default:
		std::cout << "[GL ERROR]: ";
		break;
	}
	std::cout << message << "\n";
}



Renderer::Renderer()
{
	Init(1280, 720);
}

Renderer::Renderer(int width, int height)
{
	Init(width, height);
}

void Renderer::Render(const std::vector<GameObject*> &objects, GLFWwindow* window)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	for (int i = 0; i < objects.size(); i++)
		 objects[i]->Render();

	glfwSwapBuffers(window);

}

Renderer::~Renderer()
{
	
}

void Renderer::Init(int width, int height)
{
	if (!glewInit() == GLEW_OK)
		std::cout << "Error initializing GLEW." << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;

	// GL error callback
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(glErrorCallback, nullptr);
	GLuint unusedIds = 0;
	glDebugMessageControl(GL_DONT_CARE,
		GL_DONT_CARE,
		GL_DONT_CARE,
		0,
		&unusedIds,
		true);

	glClearColor(0, 0, 0, 1);
	glViewport(0, 0, width, height);
	
	// create 1 VAO to be used by all render objects (?)
	// this is certainly not right
	
	// glGenVertexArrays(1, &_vaoId);
	// glBindVertexArray(_vaoId);

	// enable core profile?

	// other glEnables?

}

