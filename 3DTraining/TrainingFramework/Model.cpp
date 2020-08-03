#include "stdafx.h"
#include "Model.h"



Model::Model()
{
}


Model::~Model()
{
}

void Model::Init(char* fileLocation)
{
	LoadModel(fileLocation);
}

void Model::LoadModel(char* fileLocation)
{
	FILE *p = fopen(fileLocation, "r");
	//vertices
	int iNumVertices;
	fscanf(p, "NrVertices: %d\n", &iNumVertices);
	
	for(int i = 0; i< iNumVertices; i++)
	{
		Vector3 vPos, vNorm, vBinorm, vTgt;
		Vector2 vUv;
		Vertex vTemp;
		fscanf(p, " %*d. pos:[%f, %f, %f]; norm:[%f, %f, %f]; binorm:[%f, %f, %f]; tgt:[%f, %f, %f]; uv:[%f, %f];\n",
			&vPos.x, &vPos.y, &vPos.z, &vNorm.x, &vNorm.y, &vNorm.z, &vBinorm.x, &vBinorm.y, &vBinorm.z, &vTgt.x, &vTgt.y, &vTgt.z, &vUv.x, &vUv.y);
	
		vTemp.pos = vPos;
		vTemp.binormal = vBinorm;
		vTemp.normal = vNorm;
		vTemp.tangent = vTgt;
		vTemp.uv = vUv;

		m_vVertexList.push_back(vTemp);
	}
	//indices
	int iNumIndices;
	fscanf(p, "NrIndices: %d\n", &iNumIndices);
	for (int i = 0; i< iNumIndices; i+=3)
	{
		GLuint uiTemp[3]{};
		fscanf(p, " %*d.    %d,    %d,    %d\n", &uiTemp[0], &uiTemp[1], &uiTemp[2]);

		m_vIndices.push_back(uiTemp[0]);
		m_vIndices.push_back(uiTemp[1]);
		m_vIndices.push_back(uiTemp[2]);

	}
	fclose(p);

	//buffer object
	glGenBuffers(1, &m_vboID);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
	glBufferData(GL_ARRAY_BUFFER, m_vVertexList.size() * sizeof(Vertex), &m_vVertexList[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &m_iboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_vIndices.size() * sizeof(GLint), &m_vIndices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	
}


GLuint Model::GetVboID()
{
	return m_vboID;
}
GLuint Model::GetIboID()
{
	return m_iboID;
}

vector<Vertex> Model::GetVertexList()
{
	return m_vVertexList;
}
vector<GLuint> Model::GetIndicesList()
{
	return m_vIndices;
}