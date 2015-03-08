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


class SphinxRecogImpl {

public: 
	
	SphinxRecogImpl();
	~SphinxRecogImpl();

	static void init_recog();
	static void recognize_from_microphone();

	static	 ps_decoder_t *ps;
	static	cmd_ln_t *config;

};

