#include <stdio.h>
#include "SimpleList.h"
#include "stdafx.h"


#include "glew-1.12.0\include\GL\glew.h"
#include "glew-1.12.0\include\GL\wglew.h"

// Include GLFW
#include "GLFW\glfw3.h"

// Include GLM
#include "glm-0.9.4.0\glm\glm.hpp"
using namespace glm;
SimpleList::SimpleList(int x_, int y_ , int width_, int height_)
 {
	 x=x_;
	 y=y_;
	 height=height_;
	 width=width_;
 }

void SimpleList::OnEvent(int code)
{

	highlighted=!highlighted;
}

void SimpleList::Display()
{
	printf("%i,%i",x,y);
}

void SimpleList::Draw(Renderer* r)
{
	printf("Draw()\n");

	//printf("%i %i %i %i\n", left,right,top,bottom);
	RectangleInfo ri;
	ri.x=highlighted?x-width*0.15:x;
	ri.y=highlighted?y-height*0.15:y;
	ri.width=highlighted?width*1.3:width;
	ri.height=highlighted?height*1.3:height;
	ri.thickness=highlighted? 3:1;
	r->DrawRectangle(&ri);



}


