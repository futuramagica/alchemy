#include "Prima\Prima.h"
#include <stdio.h>
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
	
//	assert(Prima::voice!=NULL);
	assert(Prima::eye!=NULL);
//	assert(Prima::gesture!=NULL);
	
	
return 0;
};


int Prima::init(){
	
	initInternallComponents();
	checkReadiness();
	
	start();

	return 0;
};

int Prima::initInternallComponents(){
	
	sol = Sol::getInstance();
	hydrargyrum = Hydrargyrum::getInstance();
	event_Manager = Event_Manager::getInstance();
	
	ee = new EyeEvent(event_Manager);
	eye->setEyeEvent(ee);
	sol->setEyeRecogImpl(Prima::eye);


	return 0; 
};

void Prima::start(){
	sol->startEventsListeners();
	event_Manager->start_eye_to_hyd();
	//startEyeRecog();
	//int startGestureRecog();
	//int startVoiceRecog();


};



void Prima::stop(){

	


};



Eye_Recog* Prima::getEye_Recog(){
	return Prima::eye;
};

void Prima::setEye_Recog(Eye_Recog* e){
	Prima::eye=e;
};