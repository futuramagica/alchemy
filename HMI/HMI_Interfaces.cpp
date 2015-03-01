#include "HMI_Interfaces.h"
void Eye_Recog::callAction(float *x, float*y){
	(*action)(x,y);
};