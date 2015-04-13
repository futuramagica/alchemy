// works as intermediate for processing events and makign sure all event completed before bew come in. 
// might be used threads here and Qs of pending events with some logic of expiration- but that is for next phases 
// singleton class 

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "Hydrargyrum\Hydrargyrum.h"

class Event_Manager {

public: 
	static Event_Manager* getInstance();

private: 

	Event_Manager(); 
	~Event_Manager();

	static Event_Manager* event_Manager;

};
#endif