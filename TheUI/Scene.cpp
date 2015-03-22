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
Scene::Scene(Renderer* r, int w, int h)
{
	renderer=r;
	width=w;
	height=h;
}
void Scene::Draw()
{
	//printf("Scene::Draw()\n");
	for (int i=0;i<Elements.Size();i++)
	{
		//printf("%i\n",i);
		UIElement* current=Elements.Next();
		//printf("%i\n",current);
		current->Draw(renderer);
	}
}
int Scene::ElementCount()
{
	return Elements.Size();
}
void Scene::MouseOver(int x, int y)
{
	printf("mouseover at %i, %i\n",x,y);
	int relativeX=x-width/2;
	int relativeY=y-height/2;
	if ((x>=0)&&(x<=width)&&(y>=0)&&(y<=width))
	{
		for (int i=0;i<Elements.Size();i++)
		{
			UIElement* current=Elements.Next();
			RectangleInfo* ri = current->getRect();
			/*printf("inside Draw() : x=%i,y=%i,width=%i,height=%i\n",ri->x,ri->y,ri->width,ri->height);
			printf("Address: %p\n",ri);
			printf("%i\n",renderer->WithinRectangle(ri,x,y));*/
			if ((relativeX>=ri->x)&&(relativeY>=ri->y)&&(relativeX<=ri->x+ri->width)&&(relativeY<=ri->height+ri->y))
			{
				printf("Match for x=%i,y=%i!\n",x,y);
				//system("pause");
				current->MouseOver(relativeX,relativeY);
			}
			else
			{
				if (current->highlighted)
				{
					current->highlighted=false;
				}
			}
		}
	}
}