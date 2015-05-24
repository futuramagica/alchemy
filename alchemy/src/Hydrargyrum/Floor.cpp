#include "Hydrargyrum\Floor.h"


Floor::Floor(){

};

Floor::~Floor(){

};


void Floor::draw(){

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Use our shader
		glUseProgram(UIElement::my_structure.shaderID);


		//computeMatricesFromInputs();
		glm::mat4 ProjectionMatrix = glm::perspective(90.0f, 4.0f / 3.0f, 0.1f, 100.0f);
		
		
		glm::vec3 direction(
		cos(0.0f) * sin(3.14f), 
		sin(0.0f),
		cos(0.0f) * cos(3.14f));
		
		glm::vec3 position = glm::vec3( 0, 10, 32 ); 

		glm::vec3 right = glm::vec3(
		sin(3.14f - 3.14f/2.0f), 
		0,
		cos(3.14f - 3.14f/2.0f)
	);
	
	// Up vector
	glm::vec3 up = glm::cross( right, direction );

		glm::mat4 ViewMatrix =  glm::lookAt(
								position,           // Camera is here
								position+direction, // and looks here : at the same position, plus "direction"
								up                  // Head is up (set to 0,-1,0 to look upside-down)
						   );
		
		
		glm::mat4 ModelMatrix = glm::mat4(1.0);
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

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
