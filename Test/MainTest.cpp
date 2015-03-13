
#include <iostream>
#include <windows.h>
#include "EyeTribeImpl.h"
#include "SphinxRecogImpl.h"
#include "HMI_Manager.h" 



void actionEye		 (float *x, float *y);
void actionCmd (voice_cmd_t* cmd);


HMI_Manager hmi;
eye_event eye;
voice_cmd_event cmd;

int main(){


	hmi = HMI_Manager();
	eye.x=0;
	eye.y= 0;
	voice_cmd_t c=copy;
	cmd.voice_cmd = &c;

	EyeTribeImpl eyetr(actionEye);
	

	SphinxRecogImpl impl;
	impl.init_recog(actionCmd);
	impl.recognize_from_microphone();

	


	 while (true)
   {
      Sleep(2000);
      //here you also can write the output function e.g. cout <<  or printf, of course, under the precondition of predefined coordinates variable in your class
      printf( "\n-----------------------------------------------------\n" );
   }
	return 0;
}

void actionEye (float *x, float *y){

std::cout<<"X IS = "<<*x<<" Y IS = "<<*y;
eye.x=x;
eye.y=y;
hmi.update_eye_struct(eye);

};


void actionCmd (voice_cmd_t* c){

	std::cout<<"cmd  = "<<cmd.voice_cmd;
cmd.voice_cmd = c;
hmi.update_voice_cmd_struct(cmd);

}