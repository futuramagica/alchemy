#include "LinkedList.h"
#include "UIElement.h"
class Scene
{
public:
	Scene();
	void AddElement(UIElement* e);
	void Debug();
private:
	LinkedList<UIElement> Elements;
};