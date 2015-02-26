#include <HMI_DataStruct.h>

class Voice_Cmd_Recog{
public: 
	virtual voice_cmd_event recog();
}


class Gesture_Recog{
public:
	virtual gesture_event recog();
}


class Eye_Recog{
public:
	virtual eye_event recog();
}