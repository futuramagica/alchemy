#ifndef USERINPUT_H
#define USERINPUT_H
#include "stdafx.h"
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