#include "..\HelperMethods.h"

TEST(Vector3, Constructors)
{
	Vector3 vector, vector2;
	float value, x, y, z;

	//Vector3()
	vector = Vector3();
	EXPECT_VECTOR_EQ(vector, 0, 0, 0);

	//Vector3(float)
	value = 3;
	vector = Vector3(value);
	EXPECT_VECTOR_EQ(vector, value, value, value);

	//Vector3(float, float, float)
	x = 1, y = 2, z = 3;
	vector = Vector3(x, y, z);
	EXPECT_VECTOR_EQ(vector, x, y, z);

	//Vector3(Vector2, float)
	x = 5, y = 4, z = 1;
	vector = Vector3(Vector2(x, y), z);
	EXPECT_VECTOR_EQ(vector, x, y, z);

	//Vector3(Vector3)
	x = 6.5f, y = 0.2f, z = 3.4f;
	vector = Vector3(x, y, z);
	vector2 = Vector3(1.2f, 5.4f, 0.1f);
	vector2 = Vector3(vector);
	EXPECT_VECTOR_EQ(vector, x, y, z);

	//Vector3(std::initializer_list<float>)
	x = 10, y = 9, z = 8;
	vector = { x, y, z };
	EXPECT_VECTOR_EQ(vector, x, y, z);
}

TEST(Vector3, Constants)
{
	Vector3 vector;

	//Vector3(1, 0, 0)
	vector = Vector3::UnitX;
	EXPECT_VECTOR_EQ(vector, 1, 0, 0);

	//Vector3(0, 1, 0)
	vector = Vector3::UnitY;
	EXPECT_VECTOR_EQ(vector, 0, 1, 0);

	//Vector3(0, 0, 1)
	vector = Vector3::UnitZ;
	EXPECT_VECTOR_EQ(vector, 0, 0, 1);

	//Vector3(1, 1, 1)
	vector = Vector3::One;
	EXPECT_VECTOR_EQ(vector, 1, 1, 1);

	//Vector3(0, 0, 0)
	vector = Vector3::Zero;
	EXPECT_VECTOR_EQ(vector, 0, 0, 0);

	//Vector3(0, 0, -1)
	vector = Vector3::Forward;
	EXPECT_VECTOR_EQ(vector, 0, 0, -1);

	//Vector3(0, 0, 1)
	vector = Vector3::Backward;
	EXPECT_VECTOR_EQ(vector, 0, 0, 1);

	//Vector3(0, 1, 0)
	vector = Vector3::Up;
	EXPECT_VECTOR_EQ(vector, 0, 1, 0);

	//Vector3(0, -1, 0)
	vector = Vector3::Down;
	EXPECT_VECTOR_EQ(vector, 0, -1, 0);

	//Vector3(1, 0, 0)
	vector = Vector3::Right;
	EXPECT_VECTOR_EQ(vector, 1, 0, 0);

	//Vector3(-1, 0, 0)
	vector = Vector3::Left;
	EXPECT_VECTOR_EQ(vector, -1, 0, 0);
}

