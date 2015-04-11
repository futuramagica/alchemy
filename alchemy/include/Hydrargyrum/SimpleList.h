#ifndef SIMPLELIST_H
#define SIMPLELIST_H
#include "UIElement.h"
#include "EventInterface.h"
#include "Renderer.h"
#include "LinkedList.h"
//#include "SimpleListElement.h"

class SimpleList:public UIElement, public EventInterface
{
public:
	SimpleList(int x_, int y_ , int height_, int width_);
	void Display();
	void Draw(Renderer* r) ;
	void onEvent(int code);

	void onEyeEvent (eye_event* e);
	void onVoiceEvent (voice_cmd_event* v);
	void onGestureEvent (gesture_event* g);


	void AddElement(UIElement* e);

	int ElementCount();
	int margin();
	int elementHeight();
	void MouseOver (int x, int y);
private:
	LinkedList<UIElement> Elements;
	int _margin;
	int _elementHeight;
};
#endif