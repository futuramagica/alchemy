#ifndef EVENTINTERFACE_H
#define EVENTINTERFACE_H
class EventInterface
{
public:
	virtual void OnEvent (int code)=0;
};
#endif