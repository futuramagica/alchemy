#ifndef _INC_SOFTKINECTIMPL_H
#define _INC_SOFTKINECTIMPL_H

#include "Sol\HMI_Interfaces.h"
#include "SDK\iisuSDK.h"
#include <iostream>
#include <boost/thread/thread.hpp>

using namespace SK;
using namespace std;

class SoftKinectImpl: public Gesture_Recog{
public: 
	SoftKinectImpl();
	~SoftKinectImpl();


	void startRecognition();
	void stopRecognition();


	// softkinetic related routines 
	void init();
	void registerEvents();
	void run();

	void shutdown();

	void onClick(const ClickGestureEvent& event);


	 
	IisuHandle *	m_iisuHandle;
	Device *		m_device;
};

#endif