#include "Prima\Prima.h"


Prima* Prima::prima = NULL;

Prima* Prima::getInstance(){
	if (prima == NULL){
		prima = new Prima();
	}
	return prima;
};