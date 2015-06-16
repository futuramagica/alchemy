#include "Hydrargyrum\Compositor.h"
#include "Hydrargyrum\UIElement.h"


Compositor* Compositor::compositor = NULL;

Compositor* Compositor::getInstance(){
	if (compositor == NULL){
		compositor = new Compositor;
	}
	return compositor;
};


Compositor::Compositor(){
	
};

Compositor::~Compositor(){

};

void Compositor::makeMagic(){

	focusCheck();

	for (std::list<UIElement*>::iterator it = Compositor::ui_widget_container.elements.begin(); it != Compositor::ui_widget_container.elements.end(); it++){

			UIElement* ui = *it; 
			
			ui->draw(Compositor::projectionMatrix,Compositor::viewMatrix);


		}

	
};

void Compositor::addUIElement(UIElement* e){
	ui_widget_container.elements.push_back(e);
};

std::list<UIElement*> Compositor::getElements(){

	return ui_widget_container.elements;
};


void Compositor::initLayout(){

	 
	projectionMatrix = glm::perspective(90.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	
 	float horizontalAngle = 3.14f;
	float verticalAngle =0.0f;/// problems here 

	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle), 
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);

	glm::vec3 position = glm::vec3( 0.0, 10.0, 32.0 ); 

	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f/2.0 ), 
		0,
		cos(horizontalAngle - 3.14f/2.0 )
	);

	// Up vector
	glm::vec3 up = glm::cross( right, direction );

	viewMatrix =  glm::lookAt(
								position,           // Camera is here
								position+direction, // and looks here : at the same position, plus "direction"
								up                  // Head is up (set to 0,-1,0 to look upside-down)
						   );

		
	/*viewMatrix = glm::lookAt(
								glm::vec3(0.0f,0.0f,30.0f),           
								glm::vec3(0.0f,0.0f,0.0f), 
								glm::vec3(0.0f,-1.0f,0.0f)  
						   );*/
	
	 
};

void Compositor::ScreenPosToWorldRay(
	int mouseX, int mouseY,             // Mouse position, in pixels, from bottom-left corner of the window
	int screenWidth, int screenHeight,  // Window size, in pixels
	glm::mat4 ViewMatrix,               // Camera position and orientation
	glm::mat4 ProjectionMatrix,         // Camera parameters (ratio, field of view, near and far planes)
	glm::vec3& out_origin,              // Ouput : Origin of the ray. /!\ Starts at the near plane, so if you want the ray to start at the camera's position instead, ignore this.
	glm::vec3& out_direction            // Ouput : Direction, in world space, of the ray that goes "through" the mouse.
){

	/*glm::vec3 ray_start = glm::unProject(glm::vec3(mouseX, mouseY, 0.0), ViewMatrix, ProjectionMatrix, glm::vec4(0.0f, 0.0f, screenWidth, screenHeight));

	glm::vec3 ray_end = glm::unProject(glm::vec3(mouseX, mouseY, 1.0), ViewMatrix, ProjectionMatrix, glm::vec4(0.0f, 0.0f, screenWidth, screenHeight));


	float t =0.0f;
*/



	glm::vec4 lRayStart_NDC(
		((float)mouseX/(float)screenWidth  - 0.5f) * 2.0f, // [0,1024] -> [-1,1]
		((((float)mouseY/(float)screenHeight - 0.5f) * 2.0f ) *(-1.0f) ), // [0, 768] -> [-1,1]
		-1.0, // The near plane maps to Z=-1 in Normalized Device Coordinates
		1.0f
	);
	glm::vec4 lRayEnd_NDC(
		((float)mouseX/(float)screenWidth  - 0.5f) * 2.0f,
		((((float)mouseY/(float)screenHeight - 0.5f) * 2.0f) *(-1.0f)   ),
		0.0,
		1.0f
	);





	 
	// The Projection matrix goes from Camera Space to NDC.
	// So inverse(ProjectionMatrix) goes from NDC to Camera Space.
	glm::mat4 InverseProjectionMatrix = glm::inverse(ProjectionMatrix);
	
	// The View Matrix goes from World Space to Camera Space.
	// So inverse(ViewMatrix) goes from Camera Space to World Space.
	glm::mat4 InverseViewMatrix = glm::inverse(ViewMatrix);
	
	glm::vec4 lRayStart_camera = InverseProjectionMatrix * lRayStart_NDC;    
	lRayStart_camera/=lRayStart_camera.w;
	glm::vec4 lRayStart_world  = InverseViewMatrix       * lRayStart_camera; 
	lRayStart_world /=lRayStart_world .w;
	glm::vec4 lRayEnd_camera   = InverseProjectionMatrix * lRayEnd_NDC;      
	lRayEnd_camera  /=lRayEnd_camera  .w;
	glm::vec4 lRayEnd_world    = InverseViewMatrix       * lRayEnd_camera;   
	lRayEnd_world   /=lRayEnd_world   .w;




	glm::vec3 lRayDir_world(lRayEnd_world - lRayStart_world);
	lRayDir_world = glm::normalize(lRayDir_world);


	out_origin = glm::vec3(lRayStart_world);
	out_direction = glm::normalize(lRayDir_world);
};




