#include "Hydrargyrum\Floor.h"


Floor::Floor(){
	initModelMatrix();
	Floor::initFocusShape();
};

Floor::~Floor(){

};

// all of the matrices should be handled by Compositor 
void Floor::draw(glm::mat4 projectionMatrix, glm::mat4 viewMatrix){

		

		// Use our shader
		glUseProgram(getStructure().shaderID);

	
		glm::mat4 MVP = projectionMatrix * viewMatrix * getStructure().modelMatrix;

		glUniformMatrix4fv(getStructure().MatrixID, 1, GL_FALSE, &MVP[0][0]);


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
		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
		glDrawElements(
			GL_TRIANGLES,      // mode
			getStructure().indices.size(),    // count
			GL_UNSIGNED_SHORT,   // type
			(void*)0           // element array buffer offset
		);

		glDisableVertexAttribArray(0);

};


void Floor::initModelMatrix(){
		
	
	my_structure.position = glm::vec3 (2,3,2);
	my_structure.orientation = glm::quat(glm::vec3(10, 10, 10));


	glm::mat4 RotationMatrix = glm::toMat4(my_structure.orientation);
	glm::mat4 TranslationMatrix = glm::translate(glm::mat4(), my_structure.position);
	glm::mat4 model = TranslationMatrix * RotationMatrix;

	/*model = glm::rotate(
            model,
            -115.0f,
            glm::vec3(1.0f, 0.0f, 0.0f)
        );*/

		//model = glm::scale(model,glm::vec3(3.0f,2.5f,2.5f));
		
		
		my_structure.modelMatrix = model;
		
		
		//ModelMatrix = glm::translate(ModelMatrix, glm::vec3(10.0f, 0.0f, 30.0f));
};


void Floor::initFocusShape(){

	my_structure.collisionShape  = new btBoxShape(btVector3(7.0f,7.0f,0.1f));

};