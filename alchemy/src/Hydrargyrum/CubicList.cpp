#include "Hydrargyrum\CubicList.h"



CubicList::CubicList(){
	CubicList::initModelMatrix();
	CubicList::initFocusShape();
};

CubicList::~CubicList(){

};




void CubicList::draw(glm::mat4 projectionMatrix, glm::mat4 viewMatrix){


	glUseProgram(getStructure().shaderID);

	
		

		glm::mat4 MVP = projectionMatrix * viewMatrix * my_structure.modelMatrix ;

		
		glUniformMatrix4fv(my_structure.MatrixID, 1, GL_FALSE, &MVP[0][0]);
		glUniformMatrix4fv(my_structure.ModelMatrixID, 1, GL_FALSE, &my_structure.modelMatrix[0][0]);
		glUniformMatrix4fv(my_structure.ViewMatrixID, 1, GL_FALSE, &viewMatrix[0][0]);


		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, getStructure().vertexbuffer);

		glVertexAttribPointer(
			0,                  // attribute
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, getStructure().elementbuffer);


		
	//	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

	 	glDrawElements(
			GL_TRIANGLES,      // mode
			getStructure().indices.size(),    // count
			GL_UNSIGNED_SHORT,   // type
			(void*)0           // element array buffer offset
		);

		glDisableVertexAttribArray(0);

};



void CubicList::initModelMatrix(){
 
	my_structure.position = glm::vec3 (-10.0f,5.0f,0.0f);
	my_structure.orientation = glm::quat(glm::vec3(90.0f, 0.0f, 90.0f));

	glm::mat4 RotationMatrix = glm::toMat4(my_structure.orientation);
	glm::mat4 TranslationMatrix = glm::translate(glm::mat4(), my_structure.position);
	glm::mat4 model = TranslationMatrix * RotationMatrix;
	
	my_structure.modelMatrix =   model;

	
	

};


void CubicList::initFocusShape(){
 	my_structure.collisionShape = new btConvexHullShape();
 	for(int i=0; i<my_structure.vertices.size(); i++){
 		my_structure.collisionShape->addPoint(btVector3(my_structure.vertices[i].x,my_structure.vertices[i].y,my_structure.vertices[i].z));
	}

};

