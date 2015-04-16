#include "Sol\HMI_Events.h"
#include "assert.h"


EyeEvent::EyeEvent(Event_Manager* em){
	assert(em!=NULL);
	event_manager=em;
};

EyeEvent::~EyeEvent(){

};

void EyeEvent::update(eye_event e){

	//printf("CALLED::::update(eye_event e) X=%f Y=%f",e.x,e.y);
	event_manager->eye_event_q_push(e);
	  
};
