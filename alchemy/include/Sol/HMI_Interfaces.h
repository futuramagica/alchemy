#ifndef _INC_HMI_INTERFACES
#define _INC_HMI_INTERFACES

#include "HMI_DataStruct.h" 
#include "HMI_Events.h"
// external to API user 
class Voice_Cmd_Recog{
public: 
	//that is only method should be used 
	void notifyChange (voice_cmd_t* cmd);
	// virtual void runChange();

	// both deprecated - should be removed 
	void callVoiceAction(voice_cmd_t* cmd);
	void setCallVoiceAction(void(*act)(voice_cmd_t*));

protected: 
	void setVoiceEvent(VoiceEvent* voiceEvent);// deprectated 

private: 	
	 void (*action)(voice_cmd_t*);
	 VoiceEvent* voiceEvent;

};

// external to API user 
class Gesture_Recog{
public:
	void notifyChange(gesture_event* g);
	// virtual void runChange();

protected: 
	void setGestureEvent(GestureEvent* gestureEvent);

private: 
	GestureEvent* gestureEvent;

};

// external to API user 
class Eye_Recog{
public:
	//that is only method should be used 
	void notifyChange (eye_event* e);
	// virtual void runChange();

	// both deprecated - should be removed 
	void callEyeAction( float *x, float*y);
	void setCallEyeAction(void(*act)(float *x, float*y));

protected:
	void setEyeEvent(EyeEvent* eyeEvent);

private: 	
	 void (*action)(float*, float*); // deprectated 
	 EyeEvent* eyeEvent;
};



#endif