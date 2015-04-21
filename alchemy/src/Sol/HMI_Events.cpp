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


VoiceEvent::VoiceEvent(Event_Manager* em){

	assert(em!=NULL);
	event_manager=em;
};


void VoiceEvent::update(voice_cmd_event v){
	event_manager->voice_event_q_push(v);
};


GestureEvent::GestureEvent(Event_Manager* em){

	assert(em!=NULL);
	event_manager=em;
};


void GestureEvent::update(gesture_event g){
	event_manager->gesture_event_q_push(g);
};