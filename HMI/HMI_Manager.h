#include "HMI_Interfaces.h"


class HMI_Manager {

public: 
	HMI_Manager init();
	int relase();

	void setEyeRecogImpl(Eye_Recog e);

private:
	HMI_Manager();
	~HMI_Manager();
	
	Eye_Recog eye_recog;

}


