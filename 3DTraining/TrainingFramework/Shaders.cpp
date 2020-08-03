#include "stdafx.h"
#include "Shaders.h"

int Shaders::Init(char * fileVertexShader, char * fileFragmentShader)
{
	m_vertexShader = esLoadShader(GL_VERTEX_SHADER, fileVertexShader);

	if (m_vertexShader == 0 )
		return -1;

	m_fragmentShader = esLoadShader(GL_FRAGMENT_SHADER, fileFragmentShader);

	if (m_fragmentShader == 0 )
	{
		glDeleteShader(m_vertexShader );
		return -2;
	}

	m_program = esLoadProgram(m_vertexShader, m_fragmentShader);

	//finding location of uniforms / attributes
	m_positionAttribute = glGetAttribLocation(m_program, "a_posL");
	m_uvAttribute = glGetAttribLocation(m_program, "a_uv");
	m_uniformLocation = glGetUniformLocation(m_program, "u_Texture");
	m_WVP = glGetUniformLocation(m_program, "m_wvp");

	return 0;
}

Shaders::~Shaders()
{
	glDeleteProgram(m_program);
	glDeleteShader(m_vertexShader);
	glDeleteShader(m_fragmentShader);
}