// works as intermediate for processing events and makign sure all event completed before bew come in. 
// might be used threads here and Qs of pending events with some logic of expiration- but that is for next phases 
// singleton class 

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "Hydrargyrum\Hydrargyrum.h"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/atomic.hpp>

/// unknown issue with boost 
namespace boost {
    struct thread::dummy {};
}

class Event_Manager {

public: 
	static Event_Manager* getInstance();

	// eye updates routines 
	void start_eye_to_hyd();
	eye_event eye_event_q_pop();
	void eye_event_q_push(eye_event e);

	// voice updates routines 
	void start_voice_to_hyd();
	voice_cmd_event voice_event_q_pop();
	void voice_event_q_push(voice_cmd_event v);

private: 

	Event_Manager(); 
	~Event_Manager();
	


	void push_eye_to_hyd();
	
	void push_voice_to_hyd();

	boost::lockfree::queue<eye_event>* eye_event_q; // eye q
	boost::thread* eye_to_hyd_t;

	boost::lockfree::queue<voice_cmd_event>* voice_event_q; // voice q
	boost::thread* voice_to_hyd_t;
	
	
	static Event_Manager* event_Manager;

	Hydrargyrum* hyd;

};
#endif