#pragma once
#include <iostream>
#include <windows.h>
#include "EyeTribeImpl.h"

void action (float *x, float *y);

int main(){

	EyeTribeImpl eyetr(action);
	


	 while (true)
   {
      Sleep(2000);
      //here you also can write the output function e.g. cout <<  or printf, of course, under the precondition of predefined coordinates variable in your class
      printf( "\n-----------------------------------------------------\n" );
   }
	return 0;
}

void action (float *x, float *y){

std::cout<<"X IS = "<<*x<<" Y IS = "<<*y;


}
