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