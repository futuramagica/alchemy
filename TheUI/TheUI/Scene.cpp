#include "stdafx.h"
#include "Scene.h"
Scene::Scene()
{
	

}
void Scene::AddElement(UIElement* e)
	{
		Elements.AddElement(e);
	}
 void Scene::Debug()
{
	UIElement* e=Elements.Last();
	e->Display();
}