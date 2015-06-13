#include "Hydrargyrum\Hydrargyrum.h"
#include "Hydrargyrum\Floor.h"
#include "Hydrargyrum\CubicList.h"

int main(){

	



	Hydrargyrum* hyd = Hydrargyrum::getInstance();
	Compositor* c = Compositor::getInstance();
	
	hyd->setCompositor(c);
	hyd->initGraphics(); //this needs to go before any buffers initialization
	c->initLayout();
	c->setWindow(hyd->getWindow());

	Floor *f = new Floor();
 
	f->loadShaders("c:\\Users\\Oleg\\Documents\\Visual Studio 2010\\Projects\\alchemy\\alchemy\\Resources\\TransformVertexShader_floor.vertexshader",
		"c:\\Users\\Oleg\\Documents\\Visual Studio 2010\\Projects\\alchemy\\alchemy\\Resources\\TextureFragmentShader_floor.fragmentshader");


	f->loadModel("c:\\Users\\Oleg\\Documents\\Visual Studio 2010\\Projects\\alchemy\\alchemy\\Resources\\floor.3ds");
	c->addUIElement(f);
	f->index_vertices();
	f->initModelMatrix();
	f->initFocusShape();


	CubicList *cubicList = new CubicList();

	cubicList->loadShaders("c:\\Users\\Oleg\\Documents\\Visual Studio 2010\\Projects\\alchemy\\alchemy\\Resources\\TransformVertexShader_cubicList.vertexshader",
		"c:\\Users\\Oleg\\Documents\\Visual Studio 2010\\Projects\\alchemy\\alchemy\\Resources\\TextureFragmentShader_cubicList.fragmentshader");


	cubicList->loadModel("c:\\Users\\Oleg\\Documents\\Visual Studio 2010\\Projects\\alchemy\\alchemy\\Resources\\cubicList.3ds");
 	c->addUIElement(cubicList);
	cubicList->index_vertices();
	cubicList->initModelMatrix();
	cubicList->initFocusShape();

	hyd->initBuffers();

	c->initElementsIndicies();
	c->initdynamicsWorld();

	
	hyd->mainUILoop();
	//system("pause");
}