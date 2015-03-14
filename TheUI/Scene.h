#include "LinkedList.h"
#include "UIElement.h"
#include "Renderer.h"
class Scene
{
public:
	Scene();
	Scene(Renderer* r);
	void AddElement(UIElement* e);
	void Debug();
	void Draw();
	int ElementCount();
private:
	LinkedList<UIElement> Elements;
	Renderer* renderer;
};