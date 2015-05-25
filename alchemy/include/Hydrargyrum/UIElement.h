#ifndef UIELEMENT_H
#define UIELEMENT_H
#include "UIDataStructures.h"


#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>


#include <stdlib.h>

#include "assimp\Importer.hpp"	
#include "assimp\PostProcess.h"
#include "assimp\Scene.h"

#include <map>


// is just a container for structure and logic of data structure change, while compositor is responsible for display it 
class UIElement 
{
public:
	UIElement();
	~UIElement();
	
	
	GLuint loadShaders(const char * vertex_file_path,const char * fragment_file_path);
	void loadModel(const char * path);
	void index_vertices();
	


	void init_ui_buffers();
	virtual void draw(glm::mat4 projectionMatrix, glm::mat4 viewMatrix) = 0; // draw specific element behaviour  
	
	
	
	ui_element getStructure();






protected:
	
	ui_element my_structure;
	
	virtual void initModelMatrix() = 0;


private: 
	void loadModel(const char * path, std::vector<glm::vec3> & out_vertices);
	// used for indexing 

	struct PackedVertex{
		glm::vec3 position;
		bool operator<(const PackedVertex that) const{
			return memcmp((void*)this, (void*)&that, sizeof(PackedVertex))>0;
		};
	};


	bool getSimilarVertexIndex_fast( 
		UIElement::PackedVertex & packed, 
		std::map<UIElement::PackedVertex,unsigned short> & VertexToOutIndex,
		unsigned short & result);


	void index_vertices(
		std::vector<glm::vec3> & in_vertices,
		std::vector<unsigned short> & out_indices,
		std::vector<glm::vec3> & out_vertices);

};

#endif