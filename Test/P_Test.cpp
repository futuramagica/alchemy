#include "Prima\Prima.h"
#include "EyeTribeImpl.h"
#include "SphinxRecogImpl.h"
#include "SoftKinectImpl.h"
//#include <SDK/iisuSDK.h>
//#include <stdio.h>
//#include <tchar.h>




#define BUFSIZE MAX_PATH
int main(){

	Prima* p = Prima::getInstance();

	EyeTribeImpl* eye = new EyeTribeImpl();
	p->setEye_Recog(eye);

	SphinxRecogImpl* voice = new SphinxRecogImpl();
	voice->init_recog();
	p->setVoice_Cmd_Recog(voice);

	SoftKinectImpl* sk = new SoftKinectImpl();
	sk->init();

	p->setGesture_Recog(sk);

	p->init();


	
	system("pause");
	return 0;

}