TEST(Vector3, Operators)
{
	Vector3 a = Vector3(1, 2, 3), b = Vector3(2, 2, 2);
	float value = 4;
	Vector3 result;

	//Vector3 + Vector3
	result = a + b;
	EXPECT_VECTOR_EQ(result, 3, 4, 5);

	//Vector3 - Vector3
	result = a - b;
	EXPECT_VECTOR_EQ(result, -1, 0, 1);

	//Vector3 * Vector3
	result = a * b;
	EXPECT_VECTOR_EQ(result, 2, 4, 6);

	//Vector3 * float
	result = a * value;
	EXPECT_VECTOR_EQ(result, 4, 8, 12);

	//Vector3 * Vector3
	result = a / b;
	EXPECT_VECTOR_EQ(result, 0.5f, 1, 1.5f);

	//Vector3 * float
	result = a / value;
	EXPECT_VECTOR_EQ(result, 0.25f, 0.5f, 0.75f);


	//Vector3 += Vector3
	a = Vector3(1, 0, -1), b = Vector3(2, 4, 7);
	a += b;
	EXPECT_VECTOR_EQ(a, 3, 4, 6);

	//Vector3 -= Vector3
	a = Vector3(1, 0, -1), b = Vector3(2, 4, 7);
	a -= b;
	EXPECT_VECTOR_EQ(a, -1, -4, -8);

	//Vector3 *= Vector3
	a = Vector3(1, 0, -1), b = Vector3(2, 4, 7);
	a *= b;
	EXPECT_VECTOR_EQ(a, 2, 0, -7);

	//Vector3 *= float
	a = Vector3(1, 0, -1);
	value = 5;
	a *= value;
	EXPECT_VECTOR_EQ(a, 5, 0, -5);

	//Vector3 /= Vector3
	a = Vector3(4, 8, 12), b = Vector3(4, 2, 1);
	a /= b;
	EXPECT_VECTOR_EQ(a, 1, 4, 12);

	//Vector3 /= float
	a = Vector3(4, 8, 12);
	value = 4;
	a /= value;
	EXPECT_VECTOR_EQ(a, 1, 2, 3);

	//Vector3 == Vector3
	a = Vector3(9, 7, 3), b = Vector3(9, 7, 3);
	EXPECT_TRUE(a == b);
	b = Vector3(8, 7, 3);
	EXPECT_FALSE(a == b);

	//Vector3 != Vector3
	EXPECT_TRUE(a != b);
	b = Vector3(9, 7, 3);
	EXPECT_FALSE(a != b);
}

TEST(Vector3, Arithmetics)
{
	Vector3 a, b;
	float value;
	Vector3 result;

	//Vector3::Add(Vector3, Vector3)
	a = Vector3(1, 2, 3), b = Vector3(2, 3, 4);
	EXPECT_VECTOR_EQ(Vector3::Add(a, b), 3, 5, 7);
	Vector3::Add(a, b, result);
	EXPECT_VECTOR_EQ(result, 3, 5, 7);

	//Vector3::Subtract(Vector3, Vector3)
	a = Vector3(2, 3, 4), b = Vector3(1, 2, 3);
	EXPECT_VECTOR_EQ(Vector3::Subtract(a, b), 1, 1, 1);
	Vector3::Subtract(a, b, result);
	EXPECT_VECTOR_EQ(result, 1, 1, 1);

	//Vector3::Multiply(Vector3, Vector3)
	a = Vector3(1, 2, 3), b = Vector3(2, 3, 4);
	EXPECT_VECTOR_EQ(Vector3::Multiply(a, b), 2, 6, 12);
	Vector3::Multiply(a, b, result);
	EXPECT_VECTOR_EQ(result, 2, 6, 12);

	//Vector3::Multiply(Vector3, float)
	a = Vector3(1, 4, 10);
	value = 5;
	EXPECT_VECTOR_EQ(Vector3::Multiply(a, value), 5, 20, 50);
	Vector3::Multiply(a, value, result);
	EXPECT_VECTOR_EQ(result, 5, 20, 50);

	//Vector3::Divide(Vector3, Vector3)
	a = Vector3(1, 3, 6), b = Vector3(2, 2, 3);
	EXPECT_VECTOR_EQ(Vector3::Divide(a, b), 0.5f, 1.5f, 2);
	Vector3::Divide(a, b, result);
	EXPECT_VECTOR_EQ(result, 0.5f, 1.5f, 2);

	//Vector3::Divide(Vector3, float)
	a = Vector3(3, 6, 9);
	value = 3;
	EXPECT_VECTOR_EQ(Vector3::Divide(a, value), 1, 2, 3);
	Vector3::Divide(a, value, result);
	EXPECT_VECTOR_EQ(result, 1, 2, 3);

	//Vector3::Negate(Vector3)
	a = Vector3(1, -4, -5);
	EXPECT_VECTOR_EQ(Vector3::Negate(a), -1, 4, 5);
	Vector3::Negate(a, result);
	EXPECT_VECTOR_EQ(result, -1, 4, 5);
}

