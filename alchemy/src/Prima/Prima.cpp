#include "Prima\Prima.h"

#include "assert.h"

Prima* Prima::prima = NULL;


Prima::Prima(){
	sol = NULL;
	hydrargyrum=NULL;
	event_Manager=NULL;
	
	voice=NULL;
	eye=NULL;
	gesture=NULL;
};

Prima::~Prima(){
};



Prima* Prima::getInstance(){
	if (prima == NULL){
		prima = new Prima;
	}
	return prima;
};


int Prima::checkReadiness(){

	assert(Prima::sol!=NULL);
	assert(Prima::hydrargyrum!=NULL);
	assert(Prima::event_Manager!=NULL);
	
	assert(Prima::voice!=NULL);
	assert(Prima::eye!=NULL);
	assert(Prima::gesture!=NULL);
	
	
return 0;
};


int Prima::init(){
	
	initInternallComponents();
	checkReadiness();
	


	return 0;
};

int Prima::initInternallComponents(){
	
	sol = new Sol();
	hydrargyrum = Hydrargyrum::getInstance();
	event_Manager = Event_Manager::getInstance();



	return 0; 
};

void Prima::start(){

	int startEyeRecog();
	int startGestureRecog();
	int startVoiceRecog();


};



void Prima::stop(){

	int startEyeRecog();
	int startGestureRecog();
	int startVoiceRecog();


};

int Prima::startEyeRecog(){


	return 0;
};


int Prima::startGestureRecog(){


	return 0;
};


int Prima::startVoiceRecog(){


	return 0;

};

