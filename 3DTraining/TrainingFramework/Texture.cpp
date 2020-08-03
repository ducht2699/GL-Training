#include "stdafx.h"
#include "Texture.h"


Texture::Texture()
{
}


Texture::~Texture()
{
}

GLuint Texture::GetTextureID()
{
	return m_iTextureID;
}

void Texture::LoadTexture(char* textureLocation)
{
	glGenTextures(1, &m_iTextureID);
	glBindTexture(GL_TEXTURE_2D, m_iTextureID);

	int iWidth, iHeight, iBpp;
	char* bufferTGA = LoadTGA(textureLocation, &iWidth, &iHeight, &iBpp);

	if (iBpp == 24)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, iWidth, iHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bufferTGA);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, iWidth, iHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, bufferTGA);
	}
	delete[] bufferTGA;

	//set the filters for minification and magnification

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, 0);
}