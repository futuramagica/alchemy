#ifndef _INC_HMI_INTERFACES
#define _INC_HMI_INTERFACES

#include "HMI_DataStruct.h" 
#include "HMI_Events.h"
// external to API user 
class Voice_Cmd_Recog{
public: 
	//that is only method should be used 
	void notifyChange (voice_cmd_t* cmd);
	//virtual void startRecognition();
protected: 
	void setVoiceEvent(VoiceEvent* voiceEvent);// deprectated 

private: 	
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
	void notifyChange (eye_event e);
	virtual void startRecognition() = 0;
	virtual void stopRecognition() = 0;
	
	void setEyeEvent(EyeEvent* ee);

private: 	
	 EyeEvent* eyeEvent;
};



#endif