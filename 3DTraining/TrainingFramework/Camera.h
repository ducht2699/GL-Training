#pragma once
#include "stdafx.h"
#include "Globals.h"
#include "Model.h"
#include "Texture.h"
class Camera
{
private:
	static Camera* s_Instance;

	float m_fNear;
	float m_fFar;
	float m_fFOV;
	float m_fRotationSpeed;
	float m_fMoveSpeed;

	Vector3 m_vUp;

	Vector3 m_vPosition;
	Vector3 m_vTarget;
public:
	Camera();
	~Camera();
	static Camera* GetInstance();

	void Init();

	//caculate matrix
	Vector3 GetXAxis();
	Vector3 GetYAxis();
	Vector3 GetZAxis();

	Matrix GetViewMatrix();
	Matrix GetRotationMatrix();
	Matrix GetTranslationMatrix();
	Matrix GetWorldMatrix();
	Matrix GetPojectionMatrix();
	//move
	void MoveFoward();
	void MoveBackward();
	void MoveLeft();
	void MoveRight();
	//rotate
	void RotateUp();
	void RotateDown();
	void RotateLeft();
	void RotateRight();
};

