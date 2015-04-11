#include <stdio.h>
#include "Hydrargyrum\SimpleList.h"
#include "Hydrargyrum\SimpleListElement.h"


#include "glew-1.12.0\include\GL\glew.h"
#include "glew-1.12.0\include\GL\wglew.h"

// Include GLFW
#include "GLFW\glfw3.h"

// Include GLM
#include "glm-0.9.4.0\glm\glm.hpp"
using namespace glm;
SimpleList::SimpleList(int x_, int y_ , int width_, int height_)
 {
	 x=x_;
	 y=y_;
	 height=height_;
	 width=width_;
	 _margin=15;
	 _elementHeight=40;
 }

void SimpleList::onEvent(int code)
{

	highlighted=!highlighted;
}

void SimpleList::Display()
{
	//printf("%i,%i",x,y);
}

void SimpleList::Draw(Renderer* r) 
{
	//printf("Draw()\n");

	//printf("%i %i %i %i\n", left,right,top,bottom);
	RectangleInfo* ri=this->getRect();
	/*ri.x=displayedX();
	ri.y=displayedY();
	ri.width=displayedWidth();
	ri.height=displayedHeight();
	ri.thickness=highlighted? 3:1;*/
	r->DrawRectangle(ri);
	for (int i=0;i<Elements.Size();i++)
	{
	//	printf("%i\n",i);
		
		SimpleListElement* current=(SimpleListElement*)Elements.Next();
		
	//	printf("%i\n",current);
		current->Draw(r,i);
	}

}

void SimpleList::AddElement(UIElement* e)
	{
		//printf("%i",&Elements);
		Elements.AddElement(e);
	}
int SimpleList::ElementCount()
{
	return Elements.Size();
}
int SimpleList::margin()
{
	return _margin;
}
int SimpleList::elementHeight()
{
	return _elementHeight;
}
void SimpleList::MouseOver (int cursorX, int cursorY)
{
//	printf("SimpleList::MouseOver\n");
	UIElement::MouseOver(x,y);

	for (int i=0;i<Elements.Size();i++)
	{
		SimpleListElement* current=(SimpleListElement*)Elements.Next();
		RectangleInfo* ri  = current->getRect(i);
		RectangleInfo localRect=*ri;
	//	printf("Rectangle defined by x=%i,y=%i,width=%i,height=%i, list located at x=%i,y=%i, cursor located at x=%i,y=%i\n",localRect.x,localRect.y,localRect.width,localRect.height,this->x,this->y,cursorX,cursorY);
		//system("pause");
	//	printf("%i>=%i:%i\n",cursorX,localRect.x,cursorX>=localRect.x);
	//	printf("%i>=%i:%i\n",cursorY,localRect.y,cursorY>=localRect.y);
	//	printf("%i\n",cursorX<=localRect.x+localRect.width);
	//	printf("%i\n",cursorY<=localRect.height+localRect.y);
			if ((cursorX>=localRect.x)&&(cursorY>=localRect.y)&&(cursorX<=localRect.x+localRect.width)&&(cursorY<=localRect.height+localRect.y))
			{
		//		printf("SimpleList::Match for x=%i,y=%i!\n",cursorX,cursorY);
				//system("pause");
				current->MouseOver(cursorX,cursorY);
			}
			else
			{
				if (current->highlighted)
				{
					current->highlighted=false;
				}
			}
	}
}


void SimpleList::onEyeEvent (eye_event* e){
	printf("on eye");
};
void SimpleList::onVoiceEvent (voice_cmd_event* v){
	printf("on voice");
};
void SimpleList::onGestureEvent (gesture_event* g){
	printf("on gesture");

};