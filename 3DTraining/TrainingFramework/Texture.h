#pragma once
#include "../Utilities/utilities.h"
#include "Math.h"

class Texture
{
private:
	GLuint m_iTextureID;
public:
	GLuint GetTextureID();
	void LoadTexture(char*);

	Texture();
	~Texture();
};

