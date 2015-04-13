#include "Sol\Event_Manager.h"

Event_Manager* Event_Manager::event_Manager = NULL;

Event_Manager::Event_Manager(){

};


Event_Manager::~Event_Manager(){

};


Event_Manager* Event_Manager::getInstance(){

	if (event_Manager == NULL){
		event_Manager = new Event_Manager;
	}
	return event_Manager;

};