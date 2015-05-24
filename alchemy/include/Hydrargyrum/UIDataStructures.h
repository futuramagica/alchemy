#ifndef UIDATASTRUCTURES_H
#define UIDATASTRUCTURES_H

#include <vector>


#include "glew-1.12.0\include\GL\glew.h"
#include "glew-1.12.0\include\GL\wglew.h"
#include "GLFW\glfw3.h"
#include <glm-0.9.4.0\glm\glm.hpp>
#include <glm-0.9.4.0\glm\gtc\matrix_transform.hpp>

enum ui_orientation {left, right, top, bottom, center};


struct ui_elem_pos {
	// top left corner 
	double x;
	double y;
};

struct ui_element {
	double border;
	int texture;
	int color;
	int mode;//	(blink = 1, normal = 0– when element to be moved)
	ui_elem_pos position; 
	ui_orientation orientation;
	
	std::vector<glm::vec3> vertices;
	std::vector<unsigned short> indices;
	std::vector<glm::vec3> indexed_vertices;

	// OPENGL Shader ID
	GLuint shaderID;

	//OPENGL model matrix 
	GLuint MatrixID;


	// OPENGL buffers references 
	GLuint vertexbuffer;
	GLuint elementbuffer;
	
	
	// OPENGL our manipulation matrices 
	glm::mat4 ModelMatrix;


};

#endif