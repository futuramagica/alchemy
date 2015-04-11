// internal events 

#ifndef EVENTINTERFACE_H
#define EVENTINTERFACE_H

#include "Sol\HMI_Interfaces.h"

class EventInterface
{
public:
	
	virtual void onEvent (int code)=0; /// this is depricated should be removed 
	
	virtual void onEyeEvent (eye_event* e)=0;
	virtual void onVoiceEvent (voice_cmd_event* v)=0;
	virtual void onGestureEvent (gesture_event* g)=0;
};
#endif