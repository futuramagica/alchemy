#include "Sol\Event_Manager.h"

Event_Manager* Event_Manager::event_Manager = NULL;

Event_Manager::Event_Manager(){
	eye_event_q = new boost::lockfree::queue<eye_event>(50);
	voice_event_q = new boost::lockfree::queue<voice_cmd_event>(50);
	gesture_event_q = new boost::lockfree::queue<gesture_event>(50);
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
	printf("start_eye_to_hyd()      ------------------------------------------ \n");
	eye_to_hyd_t = new boost::thread(&Event_Manager::push_eye_to_hyd,this);
	//eye_to_hyd_t->join();
};

void Event_Manager::push_eye_to_hyd(){
	
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
	v.voice_cmd = no_voice;
	
	if (!voice_event_q->empty())
		voice_event_q->pop(v);
	return v;
};

void Event_Manager::push_voice_to_hyd(){
	
	while (true){
		
		voice_cmd_event* v;
		v=&voice_event_q_pop();
		//hyd->voice_event(eye_event_q_pop()); // to push 
		


					
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
			

			boost::this_thread::sleep_for(boost::chrono::milliseconds(10));

		//printf("POP: X=%f Y=%f \n",e->x,e->y);
	}
};
void Event_Manager::voice_event_q_push(voice_cmd_event v){

	voice_event_q->push(v);
	//printf("PUSH: X=%f Y=%f \n",e.x,e.y);
};




// gesture routine 
void Event_Manager::start_gesture_to_hyd(){
	
	gesture_to_hyd_t = new boost::thread(&Event_Manager::push_gesture_to_hyd,this);
	
};


gesture_event Event_Manager::gesture_event_q_pop(){

	gesture_event g;
	g.gesture = no_gesture;
	
	if (!gesture_event_q->empty())
		gesture_event_q->pop(g);
	return g;
};

void Event_Manager::push_gesture_to_hyd(){
	
	while (true){
		
		gesture_event* g;
		g=&gesture_event_q_pop();
		//hyd->gesture_event(eye_event_q_pop()); // to push 
		


					
			if (g->gesture==click){
					 printf("POPU UP GESTURE -------->>>>>> CLICK \n");
			}
			if (g->gesture==move){
					 printf("POPU UP GESTURE -------->>>>>> MOVE \n");
				}

boost::this_thread::sleep_for(boost::chrono::milliseconds(10));
		//printf("POP: X=%f Y=%f \n",e->x,e->y);
	}
};
void Event_Manager::gesture_event_q_push(gesture_event g){

	gesture_event_q->push(g);

};