#ifndef _INC_HMI_DATASTRUCTURE
#define _INC_HMI_DATASTRUCTURE


struct eye_event{
	float x;
	float y;
};
 

enum gesture_t {no_gesture,click, move};

struct gesture_event{
	gesture_t gesture;
	double x_move;
	double y_move;
};

enum  voice_cmd_t {no_voice,sel, reply, forward, close};

struct voice_cmd_event{
	voice_cmd_t voice_cmd;
};

#endif  /* _INC_HMI_DATASTRUCTURE */