#include "Hydrargyrum\SimpleListElement.h"
#include <stdio.h> 

void SimpleListElement::Draw(Renderer* r, int index)  
{
	/*int baseX = Parent->displayedX();
	int baseY = Parent->displayedY();
	int displayMargin=((SimpleList*)Parent)->margin();
	
	int height=((SimpleList*)Parent)->elementHeight();
	int width=Parent->displayedWidth()-2*displayMargin;
	int posX=baseX+displayMargin;
	int posY=baseY+index*(displayMargin+height)+displayMargin;
	if (!highlighted)
	{
		posX+=displayMargin;
		width-=displayMargin*2;
	}
	RectangleInfo ri;
	ri.x=posX;
	ri.y=posY;
	ri.width=width;
	ri.height=height;
	ri.thickness=highlighted?2:1;*/
	RectangleInfo* ri=this->getRect(index);
	r->DrawRectangle(ri);
}
SimpleListElement::SimpleListElement(SimpleList* newparent, int newwidth, int newheight)
{
	Parent=(UIElement*)newparent;
	
	width=newwidth;
	
	height=newheight;
	highlighted=false;
}
void SimpleListElement::Prime(int maxwidth, int maxheight)
{
	if (width>=maxwidth)
	{
		width=maxwidth;
	}
	if (height>=maxheight)
	{
		height=maxheight;
	}
}
RectangleInfo* SimpleListElement::getRect(int position)
{
	int baseX = Parent->displayedX();
	int baseY = Parent->displayedY();
	int displayMargin=((SimpleList*)Parent)->margin();
	
	int height=((SimpleList*)Parent)->elementHeight();
	int width=Parent->displayedWidth()-2*displayMargin;
	int posX=baseX+displayMargin;
	int posY=baseY+position*(displayMargin+height)+displayMargin;
	if (!highlighted)
	{
		posX+=displayMargin;
		width-=displayMargin*2;
	}
	RectangleInfo ri;
	ri.x=posX;
	ri.y=posY;
	ri.width=width;
	ri.height=height;
	ri.thickness=highlighted?2:1;
//	printf("GetRect returning: x=%i,y=%i,width=%i,height=%i\n",ri.x,ri.y,ri.width,ri.height);
	return &ri;

}
void SimpleListElement::MouseOver(int x, int y)
{
	UIElement::MouseOver(x,y);
//	printf("SimpleListElement::MouseOver\n");
}