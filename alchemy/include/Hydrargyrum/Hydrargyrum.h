// this is entry point in all UI related routine
// single object 

#ifndef HYDRARGYRUM_H
#define HYDRARGYRUM_H
#include "Compositor.h";

#include "glew-1.12.0\include\GL\glew.h"
#include "glew-1.12.0\include\GL\wglew.h"
#include "GLFW\glfw3.h"
#include <glm-0.9.4.0\glm\glm.hpp>
#include <glm-0.9.4.0\glm\gtc\matrix_transform.hpp>



class Hydrargyrum{

	public:	
		static Hydrargyrum* getInstance();
		int initGraphics();
		int initBuffers();
		void mainUILoop();
		void clear();


		// setters and getters 
		void setCompositor(Compositor* c );
		GLFWwindow* getWindow();

	private: 
		Hydrargyrum();
		~Hydrargyrum();

		Compositor* compositor;

		static Hydrargyrum* hydrargyrum;
		
		GLFWwindow* window;

};

#endif