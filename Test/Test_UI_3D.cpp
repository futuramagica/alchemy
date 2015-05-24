#include "Hydrargyrum\Hydrargyrum.h"
#include "Hydrargyrum\Floor.h"

int main(){

	Hydrargyrum* hyd = Hydrargyrum::getInstance();
	Compositor* c = Compositor::getInstance();
	
	hyd->setCompositor(c);
	hyd->initGraphics(); //this needs to go before any buffers initialization


	Floor *f = new Floor();

	f->loadShaders("c:\\Users\\Oleg\\Documents\\Visual Studio 2010\\Projects\\alchemy\\alchemy\\Resources\\TransformVertexShader_floor.vertexshader",
		"c:\\Users\\Oleg\\Documents\\Visual Studio 2010\\Projects\\alchemy\\alchemy\\Resources\\TextureFragmentShader_floor.fragmentshader");


	f->loadModel("c:\\Users\\Oleg\\Documents\\Visual Studio 2010\\Projects\\alchemy\\alchemy\\Resources\\floor.3ds");
	c->addUIElement(f);
	f->index_vertices();	
	hyd->initBuffers();
	hyd->mainUILoop();
	//system("pause");
}