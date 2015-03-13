#include "UIElement.h"
#include "EventInterface.h"
#include "Renderer.h"

class SimpleList:public UIElement, public EventInterface
{
public:
	SimpleList(int x_, int y_ , int height_, int width_);
	void Display();
	void Draw(Renderer* r);
	void OnEvent(int code);
};