#include "stdafx.h"
#include <stdio.h>

#include "UIElement.h"
 void UIElement::Display()
{
  printf("%i",x);
}
 void UIElement::Resize(double k)
 {
	 width*=k;
	 height*=k;
 }
 void UIElement::Draw(Renderer* r)
 {
	 printf("UIElement::Draw()");
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