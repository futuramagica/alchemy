// this is entry point in all UI related routine
// single object 

#ifndef HYDRARGYRUM_H
#define HYDRARGYRUM_H
#include "Compositor.h";


class Hydrargyrum{

	public:	
		Hydrargyrum getInstance();


	private: 
		Hydrargyrum();
		~Hydrargyrum();

		Compositor* compositor;
};

#endif