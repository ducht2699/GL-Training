#pragma once
#include "Math.h"

struct Vertex 
{
	Vector3 pos;
	Vector3 normal;
	Vector3 binormal;
	Vector3 tangent;
	Vector2 uv;

	Vertex()
	{
		pos = Vector3(0.0f, 0.0f, 0.0f);
		normal = Vector3(0.0f, 0.0f, 0.0f);
		binormal = Vector3(0.0f, 0.0f, 0.0f);
		uv = Vector2(0.0f, 0.0f);
	}

	Vertex(const Vertex &v)
	{
		pos = Vector3(v.pos.x, v.pos.y, v.pos.z);
		normal = Vector3(v.normal.x, v.normal.y, v.normal.z);
		binormal = Vector3(v.binormal.x, v.binormal.y, v.binormal.z);
		uv = Vector2(v.uv.x, v.uv.y);
	}
};