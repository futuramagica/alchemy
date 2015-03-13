// TheUI.cpp : main project file.

#include "stdafx.h"
#include "SimpleList.h"
#include "Scene.h"
#include "Renderer.h"
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

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
/*	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	//Triangles
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	


	static const GLfloat g_vertex_buffer_data[] = { 
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 0.0f,  1.0f, 0.0f,
	};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	*/
	SimpleList l1(-200,-275,400,100);
	l1.highlighted=false;
	
	do{
		glClearColor(0.1f, 0.5f, 0.7f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT );
		l1.Draw(&r);

		
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
	/*Scene MainScene;
	SimpleList l1(5,5,50,50);
	SimpleList l2(100,100,60,60);
	MainScene.AddElement(&l1);
	MainScene.AddElement(&l2);
	MainScene.Debug();

	int a=333;
	LinkedList<int> ll;
	ll.AddElement(&a);
	int b=*(ll.Last());
	printf("%i\n",b);*/
	system("pause");
    return 0;
}
