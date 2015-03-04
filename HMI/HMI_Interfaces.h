#include "HMI_DataStruct.h" 
class Voice_Cmd_Recog{
public: 
	virtual void callVoiceAction(voice_cmd_t* cmd);
};


//class Gesture_Recog{
//public:
	//virtual gesture_event recog();
//};


class Eye_Recog{
public:
	 void callEyeAction( float *x, float*y);
	void (*action)(float*, float*);
};

