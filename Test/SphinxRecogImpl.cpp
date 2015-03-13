#include "SphinxRecogImpl.h";

//ps_decoder_s * SphinxRecogImpl::ps = NULL;
//cmd_ln_s * SphinxRecogImpl::config = NULL;

void SphinxRecogImpl::init_recog(void(*act)(voice_cmd_t*)){

	config = cmd_ln_init(NULL, ps_args(), TRUE,
			     "-hmm", "c:\\Users\\Oleg\\Documents\\Development\\sphinx\\pocketsphinx\\model\\en-us\\en-us",
			     "-lm", "c:\\Users\\Oleg\\Documents\\Development\\sphinx\\pocketsphinx\\model\\en-us\\en-us.lm.dmp",
			     "-dict","c:\\Users\\Oleg\\Documents\\Development\\sphinx\\pocketsphinx\\model\\en-us\\cmudict-en-us.dict",
			     NULL);
        
	if (config == NULL)
	    ps_default_search_args(config);
	
	ps = ps_init(config);
    if (ps == NULL) {
        cmd_ln_free_r(config);
    }

	setCallVoiceAction(act);

};


 void SphinxRecogImpl::recognize_from_microphone()
{

    ad_rec_t *ad;
    int16 adbuf[2048];
    uint8 utt_started, in_speech;
    int32 k;
    char const *hyp;

    if ((ad = ad_open_dev(cmd_ln_str_r(config, "-adcdev"),
                          (int) cmd_ln_float32_r(config,
                                                 "-samprate"))) == NULL)
        E_FATAL("Failed to open audio device\n");
    if (ad_start_rec(ad) < 0)
        E_FATAL("Failed to start recording\n");

    if (ps_start_utt(ps) < 0)
        E_FATAL("Failed to start utterance\n");
    utt_started = FALSE;
    printf("READY....\n");

    for (;;) {
        if ((k = ad_read(ad, adbuf, 2048)) < 0)
            E_FATAL("Failed to read audio\n");
        ps_process_raw(ps, adbuf, k, FALSE, FALSE);
        in_speech = ps_get_in_speech(ps);
        if (in_speech && !utt_started) {
            utt_started = TRUE;
            printf("Listening...\n");
        }
        if (!in_speech && utt_started) {
            /* speech -> silence transition, time to start new utterance  */
            ps_end_utt(ps);
            hyp = ps_get_hyp(ps, NULL );
            if (hyp != NULL){
                printf("%s\n", hyp);
			
				if (strcmp(hyp, "copy")==0){
					cmd = copy;
					callVoiceAction(&cmd);
				}
				
			}


            if (ps_start_utt(ps) < 0)
                E_FATAL("Failed to start utterance\n");
            utt_started = FALSE;
            printf("READY....\n");
        }
        Sleep(100);
    }
    ad_close(ad);
};