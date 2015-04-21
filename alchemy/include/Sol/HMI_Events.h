#ifndef HMI_EVENTS_H
#define HMI_EVENTS_H
#include "Event_Manager.h"
// internall 
class GestureEvent{
public: 


	GestureEvent(Event_Manager* em);

	void update(gesture_event g);

private: 
	Event_Manager* event_manager;
	GestureEvent();
	~GestureEvent();

};


// internall
class EyeEvent{
public:
	EyeEvent(Event_Manager* em);

	void update(eye_event e);
private: 
	EyeEvent();
	~EyeEvent();
	Event_Manager* event_manager;
};

// internall
class VoiceEvent{
public: 
	VoiceEvent(Event_Manager* em);

	void update(voice_cmd_event v);
private: 
	VoiceEvent();
	~VoiceEvent();
	Event_Manager* event_manager;

};
#endif