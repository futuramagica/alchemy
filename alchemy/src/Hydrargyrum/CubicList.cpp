#include "Hydrargyrum\CubicList.h"



CubicList::CubicList(){
	CubicList::initModelMatrix();
	CubicList::initFocusShape();
};

CubicList::~CubicList(){

};




void CubicList::draw(glm::mat4 projectionMatrix, glm::mat4 viewMatrix){


	glUseProgram(getStructure().shaderID);

	
		glm::mat4 RotationMatrix = glm::toMat4(getStructure().orientation);
		glm::mat4 TranslationMatrix = glm::translate(glm::mat4(), getStructure().position);
		glm::mat4 ModelMatrix = TranslationMatrix * RotationMatrix;

		glm::mat4 MVP = projectionMatrix * viewMatrix * ModelMatrix;

		
		glUniformMatrix4fv(my_structure.MatrixID, 1, GL_FALSE, &MVP[0][0]);
		glUniformMatrix4fv(my_structure.ModelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
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


		
		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );



		glDrawElements(
			GL_TRIANGLES,      // mode
			getStructure().indices.size(),    // count
			GL_UNSIGNED_SHORT,   // type
			(void*)0           // element array buffer offset
		);

		glDisableVertexAttribArray(0);

};



void CubicList::initModelMatrix(){

		//glm::mat4 model =glm::mat4(1.0f);// glm::scale(glm::mat4(1.0f),glm::vec3(1.5f,1.5f,0.5f)); 
		
		my_structure.position = glm::vec3 (0,0,0);//glm::vec3(rand()%20-10, rand()%20-10, rand()%20-10);//
	my_structure.orientation = glm::quat(glm::vec3(90,0, 0));//glm::quat(glm::vec3(rand()%360, rand()%360, rand()%360));;//glm::quat(glm::vec3(10, 10, 10));

	
	glm::mat4 RotationMatrix = glm::toMat4(my_structure.orientation);
	glm::mat4 TranslationMatrix = glm::translate(glm::mat4(), my_structure.position);
	glm::mat4 model = TranslationMatrix * RotationMatrix;
	


		/*UIElement::my_structure.modelMatrix = glm::rotate(
            UIElement::my_structure.modelMatrix,
            -90.0f,
            glm::vec3(1.0f, 0.0f, 0.0f)
        );

		*/

		//model = glm::rotate(
  //          model,
  //          -90.0f,
  //          glm::vec3(1.0f, 0.0f, 0.0f)
  //      );

	
		//model = glm::rotate(
  //         model,
  //          -90.0f,
  //          glm::vec3(0.0f, 1.0f, 0.0f)
  //      );

		//model = glm::translate(model, glm::vec3(12.0f, 0.0f, 0.0f));
		//model = glm::translate(model, glm::vec3(0.0f, -28.0f, 0.0f));
		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 5.0f));


		my_structure.modelMatrix = model;
		//UIElement::my_structure.modelMatrix = glm::scale(UIElement::my_structure.modelMatrix,glm::vec3(0.3f,0.5f,0.5f));

		

};


void CubicList::initFocusShape(){
	my_structure.collisionShape  = new btBoxShape(btVector3(8.0f,10.0f,1.0f));
};