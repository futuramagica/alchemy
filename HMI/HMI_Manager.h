#include "HMI_Interfaces.h"
#include <windows.h>

class HMI_Manager {

public: 
	HMI_Manager init();
	int relase();

	void setCmdRecogImpl(Voice_Cmd_Recog c);
	void setEyeRecogImpl(Eye_Recog e);

	int update_eye_struct(eye_event e);
	int update_voice_cmd_struct(voice_cmd_event c);
	
	HANDLE th_cmd_event; 
	HANDLE th_eye_event; 

private:
	HMI_Manager();
	~HMI_Manager();
	
	Eye_Recog eye_recog;
	Voice_Cmd_Recog cmd;
	
	eye_event eye;
	voice_cmd_event cmd_struct;
	
	

};


