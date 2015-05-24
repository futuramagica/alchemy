
#include "Hydrargyrum\UIElement.h"




UIElement::UIElement(){

};


UIElement::~UIElement(){

};


void UIElement::loadModel(const char * path){

	loadModel(path, (UIElement::my_structure.vertices));
};

// having issue with assimp reader - it is does not resolve relative filepaths - should be fixed asap!!!!!!!
void UIElement::loadModel(const char * path, 
	std::vector<glm::vec3> & out_vertices){

	Assimp::Importer importer;
	const aiScene *scene = importer.ReadFile(path,aiProcessPreset_TargetRealtime_Fast);//aiProcessPreset_TargetRealtime_Fast has the configs you'll need
 	
	aiMesh *mesh = scene->mMeshes[0]; //assuming you only want the first mesh
	for(int i=0;i<mesh->mNumFaces;i++){
		aiFace& face = mesh->mFaces[i];
		
		for(int j=0;j<3;j++){
	
			aiVector3D pos = mesh->mVertices[face.mIndices[j]];
			glm::vec3 tmp_v;
				tmp_v.x = pos.x;
				tmp_v.y = pos.y;
				tmp_v.z = pos.z;
				out_vertices.push_back(tmp_v);
		}
	}

};





GLuint UIElement::loadShaders(const char * vertex_file_path,const char * fragment_file_path){

	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if(VertexShaderStream.is_open()){
		std::string Line = "";
		while(getline(VertexShaderStream, Line))
			VertexShaderCode += "\n" + Line;
		VertexShaderStream.close();
	}else{
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
		getchar();
		return 0;
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if(FragmentShaderStream.is_open()){
		std::string Line = "";
		while(getline(FragmentShaderStream, Line))
			FragmentShaderCode += "\n" + Line;
		FragmentShaderStream.close();
	}



	GLint Result = GL_FALSE;
	int InfoLogLength;



	// Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}



	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}



	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);

	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> ProgramErrorMessage(InfoLogLength+1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);
	
	// this should be chnaged - keeep it in separate method 

	UIElement::my_structure.shaderID = ProgramID;
	UIElement::my_structure.MatrixID = glGetUniformLocation(UIElement::my_structure.shaderID, "MVP");

	return ProgramID;

};



void UIElement::init_ui_buffers(){

	glGenBuffers(1, &UIElement::my_structure.vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, UIElement::my_structure.vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, UIElement::my_structure.indexed_vertices.size() * sizeof(glm::vec3), &UIElement::my_structure.indexed_vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &UIElement::my_structure.elementbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, UIElement::my_structure.elementbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, UIElement::my_structure.indices.size() * sizeof(unsigned short), &UIElement::my_structure.indices[0] , GL_STATIC_DRAW);

};


void UIElement::index_vertices(
		std::vector<glm::vec3> & in_vertices,
		std::vector<unsigned short> & out_indices,
		std::vector<glm::vec3> & out_vertices){

std::map<UIElement::PackedVertex,unsigned short> VertexToOutIndex;

	// For each input vertex
	for ( unsigned int i=0; i<in_vertices.size(); i++ ){

		//PackedVertex packed = {in_vertices[i], in_uvs[i], in_normals[i]};
		PackedVertex packed = {in_vertices[i]};

		// Try to find a similar vertex in out_XXXX
		unsigned short index;
		bool found = UIElement::getSimilarVertexIndex_fast( packed, VertexToOutIndex, index);

		if ( found ){ // A similar vertex is already in the VBO, use it instead !
			out_indices.push_back( index );
		}else{ // If not, it needs to be added in the output data.
			out_vertices.push_back( in_vertices[i]);
			unsigned short newindex = (unsigned short)out_vertices.size() - 1;
			out_indices .push_back( newindex );
			VertexToOutIndex[ packed ] = newindex;
		}
	}

};


bool UIElement::getSimilarVertexIndex_fast( 
	UIElement::PackedVertex & packed, 
	std::map<UIElement::PackedVertex,unsigned short> & VertexToOutIndex,
	unsigned short & result){


std::map<UIElement::PackedVertex,unsigned short>::iterator it = VertexToOutIndex.find(packed);
	if ( it == VertexToOutIndex.end() ){
		return false;
	}else{
		result = it->second;
		return true;
	}

};


ui_element UIElement::getStructure(){

	return UIElement::my_structure;
};



void UIElement::index_vertices(){
	index_vertices(UIElement::my_structure.vertices,UIElement::my_structure.indices,UIElement::my_structure.indexed_vertices);
};