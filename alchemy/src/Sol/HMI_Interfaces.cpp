#include "Sol\HMI_Interfaces.h"

void Eye_Recog::notifyChange (eye_event e){
	
	eyeEvent->update(e);
};


void Eye_Recog::setEyeEvent(EyeEvent* ee){

	eyeEvent = ee;

};


void Voice_Cmd_Recog::notifyChange (voice_cmd_event cmd){

	voiceEvent->update(cmd);
};


void  Voice_Cmd_Recog::setVoiceEvent(VoiceEvent* ve){

	voiceEvent=ve;
}; 

 	
void Gesture_Recog::notifyChange (gesture_event g){

	gestureEvent->update(g);
};


void  Gesture_Recog::setGestureEvent(GestureEvent* ge){

	gestureEvent=ge;
}; 