#include "Sol\Event_Manager.h"

Event_Manager* Event_Manager::event_Manager = NULL;

Event_Manager::Event_Manager(){
	eye_event_q = new boost::lockfree::queue<eye_event>(300);
};


Event_Manager::~Event_Manager(){

};


Event_Manager* Event_Manager::getInstance(){

	if (event_Manager == NULL){
		event_Manager = new Event_Manager();
	}
	return event_Manager;

};



eye_event Event_Manager::eye_event_q_pop(){
	
	eye_event e;
	e.x=-1;
	e.y=-1;
	if (!eye_event_q->empty())
		eye_event_q->pop(e);
	return e;
};

void Event_Manager::eye_event_q_push(eye_event e){
	eye_event_q->push(e);
	printf("PUSH: X=%f Y=%f \n",e.x,e.y);
};

void Event_Manager::start_eye_to_hyd(){

	eye_to_hyd_t = new boost::thread(&Event_Manager::push_eye_to_hyd,this);
	eye_to_hyd_t->join();
};

void Event_Manager::push_eye_to_hyd(){
	printf("POP  STARTED      ------------------------------------------ \n");
	while (true){
		
		eye_event* e;
		e=&eye_event_q_pop();
	//hyd->eye_event(eye_event_q_pop());
		boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
		printf("POP: X=%f Y=%f \n",e->x,e->y);
	}
	
	

};


