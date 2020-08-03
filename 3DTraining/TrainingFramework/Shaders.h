#pragma once
#include "../Utilities/utilities.h"

class Shaders 
{

public:
	GLuint m_program, m_vertexShader, m_fragmentShader;
	GLint m_positionAttribute;
	GLint m_uniformLocation;
	GLint m_uvAttribute;
	GLint m_WVP;

	int Init(char * fileVertexShader, char * fileFragmentShader);
	~Shaders();
};