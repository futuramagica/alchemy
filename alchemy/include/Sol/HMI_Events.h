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