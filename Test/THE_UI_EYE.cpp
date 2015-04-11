
/*

// TheUI.cpp : main project file.

#include "windows.h"
#include "process.h"


#include "Hydrargyrum\SimpleList.h"

#include "Hydrargyrum\Scene.h"
#include "Hydrargyrum\Renderer.h"
#include "Hydrargyrum\SimpleListElement.h"
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

#include "Hydrargyrum\DummyInput.h"
#include "Hydrargyrum\MouseInput.h"


#include "EyeTribeImpl.h"
#include <iostream>
#include "Sol\HMI_Manager.h" 
#include "Hydrargyrum\EyeInput.h"

void actionEye		 (float *x, float *y);
unsigned int __stdcall drawThread(void *arg );
unsigned int __stdcall eyeThread(void *arg );

HMI_Manager* hmi;
eye_event eye;


Renderer r(1024,768);
Scene MainScene(&r,1920,1080);
SimpleList l1(-300,-200,300,400);
EyeInput ei (&MainScene);
//MouseInput di (&MainScene);

HANDLE mutex; 
//HANDLE myEvent;
HANDLE eyeHandle, drawHandle;

int main()
{
	float i_x, i_y;
	i_x=0;
	i_y=0;
	eye.x=&i_x;
	eye.y=&i_y;

	
mutex = CreateMutex(0, 0, 0);	
//	myEvent = CreateEvent(0, 0, 0, 0);

	
	drawHandle =(HANDLE)_beginthreadex(0,0, drawThread, (void*)0, 0, 0);
	
	
	


//	 WaitForSingleObject(eyeHandle, INFINITE); 
//	 WaitForSingleObject(drawHandle, INFINITE);


	system("pause");

	CloseHandle(mutex);
   // CloseHandle(eyeHandle); 
	//CloseHandle(drawHandle);

	return 0;
}

unsigned int __stdcall eyeThread(void * args){
	hmi = new HMI_Manager();

	EyeTribeImpl eyetr(actionEye);
	
	

		ei.setHmiManager(hmi);
	//	SetEvent(myEvent);

	while (true)
   {
   //   Sleep(1);
      //here you also can write the output function e.g. cout <<  or printf, of course, under the precondition of predefined coordinates variable in your class
     // printf( "\n-----------------------------------------------------\n" );
   }

	return 0;
}



unsigned int __stdcall drawThread(void *arg ){



	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
	//	return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow( 1920,1080, "A basic window", glfwGetPrimaryMonitor(), NULL);
	
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
	//	return -1;
	}
	glfwMakeContextCurrent(window);
	glewExperimental = true;
	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
	//	return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	
	
	
	l1.highlighted=false;
	l1.AddElement(new SimpleListElement(&l1,60,200));
	l1.AddElement(new SimpleListElement(&l1,60,100));
	l1.AddElement(new SimpleListElement(&l1,60,100));
	l1.AddElement(new SimpleListElement(&l1,60,100));
	MainScene.AddElement(&l1);
	MouseInput di (&MainScene);
	
	//printf("%i\n",MainScene.ElementCount());
	glClearColor(0.1f, 0.5f, 0.7f, 0.0f);

eyeHandle = (HANDLE)_beginthreadex(0,0, eyeThread,(void*)0, 0, 0);
do{
		
	glClear(GL_COLOR_BUFFER_BIT );
		//l1.Draw(&r);
//	WaitForSingleObject(myEvent, INFINITE);
		
	//ei.Listen(window);
	
	//di.Listen(window);
		MainScene.Draw();
		 
		glfwSwapBuffers(window);
		glfwPollEvents();


	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	return 0;
}



void actionEye (float *x, float *y){
	
	
	
	//WaitForSingleObject(mutex, INFINITE);

//	std::ofstream log("logfile1.txt", std::ios_base::app | std::ios_base::out);

if ((0<*x<1920)&&(0<*y<1080))  {
//log<<"X IS = "<<*x<<" Y IS = "<<*y<< std::endl;
	//if (abs( *x - *eye.x )>5)
		//	eye.x=x;
	//if (abs( *y - *eye.y )>5)
	//	eye.y=y;

		MainScene.MouseOver((int)*x, (int)*y);
		glfwSetCursorPos(window,(double)*x, (double) *y);
		
//		hmi->update_eye_struct(eye);
		

}
//	ReleaseMutex(mutex);
};

*/