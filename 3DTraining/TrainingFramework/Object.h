#pragma once

#include "stdafx.h"
#include "Model.h"
#include "Texture.h"
#include "Camera.h"
using namespace std;

class Object {
private:
	Model* m_mGraModel;
	Texture* m_tGraTexture;

	Matrix m_mWorldMatrix, m_WVPMatrix;
	Matrix m_mScaleMatrix, m_mRotationMatrix, m_mTranslationMatrix;

	Vector3 m_vWorldLocation;
	Vector3 m_vObjectRotation; // Angles in degrees
	Vector3 m_vObjectScale;
public:
	Object();
	~Object();

	void Init(char* objectName);
	void LoadModel(char* strFilePath);
	void LoadTexture(char* strFilePath);

	Model* GetModel();
	GLuint GetVboID();
	GLuint GetIboID();
	GLuint GetTextureID();

	Matrix GetWVP();
};