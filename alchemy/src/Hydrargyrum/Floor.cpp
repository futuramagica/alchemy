#include "Hydrargyrum\Floor.h"


Floor::Floor(){
	Floor::initModelMatrix();
};

Floor::~Floor(){

};

// all of the matrices should be handled by Compositor 
void Floor::draw(glm::mat4 projectionMatrix, glm::mat4 viewMatrix){

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Use our shader
		glUseProgram(UIElement::my_structure.shaderID);

	
		glm::mat4 MVP = projectionMatrix * viewMatrix * UIElement::my_structure.modelMatrix;

		glUniformMatrix4fv(UIElement::my_structure.MatrixID, 1, GL_FALSE, &MVP[0][0]);


		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, UIElement::my_structure.vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, UIElement::my_structure.elementbuffer);

		glDrawElements(
			GL_TRIANGLES,      // mode
			UIElement::my_structure.indices.size(),    // count
			GL_UNSIGNED_SHORT,   // type
			(void*)0           // element array buffer offset
		);

		glDisableVertexAttribArray(0);

};


void Floor::initModelMatrix(){


	printf("ININT FLOOOOOORRR");
		
		UIElement::my_structure.modelMatrix = glm::mat4(1.0);
		
		UIElement::my_structure.modelMatrix = glm::rotate(
            UIElement::my_structure.modelMatrix,
            -115.0f,
            glm::vec3(1.0f, 0.0f, 0.0f)
        );

		UIElement::my_structure.modelMatrix = glm::scale(UIElement::my_structure.modelMatrix,glm::vec3(3.0f,2.5f,2.5f));
		
		//ModelMatrix = glm::translate(ModelMatrix, glm::vec3(10.0f, 0.0f, 30.0f));
};