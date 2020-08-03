#include "stdafx.h"
#include "Object.h"


Object::Object() {
	m_mGraModel = new Model();
	m_tGraTexture = new Texture();

	m_vObjectRotation.x = 0.0f;
	m_vObjectRotation.y = 0.0f;
	m_vObjectRotation.z = 0.0f;


	Matrix RotationMatrixX, RotationMatrixY, RotationMatrixZ;
	RotationMatrixX.SetRotationX(m_vObjectRotation.x * (3.14 / 180.0f));
	RotationMatrixY.SetRotationY(m_vObjectRotation.y * (3.14 / 180.0f));
	RotationMatrixZ.SetRotationZ(m_vObjectRotation.z * (3.14 / 180.0f));

	m_mRotationMatrix = RotationMatrixZ * RotationMatrixX * RotationMatrixY;

	m_mScaleMatrix.SetScale(Vector3(1.0f, 1.0f, 1.0f));
	m_mTranslationMatrix.SetTranslation(Vector3(0.0f, 0.0f, 0.0f));
}

Object::~Object() {
	SAFE_DEL(m_mGraModel);
	SAFE_DEL(m_tGraTexture);
}

void Object::Init(char* objectName)
{
	char *cBufferModel = (char*)malloc(100), *cBufferTexture = (char*)malloc(100);
	sprintf(cBufferModel, "../Resources/Models/%s.nfg", objectName);
	LoadModel(cBufferModel);

	sprintf(cBufferTexture, "../Resources/Textures/%s.tga", objectName);
	LoadTexture(cBufferTexture);
}

void Object::LoadModel(char* strFilePath) {
	m_mGraModel->LoadModel(strFilePath);
}

void Object::LoadTexture(char* strFilePath) {
	m_tGraTexture->LoadTexture(strFilePath);
}

Model* Object::GetModel() {
	return m_mGraModel;
}

GLuint Object::GetVboID() {
	return m_mGraModel->GetVboID();
}

GLuint Object::GetIboID() {
	return m_mGraModel->GetIboID();
}

GLuint Object::GetTextureID() {
	return m_tGraTexture->GetTextureID();
}

Matrix Object::GetWVP() {
	m_mWorldMatrix =  m_mScaleMatrix * m_mRotationMatrix * m_mTranslationMatrix;

	m_WVPMatrix = m_mWorldMatrix * Camera::GetInstance()->GetViewMatrix() * Camera::GetInstance()->GetPojectionMatrix();
	return m_WVPMatrix;
}

