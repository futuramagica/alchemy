#include "Hydrargyrum\Hydrargyrum.h"




Hydrargyrum* Hydrargyrum::hydrargyrum = NULL;

Hydrargyrum::Hydrargyrum(){

};

Hydrargyrum::~Hydrargyrum(){

};


Hydrargyrum* Hydrargyrum::getInstance(){
	if (hydrargyrum == NULL){
		hydrargyrum = new Hydrargyrum;
	}
	return hydrargyrum;
};

int Hydrargyrum::initGraphics(){

	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}


	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	//glfwCreateWindow( 1024, 768, "Alchemy", NULL, NULL);

	Hydrargyrum::window  = glfwCreateWindow( 1920, 1080, "Alchemy", glfwGetPrimaryMonitor(), NULL);
	
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return -1;
	}


	glfwMakeContextCurrent(window);

	glewExperimental = true; // Needed for core profile

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	glfwSetInputMode(Hydrargyrum::window, GLFW_STICKY_KEYS, GL_TRUE);
	//glfwSetCursorPos(Hydrargyrum::window, 1024/2, 768/2);

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS); 
	//glEnable(GL_CULL_FACE);
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);


 
	

return 0;
};



int Hydrargyrum::initBuffers(){


	std::list<UIElement*> el_list = compositor->getElements();

	printf ("Elements size = %d", el_list.size());
	
	for (std::list<UIElement*>::iterator it = el_list.begin(); it != el_list.end(); it++){
		
		UIElement* ui = *it; 
		
		ui->init_ui_buffers();
	}
	
return 0;
};


void Hydrargyrum::setCompositor(Compositor* c){

	Hydrargyrum::compositor = c;
};

void Hydrargyrum::mainUILoop(){

	

	
	
	do
	{

		


	 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT  );

			compositor->makeMagic();
					 
		glfwSwapBuffers(Hydrargyrum::window);
		glfwPollEvents();
			 
	}
	while( glfwGetKey(Hydrargyrum::window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(Hydrargyrum::window) == 0 );

//	Hydrargyrum::clear();

};



void Hydrargyrum::clear(){

for (std::list<UIElement*>::iterator it = Hydrargyrum::compositor->getElements().begin(); it != Hydrargyrum::compositor->getElements().end(); it++){


			UIElement* ui = *it; 
			GLuint vertexbuffer = ui->getStructure().vertexbuffer;
			glDeleteBuffers(1, &vertexbuffer);
			//glDeleteBuffers(1, &uvbuffer);
			//glDeleteBuffers(1, &normalbuffer);
			GLuint elementbuffer = ui->getStructure().elementbuffer;
			glDeleteBuffers(1, &elementbuffer);
			glDeleteProgram(ui->getStructure().shaderID);
			//glDeleteTextures(1, &Texture);
			//glDeleteVertexArrays(1, &VertexArrayID); /// this should be corrected !!!!!!!!!!!!!!

		}

};



GLFWwindow* Hydrargyrum::getWindow(){

	return Hydrargyrum::window;
};