#include "Hydrargyrum\UserInput.h"
#include "GLFW\glfw3.h"

#include "glew-1.12.0\include\GL\glew.h"
#include "glew-1.12.0\include\GL\wglew.h"

#include "Sol\Sol.h" 

#include <ios>
#include <fstream>

class EyeInput: public UserInput
{
public:
	EyeInput(Scene* s):UserInput( s){
	
	};
	
	
	void Listen(GLFWwindow* window){
		
		int xpos, ypos; 
		xpos = (int)*hmi->get_eye_event().x;
		ypos = (int)*hmi->get_eye_event().y;
		if ((0<xpos<1920)&&(0<ypos<1080)){
		   

			 std::ofstream log("logfile.txt", std::ios_base::app | std::ios_base::out);

    log << "AFTER >>>>>>X IS = " << xpos<<" Y IS = " << ypos << std::endl;
		//	std::cout << "AFTER >>>>>>X IS = " << (int)*hmi->get_eye_event().x<<" Y IS = " << (int)*hmi->get_eye_event().y << std::endl;
		//	scene->MouseOver(xpos, ypos);
		//	glfwSetCursorPos(window,(double)*hmi->get_eye_event().x, (double) *hmi->get_eye_event().y);
		}
		
	};

	void setHmiManager (Sol* man){

		hmi = man;
};

private: 
	Sol* hmi;

};