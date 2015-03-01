#include "EventManager.h"
#include "HMI_Manager.h"

class Platform {

public: 
	int init();
	void setEventManager(EventManager e);
	void setHMIManager(HMI_Manager h);



private: 
	Platform();
	~Platform();

	EventManager event_manager;
	HMI_Manager hmi_manager;

}