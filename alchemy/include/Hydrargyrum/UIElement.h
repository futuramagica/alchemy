#ifndef UIELEMENT_H
#define UIELEMENT_H
#include "Renderer.h"
#include "UIDataStructures.h"


// is just a container for structure and logic of data structure change, while compositor is responsible for display it 
class UIElement 
{
public:
virtual void Resize (double k);
virtual void Move (int x, int y);
virtual void Draw(Renderer* r); // this is depricated should be part of Compositor. 
virtual void Display();

RectangleInfo* getRect();
int displayedX();
int displayedY();
int displayedHeight();
int displayedWidth();
virtual void MouseOver(int x, int y);


bool highlighted;
 UIElement(int x_, int y_ , int height_, int width_);

 UIElement();
protected:

	// Please amend this part ot have good structure in place 
	ui_element structure;
int x;
int y;
int width;
int height;
UIElement* Parent;
};

#endif