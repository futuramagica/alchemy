#ifndef UIELEMENT_H
#define UIELEMENT_H
#include "UIDataStructures.h"


// is just a container for structure and logic of data structure change, while compositor is responsible for display it 
class UIElement 
{
public:
	UIElement();
	~UIElement();


private:

	ui_element my_structure;
};

#endif