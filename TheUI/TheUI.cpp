// TheUI.cpp : main project file.

#include "stdafx.h"
#include "SimpleList.h"

#include "Scene.h"
#include "Renderer.h"
#include "SimpleListElement.h"
using namespace System;
// Include standard headers
#include <stdio.h>
#include <stdlib.h>
// Include GLEW
#include "glew-1.12.0\include\GL\glew.h"
#include "glew-1.12.0\include\GL\wglew.h"

// Include GLFW
#include "GLFW\glfw3.h"
GLFWwindow* window;
// Include GLM
#include "glm-0.9.4.0\glm\glm.hpp"
using namespace glm;

#include "DummyInput.h"
#include "MouseInput.h"
int main(array<System::String ^> ^args)
{

	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow( 1024, 768, "A basic window", NULL, NULL);
	Renderer r(1024,768);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glewExperimental = true;
	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	Scene MainScene(&r,1024,768);
	SimpleList l1(-300,-200,300,400);
	l1.highlighted=false;
	l1.AddElement(new SimpleListElement(&l1,60,200));
	l1.AddElement(new SimpleListElement(&l1,60,100));
	l1.AddElement(new SimpleListElement(&l1,60,100));
	l1.AddElement(new SimpleListElement(&l1,60,100));
	MainScene.AddElement(&l1);
	MouseInput di (&MainScene);
	printf("%i\n",MainScene.ElementCount());
	glClearColor(0.1f, 0.5f, 0.7f, 0.0f);
	do{
		
	glClear(GL_COLOR_BUFFER_BIT );
	//	l1.Draw(&r);
		di.Listen(window);
		MainScene.Draw();
		
		glfwSwapBuffers(window);
		glfwPollEvents();
		if (glfwGetKey(window,GLFW_KEY_SPACE)==GLFW_PRESS)
		{
			printf("space\n");
			EventInterface* e=&l1;
			e->OnEvent(0);
		}
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	system("pause");
    return 0;
}
