#include "Sol\HMI_Manager.h"


int HMI_Manager::update_eye_struct(eye_event e){

	eye=e;
	return 0;
};


int HMI_Manager::update_voice_cmd_struct (voice_cmd_event c){
	
	cmd_event=c;
	return 0;
};

eye_event HMI_Manager::get_eye_event(){
return eye;
};

HMI_Manager::HMI_Manager(){};

HMI_Manager::~HMI_Manager(){};
