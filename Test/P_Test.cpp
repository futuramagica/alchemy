#include "Prima\Prima.h"
#include "EyeTribeImpl.h"
#include <stdio.h>

int main(){

	Prima* p = Prima::getInstance();

	EyeTribeImpl* eye = new EyeTribeImpl();
	p->setEye_Recog(eye);
	p->init();

	system("pause");
	return 0;

}



