#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"
#include "Quaternion.h"

#include "gtest\gtest.h"
using namespace CFH;

void EXPECT_VECTOR_EQ(Vector2 vector, float x, float y);
void EXPECT_VECTOR_NEAR(Vector2 vector, float x, float y, float abs_error);
void EXPECT_VECTOR_EQ(Vector3 vector, float x, float y, float z);
void EXPECT_VECTOR_NEAR(Vector3 vector, float x, float y, float z, float abs_error);
void EXPECT_VECTOR_EQ(Vector4 vector, float x, float y, float z, float w);
void EXPECT_VECTOR_NEAR(Vector4 vector, float x, float y, float z, float w, float abs_error);

void EXPECT_MATRIX_EQ(Matrix4 matrix, float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44);