#ifndef USERINPUT_H
#define USERINPUT_H
#include "scene.h"

class UserInput
{
protected:
	Scene* scene;
public:
	virtual void Listen();
	UserInput(Scene* s)
	{
		scene = s;
	}
	UserInput()
	{
	}
};
#endif