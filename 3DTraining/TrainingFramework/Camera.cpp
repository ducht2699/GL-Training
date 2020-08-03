#include "stdafx.h"
#include "Camera.h"

Camera* Camera::s_Instance = NULL;

Camera::Camera()
{
	m_vPosition.x = 0.0f;
	m_vPosition.y = 0.0f;
	m_vPosition.z = 0.0f;

	m_vTarget.x = 0.134000f;
	m_vTarget.y = 1.020300f;
	m_vTarget.z = -0.083900f;

	m_vUp.x = 0.0f;
	m_vUp.y = 1.0f;
	m_vUp.z = 0.0f;

	m_fFOV = 1.0f;
	m_fNear = 0.1f;
	m_fFar = 500.0f;
	m_fMoveSpeed = 0.3f;
	m_fRotationSpeed = 0.3f;
}


Camera::~Camera()
{
}
Camera* Camera::GetInstance()
{
	if (!s_Instance)
		s_Instance = new Camera();
	return s_Instance;
}

void Camera::Init()
{

}

#pragma region Matrix Calculation
Vector3 Camera::GetXAxis()
{
	return (m_vUp.Cross(GetZAxis())).Normalize();
}
Vector3 Camera::GetYAxis()
{
	return (GetZAxis().Cross(GetXAxis()).Normalize());
}
Vector3 Camera::GetZAxis()
{
	return (m_vPosition - m_vTarget).Normalize();
}

Matrix Camera::GetViewMatrix()
{
	Matrix vViewMatrix;
	vViewMatrix.m[0][0] = GetXAxis().x;
	vViewMatrix.m[0][1] = GetYAxis().x;
	vViewMatrix.m[0][2] = GetZAxis().x;
	vViewMatrix.m[0][3] = 0.0f;

	vViewMatrix.m[1][0] = GetXAxis().y;
	vViewMatrix.m[1][1] = GetYAxis().y;
	vViewMatrix.m[1][2] = GetZAxis().z;
	vViewMatrix.m[1][3] = 0.0f;

	vViewMatrix.m[2][0] = GetXAxis().z;
	vViewMatrix.m[2][1] = GetYAxis().z;
	vViewMatrix.m[2][2] = GetZAxis().z;
	vViewMatrix.m[2][3] = 0.0f;

	vViewMatrix.m[3][0] = m_vPosition.Dot(GetXAxis()) * (-1.0f);
	vViewMatrix.m[3][1] = m_vPosition.Dot(GetYAxis()) * (-1.0f);
	vViewMatrix.m[3][2] = m_vPosition.Dot(GetZAxis()) * (-1.0f);
	vViewMatrix.m[3][3] = 1.0f;
	return vViewMatrix;
}
Matrix Camera::GetRotationMatrix()
{
	Matrix vRotationMatrix;
	vRotationMatrix.m[0][0] = GetXAxis().x;
	vRotationMatrix.m[0][1] = GetXAxis().y;
	vRotationMatrix.m[0][2] = GetXAxis().z;
	vRotationMatrix.m[0][3] = 0.0f;

	vRotationMatrix.m[1][0] = GetYAxis().x;
	vRotationMatrix.m[1][1] = GetYAxis().y;
	vRotationMatrix.m[1][2] = GetYAxis().z;
	vRotationMatrix.m[1][3] = 0.0f;

	vRotationMatrix.m[2][0] = GetZAxis().x;
	vRotationMatrix.m[2][1] = GetZAxis().y;
	vRotationMatrix.m[2][2] = GetZAxis().z;
	vRotationMatrix.m[2][3] = 0.0f;

	vRotationMatrix.m[3][0] = 0.0f;
	vRotationMatrix.m[3][1] = 0.0f;
	vRotationMatrix.m[3][2] = 0.0f;
	vRotationMatrix.m[3][3] = 1.0f;
	return vRotationMatrix;
}
Matrix Camera::GetTranslationMatrix()
{
	Matrix vTranslationMatrix;
	vTranslationMatrix.m[0][0] = 1.0f;
	vTranslationMatrix.m[0][1] = 0.0f;
	vTranslationMatrix.m[0][2] = 0.0f;
	vTranslationMatrix.m[0][3] = 0.0f;

	vTranslationMatrix.m[1][0] = 0.0f;
	vTranslationMatrix.m[1][1] = 1.0f;
	vTranslationMatrix.m[1][2] = 0.0f;
	vTranslationMatrix.m[1][3] = 0.0f;

	vTranslationMatrix.m[2][0] = 0.0f;
	vTranslationMatrix.m[2][1] = 0.0f;
	vTranslationMatrix.m[2][2] = 1.0f;
	vTranslationMatrix.m[2][3] = 0.0f;

	vTranslationMatrix.m[3][0] = m_vPosition.x;
	vTranslationMatrix.m[3][1] = m_vPosition.y;
	vTranslationMatrix.m[3][2] = m_vPosition.z;
	vTranslationMatrix.m[3][3] = 1.0f;
	return vTranslationMatrix;
}
Matrix Camera::GetPojectionMatrix()
{
	Matrix mProjectionMatrix;
	mProjectionMatrix.SetPerspective(m_fFOV, Globals::screenWidth / Globals::screenHeight, m_fNear, m_fFar);
	return mProjectionMatrix;
}
Matrix Camera::GetWorldMatrix()
{
	Matrix vWorldMatrix;
	vWorldMatrix.m[0][0] = GetXAxis().x;
	vWorldMatrix.m[0][1] = GetXAxis().y;
	vWorldMatrix.m[0][2] = GetXAxis().z;
	vWorldMatrix.m[0][3] = 0.0f;

	vWorldMatrix.m[1][0] = GetYAxis().x;
	vWorldMatrix.m[1][1] = GetYAxis().y;
	vWorldMatrix.m[1][2] = GetYAxis().z;
	vWorldMatrix.m[1][3] = 0.0f;

	vWorldMatrix.m[2][0] = GetZAxis().x;
	vWorldMatrix.m[2][1] = GetZAxis().y;
	vWorldMatrix.m[2][2] = GetZAxis().z;
	vWorldMatrix.m[2][3] = 0.0f;

	vWorldMatrix.m[3][0] = m_vPosition.x;
	vWorldMatrix.m[3][1] = m_vPosition.y;
	vWorldMatrix.m[3][2] = m_vPosition.z;
	vWorldMatrix.m[3][3] = 1.0f;
	return GetRotationMatrix() * GetTranslationMatrix();
}
#pragma endregion

#pragma region Move

#pragma endregion

