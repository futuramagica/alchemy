#include "Hydrargyrum\Floor.h"


Floor::Floor(){
	//this->initModelMatrix();
	
};

Floor::~Floor(){

};

// all of the matrices should be handled by Compositor 
void Floor::draw(glm::mat4 projectionMatrix, glm::mat4 viewMatrix){

		

		// Use our shader
		glUseProgram(getStructure().shaderID);

	
		glm::mat4 RotationMatrix = glm::toMat4(my_structure.orientation);
		glm::mat4 TranslationMatrix = glm::translate(glm::mat4(), my_structure.position);
		glm::mat4 ModelMatrix = TranslationMatrix * RotationMatrix;

		glm::mat4 MVP = projectionMatrix * viewMatrix * ModelMatrix;

		
		glUniformMatrix4fv(my_structure.MatrixID, 1, GL_FALSE, &MVP[0][0]);
		glUniformMatrix4fv(my_structure.ModelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
		glUniformMatrix4fv(my_structure.ViewMatrixID, 1, GL_FALSE, &viewMatrix[0][0]);


		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, my_structure.vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, my_structure.elementbuffer);
		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
		glDrawElements(
			GL_TRIANGLES,      // mode
			my_structure.indices.size(),    // count
			GL_UNSIGNED_SHORT,   // type
			(void*)0           // element array buffer offset
		);

		glDisableVertexAttribArray(0);

};


void Floor::initModelMatrix(){
		
	printf("\n CALLED INITMATRIX \n");



	


	my_structure.position = glm::vec3(0,0,0);
	 	my_structure.orientation = glm::quat(glm::vec3(45, 0, 0));

	 
 
	 glm::mat4 RotationMatrix = glm::toMat4(my_structure.orientation);
	glm::mat4 TranslationMatrix = glm::translate(glm::mat4(), my_structure.position);
	glm::mat4 model = TranslationMatrix * RotationMatrix;

	my_structure.modelMatrix = model;
		
		
	 
};


void Floor::initFocusShape(){

	//my_structure.collisionShape  = new btBoxShape(btVector3(7.0f,7.0f,0.1f));
	my_structure.collisionShape = new btConvexHullShape();

	for(int i=0; i<my_structure.vertices.size(); i++){
		printf("Adding elements x = %d", my_structure.vertices[i].x);
		my_structure.collisionShape->addPoint(btVector3(my_structure.vertices[i].x,my_structure.vertices[i].y,my_structure.vertices[i].z));
	}

};