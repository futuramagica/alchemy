
#include <gazeapi.h>
#include "Sol\HMI_Interfaces.h"


class EyeTribeImpl: public Eye_Recog, public gtl::IGazeListener {
public: 

  EyeTribeImpl();
 ~EyeTribeImpl();

 void on_gaze_data( gtl::GazeData const &gazeData );
 void startRecognition();
 void stopRecognition();
private: 
	 gtl::GazeApi mApi;
};