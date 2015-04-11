#include "Sol\HMI_Interfaces.h"
void Eye_Recog::callEyeAction(float *x, float*y){
	(*action)(x,y);
}; 

void Eye_Recog::setCallEyeAction(void(*act)(float *x, float*y)){
	action=act;
}; 


void  Voice_Cmd_Recog::setCallVoiceAction(void(*act)(voice_cmd_t*)){
	action=act;
}

void Voice_Cmd_Recog::callVoiceAction(voice_cmd_t* cmd){
	
	(*action)(cmd);
}

void Eye_Recog::notifyChange (eye_event* e){

};


void Voice_Cmd_Recog::notifyChange (voice_cmd_t* cmd){

};

void GestureEvent::update(gesture_event* g){

};