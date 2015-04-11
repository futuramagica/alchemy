#include "Sol\Sol.h"


int Sol::update_eye_struct(eye_event e){

	eye=e;
	return 0;
};


int Sol::update_voice_cmd_struct (voice_cmd_event c){
	
	cmd_event=c;
	return 0;
};

eye_event Sol::get_eye_event(){
return eye;
};

Sol::Sol(){};

Sol::~Sol(){};
