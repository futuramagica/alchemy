#ifndef CUBICLIST_H
#define CUBICLIST_H

#include "UIElement.h"

class CubicList: public UIElement{


public:
	CubicList();
	~CubicList();

	void draw(glm::mat4 projectionMatrix, glm::mat4 viewMatrix);
	void initFocusShape();

protected: 

	void initModelMatrix();

};

#endif