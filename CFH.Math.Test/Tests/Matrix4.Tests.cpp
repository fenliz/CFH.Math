#include "..\HelperMethods.h"

TEST(Matrix4, Constructors)
{
	Matrix4 matrix;
	float value;
	float m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44;

	//Matrix4()
	matrix = Matrix4();
	EXPECT_MATRIX_EQ(matrix,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0);

	//Matrix4(float)
	value = 5;
	matrix = Matrix4(value);
	EXPECT_MATRIX_EQ(matrix,
		value, value, value, value,
		value, value, value, value,
		value, value, value, value,
		value, value, value, value);

	/*Matrix4(float, float, float, float,
			float, float, float, float,
			float, float, float, float,
			float, float, float, float)*/
	m11 = 1, m12 = 5, m13 = -6, m14 = -2;
	m21 = 0, m22 = 66, m23 = 21, m24 = -65;
	m31 = 12, m32 = 123, m33 = 2, m34 = 6556;
	m41 = 7, m42 = 7.5, m43 = 1.2f, m44 = 0.01f;
	matrix = Matrix4(
		m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44);
	EXPECT_MATRIX_EQ(matrix,
		m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44);

	//Matrix4(std::initializer_list<float>)
	m11 = 4, m12 = 8, m13 = -1, m14 = -5;
	m21 = 5, m22 = 1, m23 = -2, m24 = -6;
	m31 = 6, m32 = 2, m33 = -3, m34 = -7;
	m41 = 7, m42 = 3, m43 = -4, m44 = -8;
	matrix = Matrix4({ m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44 });
	EXPECT_MATRIX_EQ(matrix,
		m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44);
}

TEST(Matrix4, Operators)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(Matrix4, Arithmetics)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(Matrix4, VectorOperations)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(Matrix4, Creaters)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(Matrix4, Specials)
{
	EXPECT_TRUE(false) << "No tests written!";
}