// singleton that configure and initialize all components, checking that all components work fine
// aviable for API user 

#ifndef PRIMA_H
#define PRIMA_H

#include "Sol\Sol.h"
#include "Sol\Event_Manager.h"
#include "Hydrargyrum\Hydrargyrum.h"

class Prima{
	
public: 

	
	static Prima* getInstance();

	int init();
	void start();// starting all required services Sol, Hydr, Sulfur.

	int destroy();
	void stop();

	Sol* getSol();
	void setSol(Sol* s);

	Hydrargyrum* getHydrargyrum();
	void setHydrargyrum(Hydrargyrum* h);

	Event_Manager* getEvent_Manager();
	void setEvent_Manager(Event_Manager* e);

protected: 
	Prima();
	~Prima();

	int checkReadiness(); 
	int startEyeRecog();
	int startGestureRecog();
	int startVoiceRecog();

	void initInternallComponents();// called inside init 



private: 

	
	// need their setter and getters
	Sol* sol;
	Hydrargyrum* hyrargyrum;
	Event_Manager* event_Manager;
	
	Voice_Cmd_Recog* voice;
	Eye_Recog* eye;
	Gesture_Recog* gesture;


	static Prima* prima;
	


};


#endif 