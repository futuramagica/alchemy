// singleton that configure and initialize all components, checking that all components work fine
// aviable for API user 

#ifndef PRIMA_H
#define PRIMA_H

#include "Sol\Sol.h"
#include "Sol\Event_Manager.h"
#include "Hyrargyrum\Hyrargyrum.h"

class Prima{
	
public: 

	Prima getInstance();




private: 

	Prima();
	~Prima();
	// need their setter and getters
	Sol* sol;
	Hyrargyrum* hyrargyrum;
	Event_Manager* event_Manager;
}


#endif 