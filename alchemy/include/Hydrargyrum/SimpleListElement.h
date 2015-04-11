#include "UIElement.h"
#include "SimpleList.h"
class SimpleListElement: public UIElement
{
public:
	void SimpleListElement::Draw(Renderer* r, int index) ;
	void Prime(int maxwidth, int maxheight);
	SimpleListElement(SimpleList* newparent, int width, int height);
	RectangleInfo* getRect(int position);
	void MouseOver(int x, int y);
private:

};