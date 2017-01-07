#include "HelperMethods.h"

void EXPECT_VECTOR_EQ(Vector2 vector, float x, float y)
{
	EXPECT_EQ(vector.X, x);
	EXPECT_EQ(vector.Y, y);
}
void EXPECT_VECTOR_NEAR(Vector2 vector, float x, float y, float abs_error)
{
	EXPECT_NEAR(vector.X, x, abs_error);
	EXPECT_NEAR(vector.Y, y, abs_error);
}
void EXPECT_VECTOR_EQ(Vector3 vector, float x, float y, float z)
{
	EXPECT_EQ(vector.X, x);
	EXPECT_EQ(vector.Y, y);
	EXPECT_EQ(vector.Z, z);
}
void EXPECT_VECTOR_NEAR(Vector3 vector, float x, float y, float z, float abs_error)
{
	EXPECT_NEAR(vector.X, x, abs_error);
	EXPECT_NEAR(vector.Y, y, abs_error);
	EXPECT_NEAR(vector.Z, z, abs_error);
}
void EXPECT_VECTOR_EQ(Vector4 vector, float x, float y, float z, float w)
{
	EXPECT_EQ(vector.X, x);
	EXPECT_EQ(vector.Y, y);
	EXPECT_EQ(vector.Z, z);
	EXPECT_EQ(vector.W, w);
}
void EXPECT_VECTOR_NEAR(Vector4 vector, float x, float y, float z, float w, float abs_error)
{
	EXPECT_NEAR(vector.X, x, abs_error);
	EXPECT_NEAR(vector.Y, y, abs_error);
	EXPECT_NEAR(vector.Z, z, abs_error);
	EXPECT_NEAR(vector.W, w, abs_error);
}

void EXPECT_MATRIX_EQ(Matrix4 matrix, float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44)
{
	EXPECT_EQ(matrix.M11, m11);
	EXPECT_EQ(matrix.M12, m12);
	EXPECT_EQ(matrix.M13, m13);
	EXPECT_EQ(matrix.M14, m14);

	EXPECT_EQ(matrix.M21, m21);
	EXPECT_EQ(matrix.M22, m22);
	EXPECT_EQ(matrix.M23, m23);
	EXPECT_EQ(matrix.M24, m24);

	EXPECT_EQ(matrix.M31, m31);
	EXPECT_EQ(matrix.M32, m32);
	EXPECT_EQ(matrix.M33, m33);
	EXPECT_EQ(matrix.M34, m34);

	EXPECT_EQ(matrix.M41, m41);
	EXPECT_EQ(matrix.M42, m42);
	EXPECT_EQ(matrix.M43, m43);
	EXPECT_EQ(matrix.M44, m44);
}