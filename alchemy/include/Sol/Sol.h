#ifndef _INC_SOL
#define _INC_SOL

#include "HMI_Interfaces.h"
#include <windows.h>

#include <boost/thread/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/atomic.hpp>

class Sol {

public: 

	
	static Sol* getInstance();


	void startEventsListeners();


	int destroy();

	void setCmdRecogImpl(Voice_Cmd_Recog* c);
	void setEyeRecogImpl(Eye_Recog* e);

protected: 
	void start_eye_recog_thread();
	void start_eye_recog();

private:
	Sol();
	~Sol();

	static Sol* sol;

	Eye_Recog* eye_recog;
	Voice_Cmd_Recog cmd;
	
	eye_event eye;
	voice_cmd_event cmd_event;
	
	

};



#endif