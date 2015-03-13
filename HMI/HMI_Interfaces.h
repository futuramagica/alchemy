#ifndef _INC_HMI_INTERFACES
#define _INC_HMI_INTERFACES

#include "HMI_DataStruct.h" 
class Voice_Cmd_Recog{
public: 
	void callVoiceAction(voice_cmd_t* cmd);
	void setCallVoiceAction(void(*act)(voice_cmd_t*));
private: 	
	 void (*action)(voice_cmd_t*);
};


//class Gesture_Recog{
//public:
	//virtual gesture_event recog();
//};


class Eye_Recog{
public:
	 void callEyeAction( float *x, float*y);
	 void setCallEyeAction(void(*act)(float *x, float*y));
private: 	
	 void (*action)(float*, float*);
};


#endif