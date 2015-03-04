#include "HMI_Interfaces.h"
void Eye_Recog::callEyeAction(float *x, float*y){
	(*action)(x,y);
}; 