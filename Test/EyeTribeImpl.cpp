#include "HMI_Interfaces.h"
#include "HMI_DataStruct.h"
#include <gazeapi.h>


class EyeTribeImpl: public Eye_Recog, public gtl::IGazeListener {
public: 
 void recog();
};

 void EyeTribeImpl::recog(){
	 
	/// here is routine 
	 
	  
}