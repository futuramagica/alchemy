#include <stdio.h>
#include "UserInput.h"
class DummyInput: public UserInput
{
public:
	DummyInput(Scene* s):UserInput( s)
	{
	}
	void Listen()
	{
		printf("Scene=%i\n",scene);
		scene->MouseOver(0,0);
	}
};