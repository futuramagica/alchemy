
#include <gazeapi.h>
#include "HMI_Interfaces.h"


class EyeTribeImpl: public Eye_Recog, public gtl::IGazeListener {
public: 
// void recog();
 EyeTribeImpl(void(*action)(float *x, float *y));
 ~EyeTribeImpl();

 void on_gaze_data( gtl::GazeData const &gazeData );


private: 
	 gtl::GazeApi mApi;
};