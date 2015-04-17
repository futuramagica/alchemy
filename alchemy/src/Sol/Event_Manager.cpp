#include "Sol\Event_Manager.h"

Event_Manager* Event_Manager::event_Manager = NULL;

Event_Manager::Event_Manager(){
	eye_event_q = new boost::lockfree::queue<eye_event>(50);
	voice_event_q = new boost::lockfree::queue<voice_cmd_event>(50);
};


Event_Manager::~Event_Manager(){

};


Event_Manager* Event_Manager::getInstance(){

	if (event_Manager == NULL){
		event_Manager = new Event_Manager();
	}
	return event_Manager;

};

// eye event routine 
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
	//printf("PUSH: X=%f Y=%f \n",e.x,e.y);
};

void Event_Manager::start_eye_to_hyd(){

	eye_to_hyd_t = new boost::thread(&Event_Manager::push_eye_to_hyd,this);
	//eye_to_hyd_t->join();
};

void Event_Manager::push_eye_to_hyd(){
	//printf("POP  STARTED      ------------------------------------------ \n");
	while (true){
		
		eye_event* e;
		e=&eye_event_q_pop();
	//hyd->eye_event(eye_event_q_pop());
		boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
		printf("POP: X=%f Y=%f \n",e->x,e->y);
	}
};



// voice event routines 
void Event_Manager::start_voice_to_hyd(){
	
	voice_to_hyd_t = new boost::thread(&Event_Manager::push_voice_to_hyd,this);
	//voice_to_hyd_t->join();
};


voice_cmd_event Event_Manager::voice_event_q_pop(){

	voice_cmd_event v;
	v.voice_cmd = none;
	
	if (!voice_event_q->empty())
		voice_event_q->pop(v);
	return v;
};

void Event_Manager::push_voice_to_hyd(){
	
	while (true){
		
		voice_cmd_event* v;
		v=&voice_event_q_pop();
		//hyd->voice_event(eye_event_q_pop()); // to push 
		boost::this_thread::sleep_for(boost::chrono::milliseconds(10));


					
			if (v->voice_cmd==reply){
					 printf("POPU UP -------->>>>>> REPLY \n");
			}
			if (v->voice_cmd==sel){
					 printf("POPU UP -------->>>>>> SELECT \n");
				}
			if (v->voice_cmd==close){
					 printf("POPU UP -------->>>>>> CLOSE \n");
				}
			if (v->voice_cmd==forward){
					 printf("POPU UP -------->>>>>> Forward \n");
				}
			



		//printf("POP: X=%f Y=%f \n",e->x,e->y);
	}
};
void Event_Manager::voice_event_q_push(voice_cmd_event v){

	voice_event_q->push(v);
	//printf("PUSH: X=%f Y=%f \n",e.x,e.y);
};