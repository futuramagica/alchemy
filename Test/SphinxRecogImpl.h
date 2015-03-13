#include <stdio.h>
#include <string.h>
#include <assert.h>

#if defined(_WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#else
#include <sys/select.h>
#endif

#include <sphinxbase/err.h>
#include <sphinxbase/ad.h>

#include "pocketsphinx.h"
#include "HMI_Interfaces.h"

class SphinxRecogImpl : public Voice_Cmd_Recog{

public: 
	
	
	
	 void init_recog(void(*act)(voice_cmd_t*));
	 void recognize_from_microphone();

	ps_decoder_t *ps;
	cmd_ln_t *config;
	
	voice_cmd_t cmd;
};

