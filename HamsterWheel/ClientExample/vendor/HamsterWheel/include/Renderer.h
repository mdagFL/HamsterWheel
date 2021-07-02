#include "glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

#define GLEW_STATIC

class Renderer
{
public:
	static Renderer instance;
	GLFWwindow* window;
	
	~Renderer();
private:
	Renderer();

};