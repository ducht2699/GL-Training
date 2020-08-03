// TrainingFramework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Utilities/utilities.h" // if you use STL, please include this line AFTER all other include
#include "Vertex.h"
#include "Shaders.h"
#include "Globals.h"
#include "Model.h"
#include "Texture.h"
#include <conio.h>
#include "Object.h"



Shaders myShaders;
Object *oWoman = new Object();

int Init ( ESContext *esContext )
{
	glClearColor ( 1.0f, 1.0f, 1.0f, 1.0f );
	glEnable(GL_DEPTH_TEST);

	oWoman->Init("Woman1");


	return myShaders.Init("../Resources/Shaders/TriangleShaderVS.vs", "../Resources/Shaders/TriangleShaderFS.fs");
}

void Draw ( ESContext *esContext )
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(myShaders.m_program);

	glBindBuffer(GL_ARRAY_BUFFER, oWoman->GetVboID());
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, oWoman->GetIboID());
	glBindTexture(GL_TEXTURE_2D, oWoman->GetTextureID());
	if(myShaders.m_positionAttribute != -1)
	{
		glEnableVertexAttribArray(myShaders.m_positionAttribute);
		glVertexAttribPointer(myShaders.m_positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	}
	if (myShaders.m_uvAttribute != -1)
	{
		glEnableVertexAttribArray(myShaders.m_uvAttribute);
		glVertexAttribPointer(myShaders.m_uvAttribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (char*)0 + sizeof(Vector3) * 4);
	}
	if (myShaders.m_uniformLocation != -1)
	{
		glUniform1i(myShaders.m_uniformLocation, 0);
	}
	if (myShaders.m_uniformLocation != -1)
	{
		glUniformMatrix4fv(myShaders.m_WVP, 1, GL_FALSE, &oWoman->GetWVP().m[0][0]);
	}
	

	
	int numIndices = oWoman->GetModel()->GetIndicesList().size();
	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

	eglSwapBuffers ( esContext->eglDisplay, esContext->eglSurface );
}

void Update ( ESContext *esContext, float deltaTime )
{

}

void Key ( ESContext *esContext, unsigned char key, bool bIsPressed)
{

}

void CleanUp()
{
	SAFE_DEL(oWoman);
}

int _tmain(int argc, _TCHAR* argv[])
{
	ESContext esContext;

    esInitContext ( &esContext );

	esCreateWindow ( &esContext, "Hello Triangle", Globals::screenWidth, Globals::screenHeight, ES_WINDOW_RGB | ES_WINDOW_DEPTH);

	if ( Init ( &esContext ) != 0 )
		return 0;

	esRegisterDrawFunc ( &esContext, Draw );
	esRegisterUpdateFunc ( &esContext, Update );
	esRegisterKeyFunc ( &esContext, Key);

	esMainLoop ( &esContext );

	//releasing OpenGL resources
	CleanUp();

	//identifying memory leaks
	MemoryDump();
	printf("Press any key...\n");
	_getch();

	return 0;
}