TEST(Vector3, Length)
{
	Vector3 vector;
	float result;

	//Length()
	vector = Vector3(1, 2, 3);
	EXPECT_NEAR(vector.Length(), 3.74f, 0.01f);
	vector.Length(result);
	EXPECT_NEAR(result, 3.74f, 0.01f);

	//Vector3::Length(Vector3)
	vector = Vector3(4, 5, 6);
	EXPECT_NEAR(Vector3::Length(vector), 8.77f, 0.01f);
	Vector3::Length(vector, result);
	EXPECT_NEAR(result, 8.77f, 0.01f);

	//LengthSquared()
	vector = Vector3(1, 1, 1);
	EXPECT_EQ(vector.LengthSquared(), 3);
	vector.LengthSquared(result);
	EXPECT_EQ(result, 3);

	//Vector3::LengthSquared(Vector3)
	vector = Vector3(-3, -1, 4);
	EXPECT_EQ(Vector3::LengthSquared(vector), 26);
	Vector3::LengthSquared(vector, result);
	EXPECT_EQ(result, 26);
}

TEST(Vector3, Distance)
{
	Vector3 a, b;
	float result;

	//Vector3::Distance(Vector3, Vector3)
	a = Vector3(2, 5, 10), b = Vector3(-4, -7, 10);
	EXPECT_NEAR(Vector3::Distance(a, b), 13.41f, 0.01f);
	Vector3::Distance(a, b, result);
	EXPECT_NEAR(result, 13.41f, 0.01f);

	//Vector3::DistanceSquared(Vector3, Vector3)
	a = Vector3(-1, -4, 5), b = Vector3(7, 12, 24);
	EXPECT_EQ(Vector3::DistanceSquared(a, b), 681);
	Vector3::DistanceSquared(a, b, result);
	EXPECT_EQ(result, 681);
}

TEST(Vector3, Dot_Cross)
{
	Vector3 a, b;
	float result;
	Vector3 vResult;

	//Vector3::Dot(Vector3, Vector3)
	a = Vector3(1, 2, 3), b = Vector3(-1, -2, -3);
	EXPECT_EQ(Vector3::Dot(a, b), -14);
	Vector3::Dot(a, b, result);
	EXPECT_EQ(result, -14);

	//Vector3::Cross(Vector3, Vector3)
	a = Vector3(5, 1, 10), b = Vector3(7, 10, -4);
	EXPECT_VECTOR_EQ(Vector3::Cross(a, b), -104, 90, 43);
	Vector3::Cross(a, b, vResult);
	EXPECT_VECTOR_EQ(vResult, -104, 90, 43);
}

TEST(Vector3, Clamp_Normalize)
{
	Vector3 vector;
	Vector3 min, max;
	Vector3 result;

	//Vector3::Clamp(Vector3, Vector3, Vector3)
	vector = Vector3(40, -10, 6);
	min = Vector3(-1, -1, -1), max = Vector3(5, 5, 7);
	EXPECT_VECTOR_EQ(Vector3::Clamp(vector, min, max), 5, -1, 6);
	Vector3::Clamp(vector, min, max, result);
	EXPECT_VECTOR_EQ(result, 5, -1, 6);

	//Normalize()
	vector = Vector3(1, 2, 3);
	vector.Normalize();
	EXPECT_VECTOR_NEAR(vector, 0.27f, 0.53f, 0.80f, 0.01f);
	EXPECT_NEAR(vector.Length(), 1, 0.001f);

	//Vector3::Normalize(Vector3)
	vector = Vector3(2, 3, 4);
	EXPECT_VECTOR_NEAR(Vector3::Normalize(vector), 0.37f, 0.56f, 0.74f, 0.01f);
	Vector3::Normalize(vector, result);
	EXPECT_VECTOR_NEAR(result, 0.37f, 0.56f, 0.74f, 0.01f);
	EXPECT_NEAR(result.Length(), 1, 0.001f);
}

TEST(Vector3, Transforms)
{
	EXPECT_TRUE(false) << "No tests written!";
}