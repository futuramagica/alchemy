#include "Sol\Sol.h"

#include <boost/thread/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/atomic.hpp>

Sol* Sol::sol = NULL;

Sol* Sol::getInstance(){
	if (sol == NULL){
		sol = new Sol;
	}
	return sol;
};

void Sol::setEyeRecogImpl(Eye_Recog* e){

	eye_recog=e;
};


void Sol::setVoiceRecogImpl(Voice_Cmd_Recog* v){
	voice_recog = v;
};

void Sol::setGestureRecogImpl(Gesture_Recog* g){
	gesture_recog = g;
};


void Sol::startEventsListeners(){
	start_eye_recog_thread();
	
	start_voice_recog_thread();
	start_gesture_recog_thread();
};

void Sol::start_eye_recog_thread(){
	boost::thread eye_thread(&Sol::start_eye_recog,this);
	//eye_thread.join();

};

/// THIS METHOD SHOULD BE FIXED. WHILE LOOP SHOULD BE REMOVED !!!!!!!!!!!!!

void Sol::start_eye_recog(){
	eye_recog->startRecognition();
	
		 while (true)
   {
      boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
   
   }

};


void Sol::start_voice_recog_thread(){
	boost::thread voice_thread(&Sol::start_voice_recog,this);

};

void Sol::start_voice_recog(){
	voice_recog->startRecognition();
};


void Sol::start_gesture_recog_thread(){
	boost::thread gesture_thread(&Sol::start_gesture_recog,this);
//	gesture_thread.join();

};

void Sol::start_gesture_recog(){
	gesture_recog->startRecognition();
};


Sol::Sol(){};

Sol::~Sol(){};
