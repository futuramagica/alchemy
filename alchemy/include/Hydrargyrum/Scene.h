#ifndef SCENE_H
#define SCENE_H
#include "LinkedList.h"
#include "UIElement.h"
#include "Renderer.h"
class Scene
{
public:
	Scene();
	Scene(Renderer* r);
	Scene(Renderer* r, int w, int h);
	void AddElement(UIElement* e);
	void Debug();
	void Draw();
	int ElementCount();
	void MouseOver(int x, int y);
private:
	LinkedList<UIElement> Elements;
	Renderer* renderer;
	int width;
	int height;
};
#endif