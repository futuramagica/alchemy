// singleton that configure and initialize all components, checking that all components work fine
// aviable for API user 

#ifndef PRIMA_H
#define PRIMA_H

#include "Sol\Sol.h"
#include "Sol\Event_Manager.h"
#include "Sol\HMI_Events.h"
#include "Hydrargyrum\Hydrargyrum.h"


class Prima{
	
public: 

	
	static Prima* getInstance();

	int init();
	void start();// starting all required services Sol, Hydr, Sulfur.

	int destroy();
	void stop();
	
	
	Voice_Cmd_Recog* getVoice_Cmd_Recog();
	void setVoice_Cmd_Recog(Voice_Cmd_Recog* v);

	Eye_Recog* getEye_Recog();
	void setEye_Recog(Eye_Recog* e);

	Gesture_Recog* getGesture_Recog();
	void setGesture_Recog(Gesture_Recog* g);



protected: 

	Sol* getSol();
	void setSol(Sol* s);

	Hydrargyrum* getHydrargyrum();
	void setHydrargyrum(Hydrargyrum* h);

	Event_Manager* getEvent_Manager();
	void setEvent_Manager(Event_Manager* e);

private: 

	Prima();
	~Prima();

	int checkReadiness(); 

	int initInternallComponents();// called inside init 

	// need their setter and getters
	Sol* sol;
	Hydrargyrum* hydrargyrum;
	Event_Manager* event_Manager;
	
	EyeEvent* ee;
	VoiceEvent* ve;
	GestureEvent* ge;

	Voice_Cmd_Recog* voice;
	Eye_Recog* eye;
	Gesture_Recog* gesture;
	
	


	static Prima* prima;
	


};


#endif 