void Compositor::focusCheck(){
		
	double lastTime = glfwGetTime();
	int nbFrames = 0;

	double currentTime = glfwGetTime();
		nbFrames++;
		if ( currentTime - lastTime >= 1.0 ){ // If last prinf() was more than 1sec ago
			// printf and reset
		//	printf("%f ms/frame\n", 1000.0/double(nbFrames));
			nbFrames = 0;
			lastTime += 1.0;
		}
		float deltaTime = currentTime - lastTime;

		// Step the simulation? In this example this won't do anything, 
		// since all the monkeys are static (mass = 0).
		 

		dynamicsWorld->stepSimulation(deltaTime, 7);


//	if (glfwGetMouseButton(Compositor::window, GLFW_MOUSE_BUTTON_LEFT)){
			
			glm::vec3 out_origin;
			glm::vec3 out_direction;
			
			double X;
			double Y;

			glfwGetCursorPos(Compositor::window, &X, &Y);

			int posX = (int) X; 
			int posY = (int) Y; 


 


			 ScreenPosToWorldRay(
				X, Y ,//+80,
				 1024, 768,
				Compositor::viewMatrix, 
				Compositor::projectionMatrix, 
				out_origin, 
				out_direction
			);	

			
			out_direction = out_direction*1000.0f;
		//	dynamicsWorld->debugDrawWorld();
			btCollisionWorld::ClosestRayResultCallback RayCallback(btVector3(out_origin.x, out_origin.y, out_origin.z), btVector3(out_direction.x, out_direction.y, out_direction.z));
			dynamicsWorld->rayTest(btVector3(out_origin.x, out_origin.y, out_origin.z), btVector3(out_direction.x, out_direction.y, out_direction.z), RayCallback);
			if(RayCallback.hasHit()) {
			
					int* i ;
					i = (int*) RayCallback.m_collisionObject->getUserPointer();
					printf(" DETECTED = %d \n" , i);

				if (Compositor::ui_widget_container.inFocus ==NULL){
						setFocus(i);
					    getElementbyIndex(i)->resizeElement(1.5f);
						getElementbyIndex(i)->resizeCollisionShape(1.5f);
				}

				if (Compositor::ui_widget_container.inFocus !=NULL){
						
					
					if (!((int *)Compositor::ui_widget_container.inFocus->getIndex()==i)){
					
					   Compositor::ui_widget_container.inFocus->resizeElement(12.0f/18.0f);
					   Compositor::ui_widget_container.inFocus->resizeCollisionShape(1.0f);
						setFocus(i);
						
					   Compositor::ui_widget_container.inFocus->resizeElement(1.5f);
					   Compositor::ui_widget_container.inFocus->resizeCollisionShape(1.5f);
					}

 				}

			}
			else {
			

				if (Compositor::ui_widget_container.inFocus != NULL){
					Compositor::ui_widget_container.inFocus->resizeElement(12.0f/18.0f);
					Compositor::ui_widget_container.inFocus->resizeCollisionShape(1.0f);
					Compositor::ui_widget_container.inFocus = NULL;
					printf("NO NULL DETECTED \n");
				}
				

				printf("NOT DETECTED \n");
			}
			
				
			
			
	//}
};

void Compositor::setWindow(GLFWwindow* w){
	Compositor::window=w;
};

void Compositor::initElementsIndicies(){
	int index = 0;
	Compositor::ui_widget_container.inFocus =NULL;
	for (std::list<UIElement*>::iterator it = Compositor::ui_widget_container.elements.begin(); it != Compositor::ui_widget_container.elements.end(); it++){
			index++;
			int i = index ;
			UIElement* ui = *it; 
			ui->setIndex(i);
	}
};

void Compositor::initdynamicsWorld(){

	


	btBroadphaseInterface* broadphase = new btDbvtBroadphase();
 
	
	btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
	btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);
 
	btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;
 
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
	dynamicsWorld->setGravity(btVector3(0,-9.81f,0));

	std::vector<btRigidBody*> rigidbodies;

	

	for (std::list<UIElement*>::iterator it = Compositor::ui_widget_container.elements.begin(); it != Compositor::ui_widget_container.elements.end(); it++){


	UIElement* ui = *it;
		btDefaultMotionState* motionstate = new btDefaultMotionState(	btTransform(
			btQuaternion(ui->getStructure().orientation.x, ui->getStructure().orientation.y, ui->getStructure().orientation.z, ui->getStructure().orientation.w), 
			btVector3(ui->getStructure().position.x, ui->getStructure().position.y, ui->getStructure().position.z)
		)
);


		btConvexHullShape* cs = ui->getStructure().collisionShape;

		btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(
			0,                  // mass, in kg. 0 -> Static object, will never move.
			motionstate,
			cs,  // collision shape of body
			btVector3(0,0,0)    // local inertia
		);
		btRigidBody *rigidBody = new btRigidBody(rigidBodyCI);

		rigidbodies.push_back(rigidBody);
		dynamicsWorld->addRigidBody(rigidBody);

		// Small hack : store the mesh's index "i" in Bullet's User Pointer.
		// Will be used to know which object is picked. 
		// A real program would probably pass a "MyGameObjectPointer" instead.

		//printf ("ELEMENT INDEX SET TO = %d \n", ui->getIndex());
		rigidBody->setUserPointer((int*)ui->getIndex());

	}



};

btDiscreteDynamicsWorld* Compositor::getDynamics(){
	return dynamicsWorld;
};


void Compositor::setFocus(int* index){

	for (std::list<UIElement*>::iterator it = Compositor::ui_widget_container.elements.begin(); it != Compositor::ui_widget_container.elements.end(); it++){
	
			UIElement* ui = *it; 

			if ((int *)ui->getIndex()==index){
				Compositor::ui_widget_container.inFocus = *it;
				printf("DETECTED SET = %d \n", Compositor::ui_widget_container.inFocus->getIndex());
			}
			
	}

};



UIElement* Compositor::getElementbyIndex(int* index){

	for (std::list<UIElement*>::iterator it = Compositor::ui_widget_container.elements.begin(); it != Compositor::ui_widget_container.elements.end(); it++){
	
			UIElement* ui = *it; 

			if ((int *)ui->getIndex()==index) 
				return *it;
	}
	return NULL;
	
};