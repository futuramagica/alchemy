#ifndef UIELEMENT_H
#define UIELEMENT_H
#include "Renderer.h"
class UIElement
{
public:
virtual void Resize (double k);
virtual void Move (int x, int y);
virtual void Draw(Renderer* r);
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
int x;
int y;
int width;
int height;
UIElement* Parent;
};

#endif