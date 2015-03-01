#pragma once
 

class Voice_Cmd_Recog{
//public: 
	//virtual voice_cmd_event recog();
};


class Gesture_Recog{
//public:
	//virtual gesture_event recog();
};


class Eye_Recog{
public:
	// virtual  void  recog();
//	 void setCallBackAction(void(*action)(float *, float*));
	 void callAction( float *x, float*y);
	void (*action)(float*, float*);
};

/*
void Eye_Recog::setCallBackAction(void(*act)(float*, float*)){
	action = act;
};

void Eye_Recog::callAction(float *x, float*y){
	(*action)(x,y);
};*/