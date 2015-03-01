struct eye_event{
	int x;
	int y;
}

enum gesture_t {select, wave_up, wave_down, wave_left, wave_right};

struct gesture_event{
	gesture_t gesture;
}

enum voice_cmd_t {start,stop,select, drop, cut, copy, paste, use};

struct voice_cmd_event{
	voice_cmd_t voice_cmd;
}