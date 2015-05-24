#ifndef UIELEMENTSLIST_H
#define UIELEMENTSLIST_H

#include "Hydrargyrum\UIElement.h"
#include <list>

struct ui_elements{
	std::list<UIElement*> elements;
	UIElement* inFocus;
};


#endif