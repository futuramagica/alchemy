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




	Hydrargyrum::window = glfwCreateWindow( 1920, 1080, "Alchemy", glfwGetPrimaryMonitor(), NULL);
	
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
	glfwSetCursorPos(Hydrargyrum::window, 1024/2, 768/2);

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS); 
	
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);


	glEnable(GL_CULL_FACE);
	
	GLuint programID = LoadShaders( "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader" );
	
	GLuint programID2 = LoadShaders( "TransformVertexShader.vertexshader", "TextureFragmentShader_sec.fragmentshader" );

return 0;
};



int Hydrargyrum::initBuffers(){




return 0;
};