#include "Hydrargyrum\Hydrargyrum.h"

Hydrargyrum* Hydrargyrum::hydrargyrum = NULL;

Hydrargyrum::Hydrargyrum(){

};

Hydrargyrum::~Hydrargyrum(){

};


Hydrargyrum* Hydrargyrum::getInstance(){
	if (hydrargyrum == NULL){
		hydrargyrum = new Hydrargyrum;
	}
	return hydrargyrum;
};
