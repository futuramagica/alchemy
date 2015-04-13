#ifndef UIDATASTRUCTURES_H
#define UIDATASTRUCTURES_H

#include <list>

enum ui_orientation {left, right, top, bottom, center};


struct ui_elem_pos {
	// top left corner 
	double x;
	double y;
};

struct ui_element {
	double border;
	int texture;
	int color;
	int mode;//	(blink = 1, normal = 0– when element to be moved)
	ui_elem_pos position; 
	ui_orientation orientation;
};

//// Need a change here that contradicts to current elements container in Scene
struct ui_elements{
	//std::list<UIElement> *elements;
};
#endif