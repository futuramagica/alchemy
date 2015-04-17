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



void Sol::startEventsListeners(){
	start_eye_recog_thread();
	start_voice_recog_thread();
};

void Sol::start_eye_recog_thread(){
	boost::thread eye_thread(&Sol::start_eye_recog,this);
	//eye_thread.join();

};

void Sol::start_eye_recog(){
	eye_recog->startRecognition();
	
	while (true)
   {
      boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
      //here you also can write the output function e.g. cout <<  or printf, of course, under the precondition of predefined coordinates variable in your class
     // printf( "\n-----------------------------------------------------\n" );
   }
};


void Sol::start_voice_recog_thread(){
	boost::thread voice_thread(&Sol::start_voice_recog,this);

};

void Sol::start_voice_recog(){
	voice_recog->startRecognition();
};

Sol::Sol(){};

Sol::~Sol(){};
