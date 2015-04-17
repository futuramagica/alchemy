#include "Prima\Prima.h"
#include "EyeTribeImpl.h"
#include "SphinxRecogImpl.h"
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#define BUFSIZE MAX_PATH
int main(){

	Prima* p = Prima::getInstance();

	EyeTribeImpl* eye = new EyeTribeImpl();
	p->setEye_Recog(eye);
	SphinxRecogImpl* voice = new SphinxRecogImpl();
	voice->init_recog();
	p->setVoice_Cmd_Recog(voice);

	p->init();


	
	system("pause");
	return 0;

}



