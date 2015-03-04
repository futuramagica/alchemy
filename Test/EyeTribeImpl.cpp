#include <gazeapi.h>

#include <windows.h>
#include <iostream>

#include "EyeTribeImpl.h"

// void EyeTribeImpl::recog(){
	 
	// callAction();  
//}



EyeTribeImpl::EyeTribeImpl(void(*action)(float *x, float *y))
{
   if( mApi.connect( true ) )
   {
      mApi.add_listener( *this );
      if ( mApi.is_connected() )
      {
		  EyeTribeImpl::action = action;
         gtl::Screen screen;
         screen.set( 1, 1920, 1080, 0.5003, 0.2814 );
         mApi.set_screen( screen );
      }
   }
}


EyeTribeImpl::~EyeTribeImpl()
{
   mApi.remove_listener( *this );
   mApi.disconnect();
}


void EyeTribeImpl::on_gaze_data( gtl::GazeData const & gazeData )
{
   printf( "state = %d\n", gazeData.state );

   if( gazeData.state & gtl::GazeData::GD_STATE_TRACKING_GAZE )
   {
      gtl::Point2D const & smoothedCoordinates = gazeData.avg;
    
                // Move GUI point, do hit-testing, log coordinates, etc.

      Sleep(1000);
      gtl::Point2D const & smoothedCoordinatesLeftEye = gazeData.lefteye.avg; // smoothed data from left eye
      gtl::Point2D const & smoothedCoordinatesRightEye=gazeData.righteye.avg; // smoothed data from right eye

      //center values for left and right eyes, respectively.
      //std::cout << "x = " << (smoothedCoordinatesLeftEye.x+ smoothedCoordinatesRightEye.x)/2<< " y = " << (smoothedCoordinatesLeftEye.y+smoothedCoordinatesRightEye.y)/2 << endl;
	  float x = (smoothedCoordinatesLeftEye.x+ smoothedCoordinatesRightEye.x)/2;
	  float y = (smoothedCoordinatesLeftEye.y+smoothedCoordinatesRightEye.y)/2;
	Eye_Recog::callEyeAction( &x,  &y);// call graphics to change 

      printf( "\n" );
   }
}


