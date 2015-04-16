#include "Sol\HMI_Interfaces.h"

void Eye_Recog::notifyChange (eye_event e){
	
	eyeEvent->update(e);
};


void Eye_Recog::setEyeEvent(EyeEvent* ee){

	eyeEvent = ee;

};


