#include "stdafx.h"
#include "Scene.h"
Scene::Scene()
{


}
void Scene::AddElement(UIElement* e)
	{
		printf("%i",&Elements);
		Elements.AddElement(e);
	}
 void Scene::Debug()
{
	

}
Scene::Scene(Renderer* r)
 {
	 renderer=r;

 }
void Scene::Draw()
{
	printf("Scene::Draw()\n");
	for (int i=0;i<Elements.Size();i++)
	{
		printf("%i\n",i);
		UIElement* current=Elements.Next();
		printf("%i\n",current);
		current->Draw(renderer);
	}
}
int Scene::ElementCount()
{
	return Elements.Size();
}