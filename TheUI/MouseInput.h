#include "UserInput.h"
#include "GLFW\glfw3.h"

#include "glew-1.12.0\include\GL\glew.h"
#include "glew-1.12.0\include\GL\wglew.h"
class MouseInput: public UserInput
{
public:
	MouseInput(Scene* s):UserInput( s)
	{
	}
	void Listen(GLFWwindow* window)
	{
		double xpos, ypos;
		glfwGetCursorPos(window,&xpos, &ypos);
		scene->MouseOver(xpos,ypos);
	}
};