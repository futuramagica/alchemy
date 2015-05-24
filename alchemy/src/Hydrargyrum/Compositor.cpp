#include "Hydrargyrum\Compositor.h"
#include "Hydrargyrum\UIElement.h"


Compositor* Compositor::compositor = NULL;

Compositor* Compositor::getInstance(){
	if (compositor == NULL){
		compositor = new Compositor;
	}
	return compositor;
};


Compositor::Compositor(){

};

Compositor::~Compositor(){

};

void Compositor::makeMagic(){

	for (std::list<UIElement*>::iterator it = Compositor::ui_widget_container.elements.begin(); it != Compositor::ui_widget_container.elements.end(); it++){

			UIElement* ui = *it; 
			ui->draw();

		}

	
};

void Compositor::addUIElement(UIElement* e){
	ui_widget_container.elements.push_back(e);
};

std::list<UIElement*> Compositor::getElements(){

	return ui_widget_container.elements;
};