#include "SoftKinectImpl.h"


void SoftKinectImpl::startRecognition(){
	run();
};

void SoftKinectImpl::stopRecognition(){
	shutdown();
};

SoftKinectImpl::SoftKinectImpl():m_device(NULL),m_iisuHandle(NULL){
	
};

void SoftKinectImpl::init()
	{
		 

		string dllLocation = getenv("IISU_SDK_DIR") ;
		dllLocation+="/bin" ;

		// get the working context
		Context& context = Context::Instance();

		// create an iisu configuration
		IisuHandle::Configuration iisuConfiguration(dllLocation.c_str(),"iisu_config.xml");
	 

		// create the handle  
		Return<IisuHandle*> retHandle = context.createHandle(iisuConfiguration);
		if(retHandle.failed())
		{
			cerr << "Failed to get iisu handle!" << endl
				<< "Error " << retHandle.getErrorCode() << ": " << retHandle.getDescription().ptr() << endl;
			getchar();
			
		}
		// get the iisu handle
		m_iisuHandle = retHandle.get();

		//  device configuration
		Device::Configuration deviceConfiguration ;
		 

		// create the device  
		Return<Device*> retDevice = m_iisuHandle->initializeDevice(deviceConfiguration);
		if(retDevice.failed())
		{
			cerr << "Failed to create device!" << endl
				<< "Error " << retDevice.getErrorCode() << ": " << retDevice.getDescription().ptr() << endl;
			shutdown();
			getchar();
			
		}
		// get the device
		m_device = retDevice.get();
		
		//register events
		registerEvents();


		SK::Result devStart = m_device->start();
		if(devStart.failed())
		{
			cerr << "Failed to start device!" << endl
				<< "Error " << devStart.getErrorCode() << ": " << devStart.getDescription().ptr() << endl;
			getchar();
			
		}

	};



void SoftKinectImpl::registerEvents()
	{
		if (m_device==NULL || m_iisuHandle==NULL)
		{
			cerr << "iisu is not initialized" <<endl;
			getchar();
			
		}

		
		// enable gestures 
		 SK::ParameterHandle<bool> m_isActive;
		 m_isActive = m_device->registerParameterHandle<bool>("UI.CONTROLLERS.GESTURES.Enabled");
		 m_isActive.set(true);
 

		 
		if (!m_isActive.isValid())
		{
			cerr << "UI.CONTROLLERS.GESTURES.Enabled data registration failed" << endl;
			std::cout<<m_isActive.getErrorDescription()<<std::endl;
			getchar();
		}	


		 m_isActive = m_device->registerParameterHandle<bool>("UI.CONTROLLERS.GESTURES.CLICK.Enabled");
		 m_isActive.set(true);
 

		 
		if (!m_isActive.isValid())
		{
			cerr << "UI.CONTROLLERS.GESTURES.CIRCLE.Enabled data registration failed" << endl;
			std::cout<<m_isActive.getErrorDescription()<<std::endl;
			getchar();
		}	
		

		
		// enable swipe ----- for next releases
/* 
		m_isActive = m_device->registerParameterHandle<bool>("UI.CONTROLLERS.GESTURES.SWIPE.Enabled");
		m_isActive.set(true);
 
		if (!m_isActive.isValid())
		{
			cerr << "UI.CONTROLLERS.GESTURES.SWIPE.Enabled data registration failed" << endl;
			std::cout<<m_isActive.getErrorDescription()<<std::endl;
			getchar();
		}	

		//Result ret = m_iisuHandle->getEventManager().registerEventListener("UI.CONTROLLERS.GESTURES.SWIPE.Detected", *this, &Application::onSwipe); 
 */

		Result ret = m_iisuHandle->getEventManager().registerEventListener("UI.CONTROLLERS.GESTURES.CLICK.Detected", *this, &SoftKinectImpl::onClick);
		
		if (ret.failed()) 
		{
			cerr << "Failed to register for system error events!" << endl
				<< "Error " << ret.getErrorCode() << ": " << ret.getDescription().ptr() << endl;
			getchar();
			
		}



	};

	void SoftKinectImpl::onClick(const ClickGestureEvent& event)
	{
		std::cout << "CLICK x =  : " << event.getPosition().x << endl;
		gesture_event g;

		g.gesture = click;

		notifyChange(g);
	
	};

	void SoftKinectImpl::run()
	{
	
		

		if (m_device==NULL || m_iisuHandle==NULL)
		{
			cerr << "iisu is not initialized" <<endl;
			getchar();
			exit(0);
		}
		while(true)
		{
		// boost::this_thread::sleep_for(boost::chrono::milliseconds(10));
		}

		
	};


		//iisu shutdown and cleanup
	void SoftKinectImpl::shutdown()
	{
		// if we have iisu device
		if (m_device)
		{
			//stop iisu processing
			SK::Result devStop = m_device->stop();
			if(devStop.failed())
			{
				cerr << "Failed to stop device!" << endl
					<< "Error " << devStop.getErrorCode() << ": " << devStop.getDescription().ptr() << endl;
				getchar();
				exit(0);
			}
			
			// clear the device pointer
			m_device = NULL;
		}
		// if we have iisu handle
		if (m_iisuHandle)
		{
			
			// destroy the iisu handle
			SK::Result res = Context::Instance().destroyHandle(*m_iisuHandle);
			if(res.failed())
			{
				cerr << "Failed to destroy handle!" << endl
					<< "Error " << res.getErrorCode() << ": " << res.getDescription().ptr() << endl;
				getchar();
				exit(0);
			}

			// cleat the iisu handle
			m_iisuHandle = NULL;
		}

		// finalize context
		Context::Instance().finalize();
	};