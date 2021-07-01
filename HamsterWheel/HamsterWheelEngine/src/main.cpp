#define GLEW_STATIC

#include "glew.h"
#include "GLFW/glfw3.h"
#include <iostream>


int main()
{
	
	std::cout << "hello world" << std::endl;
	if (!glfwInit())
		std::cout << "Error initializing GLFW." << std::endl;
	
	GLFWwindow* window;
	window = glfwCreateWindow(1280, 720, "game", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	if (!glewInit() == GLEW_OK)
		std::cout << "Error initializing GLEW." << std::endl;
	std::cout << glGetString(GL_VERSION) << std::endl;
	std::cin.ignore();
	
}