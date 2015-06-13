#ifndef UIFLOOR_H
#define UIFLOOR_H

#include "UIElement.h"

class Floor: public UIElement {

	


public: 
	Floor();
	~Floor();
	void draw(glm::mat4 projectionMatrix, glm::mat4 viewMatrix);

	void initFocusShape();
	void initModelMatrix();
 
		

};


#endif
