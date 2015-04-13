
#include <stdio.h>
#include "Hydrargyrum\UIElement.h"

void UIElement::Display()
{
//  printf("%i",x);
}
 void UIElement::Resize(double k)
 {
	 width*=k;
	 height*=k;
 }
 void UIElement::Draw(Renderer* r)
 {
	// printf("UIElement::Draw()");
 }
 void UIElement::Move(int dx, int dy)
 {
	 x+=dx;
	 y+=dy;
 }
 UIElement::UIElement(int x_, int y_ , int height_, int width_)
 {
	 x=x_;
	 y=y_;
	 height=height_;
	 width=width_;
 }
 UIElement::UIElement()
{
	x=0;
	y=0;
	width=50;
	height=50;
}
 int UIElement::displayedX()
 {
	 return highlighted?x-width*0.15:x;
 }
 int UIElement::displayedY()
 {
	 return highlighted?y-height*0.15:y;
 }
 int UIElement::displayedHeight()
 {
	 return highlighted?height*1.3:height;
 }
 int UIElement::displayedWidth()
 {
	 return highlighted?width*1.3:width;
 }
 void UIElement::MouseOver(int x, int y)
 {
	 if (!highlighted)
	 {
		 highlighted=true;
	 }
 }
RectangleInfo* UIElement::getRect()
 {
	RectangleInfo ri;
	ri.x=displayedX();
	ri.y=displayedY();
	ri.width=displayedWidth();
	ri.height=displayedHeight();
	ri.thickness=highlighted? 3:1;
	//printf("GetRect returning: x=%i,y=%i,width=%i,height=%i\n",ri.x,ri.y,ri.width,ri.height);
	return &ri;
 }