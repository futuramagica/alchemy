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
	 Compositor::initLayout();
};

Compositor::~Compositor(){

};

void Compositor::makeMagic(){

	for (std::list<UIElement*>::iterator it = Compositor::ui_widget_container.elements.begin(); it != Compositor::ui_widget_container.elements.end(); it++){

			UIElement* ui = *it; 
			ui->draw(Compositor::projectionMatrix,Compositor::viewMatrix);

		}

	
};

void Compositor::addUIElement(UIElement* e){
	ui_widget_container.elements.push_back(e);
};

std::list<UIElement*> Compositor::getElements(){

	return ui_widget_container.elements;
};


void Compositor::initLayout(){

	Compositor::projectionMatrix = glm::perspective(95.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	

	glm::vec3 direction(
		cos(0.0f) * sin(3.14f), 
		sin(0.0f),
		cos(0.0f) * cos(3.14f));
		
	glm::vec3 position = glm::vec3( 0, 25, 32 ); 

	Compositor::viewMatrix =  glm::lookAt(
								position,           // Camera is here
								position+direction, // and looks here : at the same position, plus "direction"
								glm::vec3( 0, 1, 0 )                  // Head is up (set to 0,-1,0 to look upside-down)
						   );

	
	 printf("\n ININT COMMMMPOOOSITRO");

};