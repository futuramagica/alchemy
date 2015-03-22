#include "stdafx.h"
#include "Renderer.h"

#include "glew-1.12.0\include\GL\glew.h"
#include "glew-1.12.0\include\GL\wglew.h"

// Include GLFW
#include "GLFW\glfw3.h"

// Include GLM
#include "glm-0.9.4.0\glm\glm.hpp"
using namespace glm;
#include <stdio.h>

void Renderer::DrawRectangle(RectangleInfo* info)
{
	//client states enabled x3
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	GLfloat thickness=info->thickness;
	GLfloat left=(double)info->y/(double)(height/2);
	GLfloat right=(double)(info->y+info->height)/(height/2);
	GLfloat top=(double)info->x/(width/2);
	GLfloat bottom=(double)(info->x+info->width)/(width/2);
	//printf("%f\t%f\t%f\t%f",left,right,top,bottom);

	//TODO: figure out how to PROPERLY work with coordinate systems

	GLfloat g_vertex_buffer_data[] = { 
		top, -left,0.0f,
		 top, -right, 0.0f,
		 bottom,  -right,0.0f, 
		 bottom, -left,0.0f
	};
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE,0,(void*)0);
	glLineWidth(thickness);



	glDrawArrays(GL_LINE_LOOP, 0, 4);

	glDisableVertexAttribArray(0);
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	
	//client states disabled x3
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisable(GL_TEXTURE_2D);
}
Renderer::Renderer(int w, int h)
{
	width=w;
	height=h;
}
/*bool Renderer::WithinRectangle(RectangleInfo* ri, int x, int y)
{
	printf("Address: %p\n",ri);
	printf("Call to withinrectangle for x=%i,y=%i, rectangle defined by x=%i,y=%i,width=%i,height=%i,thickness=%f\n",x,y,ri->x,ri->y,ri->width,ri->height,ri->thickness);
	//system("pause");
	return (ri->x<=x)&&(x<=ri->x+ri->width)&&(y>=ri->y)&&(y<=ri->y+ri->height);
}*/