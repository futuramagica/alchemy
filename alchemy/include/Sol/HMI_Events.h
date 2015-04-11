#ifndef HMI_EVENTS_H
#define HMI_EVENTS_H
#include "Event_Manager.h"
// internall 
class GestureEvent{
public: 
	void update(gesture_event* g);

protected: 
	Event_Manager event_manager;
};


// internall
class EyeEvent{
public: 
	void update(eye_event* e);
protected: 
	Event_Manager event_manager;
};

// internall
class VoiceEvent{
public: 
	void update(voice_cmd_t* e);
protected: 
	Event_Manager event_manager;

};
#endif