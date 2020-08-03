#pragma once
#include "../Utilities/utilities.h"
#include "Vertex.h"
#include <vector>

using namespace std;

class Model
{
private:
	vector<Vertex> m_vVertexList;
	vector<GLuint> m_vIndices;
	GLuint m_vboID;
	GLuint m_iboID;
	
public:
	GLuint GetVboID();
	GLuint GetIboID();
	
	vector<Vertex> GetVertexList();
	vector<GLuint> GetIndicesList();
	void LoadModel(char* fileLocation);
	void Init(char* fileLocation);
	Model();
	~Model();
};

