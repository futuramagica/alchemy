#ifndef _INC_SOL
#define _INC_SOL

#include "HMI_Interfaces.h"


#include <boost/thread/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/atomic.hpp>

class Sol {

public: 

	
	static Sol* getInstance();


	void startEventsListeners();


	int destroy();

	void setVoiceRecogImpl(Voice_Cmd_Recog* v);
	void setEyeRecogImpl(Eye_Recog* e);
	void setGestureRecogImpl(Gesture_Recog* g);


protected: 
	void start_eye_recog_thread();
	void start_eye_recog();


	void start_voice_recog_thread();
	void start_voice_recog();


	void start_gesture_recog_thread();
	void start_gesture_recog();

private:
	Sol();
	~Sol();

	static Sol* sol;

	Eye_Recog* eye_recog;
	Voice_Cmd_Recog* voice_recog;
	Gesture_Recog* gesture_recog;


	//eye_event eye;
//	voice_cmd_event cmd_event;
	
	

};



#endif