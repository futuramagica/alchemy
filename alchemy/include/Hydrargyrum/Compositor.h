// Compositor is layout of UI elements in Cube. 
// it operates also Space and Cube itself 
// it is singleton 

#ifndef COMPOSITOR_H
#define COMPOSITOR_H
#include "UIDataStructures.h"
#include "Sol\HMI_DataStruct.h"
#include "UIElement.h"
#include "ElementsList.h"

 

 

class Compositor {

public: 
	void makeMagic(); // refresh elements on UI. 
	static Compositor* getInstance();
	void initLayout();
	/// that is how i see events should be organized 
//	UIElement inFocus(eye_event* e); // searching if element was looked, if so call putInFocus to chnage structure and then draw() to reflect actual graphics  
	
//	int putInFocus(UIElement* e);
	
//	int actionVoice(UIElement* e); // in 1st phase will be called only when element will be in Focus. 
	
	//int actionGesture(UIElement* e);// not a phase one
	void addUIElement(UIElement* e);

	std::list<UIElement*> getElements();

	
	//init elements indicies in order to recognize them 
	void initElementsIndicies();

	// init rigid bodies based on collision shapes of the elements 
	void initdynamicsWorld();
	btDiscreteDynamicsWorld* getDynamics();


	void focusCheck();
	void setWindow(GLFWwindow* w);

protected: 
		
	void ScreenPosToWorldRay(
	int mouseX, int mouseY,             // Mouse position, in pixels, from bottom-left corner of the window
	int screenWidth, int screenHeight,  // Window size, in pixels
	glm::mat4 ViewMatrix,               // Camera position and orientation
	glm::mat4 ProjectionMatrix,         // Camera parameters (ratio, field of view, near and far planes)
	glm::vec3& out_origin,              // Ouput : Origin of the ray. /!\ Starts at the near plane, so if you want the ray to start at the camera's position instead, ignore this.
	glm::vec3& out_direction            // Ouput : Direction, in world space, of the ray that goes "through" the mouse.
	);

	 

private:
	Compositor();
	~Compositor();
	static Compositor* compositor;
	




	ui_elements ui_widget_container;

	// managing of world coordinates. 
	glm::mat4  projectionMatrix;
	glm::mat4  viewMatrix;
	GLFWwindow* window;
	
	// world dynamics used to manage 
	btDiscreteDynamicsWorld* dynamicsWorld;
};
#endif