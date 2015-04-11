// Compositor is layout of UI elements in Cube. 
// it operates also Space and Cube itself 
// it is singleton 


#include "UIDataStructures.h"
class Compositor {

public: 
	int draw(); // refresh elements on UI. 
	Compositor getInstance();

	/// that is how i see events should be organized 
	UIElement inFocus(eye_event* e); // searching if element was looked, if so call putInFocus to chnage structure and then draw() to reflect actual graphics  
	
	int putInFocus(UIElement* e);
	
	int actionVoice(UIElement* e); // in 1st phase will be called only when element will be in Focus. 
	
	//int actionGesture(UIElement* e);// not a phase one


private:
	 Compositor();
	~Compositor();
	ui_elements elements;

}