#include "..\HelperMethods.h"

TEST(Vector4, Constructors)
{
	Vector4 vector, vector2;
	float value, x, y, z, w;

	//Vector4()
	vector = Vector4();
	EXPECT_VECTOR_EQ(vector, 0, 0, 0, 0);

	//Vector4(float)
	value = 9;
	vector = Vector4(value);
	EXPECT_VECTOR_EQ(vector, value, value, value, value);

	//Vector4(Vector2, float, float)
	x = 4, y = -3, z = -9, w = 10;
	vector = Vector4(Vector2(x, y), z, w);
	EXPECT_VECTOR_EQ(vector, x, y, z, w);

	//Vector4(Vector3, float)
	x = 1, y = 2, z = 3, w = 4;
	vector = Vector4(Vector3(x, y, z), w);
	EXPECT_VECTOR_EQ(vector, x, y, z, w);

	//Vector4(float, float, float, float)
	x = 2, y = -2, z = 7, w = 26;
	vector = Vector4(x, y, z, w);
	EXPECT_VECTOR_EQ(vector, x, y, z, w);

	//Vector4(std::initializer_list<float>)
	x = 1, y = 76, z = -4325, w = 75;
	vector = { x, y, z, w };
	EXPECT_VECTOR_EQ(vector, x, y, z, w);
}

TEST(Vector4, Constants)
{
	Vector4 vector;

	//Vector4(1, 0, 0, 0)
	vector = Vector4::UnitX;
	EXPECT_VECTOR_EQ(vector, 1, 0, 0, 0);

	//Vector4(0, 1, 0, 0)
	vector = Vector4::UnitY;
	EXPECT_VECTOR_EQ(vector, 0, 1, 0, 0);

	//Vector4(0, 0, 1, 0)
	vector = Vector4::UnitZ;
	EXPECT_VECTOR_EQ(vector, 0, 0, 1, 0);

	//Vector4(0, 0, 0, 1)
	vector = Vector4::UnitW;
	EXPECT_VECTOR_EQ(vector, 0, 0, 0, 1);

	//Vector4(1, 1, 1, 1)
	vector = Vector4::One;
	EXPECT_VECTOR_EQ(vector, 1, 1, 1, 1);

	//Vector4(0, 0, 0, 0)
	vector = Vector4::Zero;
	EXPECT_VECTOR_EQ(vector, 0, 0, 0, 0);
}

TEST(Vector4, Operators)
{
	Vector4 a = Vector4(1, 2, 3, 4), b = Vector4(6, 7, 4, 3);
	float value = 7;
	Vector4 result;

	//Vector4 + Vector4
	result = a + b;
	EXPECT_VECTOR_EQ(result, 7, 9, 7, 7);

	//Vector4 - Vector4
	result = a - b;
	EXPECT_VECTOR_EQ(result, -5, -5, -1, 1);

	//Vector4 * Vector4
	result = a * b;
	EXPECT_VECTOR_EQ(result, 6, 14, 12, 12);

	//Vector4 * float
	result = a * value;
	EXPECT_VECTOR_EQ(result, 7, 14, 21, 28);

	//Vector4 / Vector4
	result = a / b;
	EXPECT_VECTOR_NEAR(result, 0.17f, 0.29f, 0.75f, 1.33f, 0.01f);

	//Vector4 / float
	result = a / value;
	EXPECT_VECTOR_NEAR(result, 0.14f, 0.29f, 0.43f, 0.57f, 0.01f);


	//Vector4 += Vector4
	a = Vector4(1, 2, 3, 4), b = Vector4(-1, -4, 6, 8);
	a += b;
	EXPECT_VECTOR_EQ(a, 0, -2, 9, 12);

	//Vector4 -= Vector4
	a = Vector4(1, 2, 3, 4), b = Vector4(-1, -4, 6, 8);
	a -= b;
	EXPECT_VECTOR_EQ(a, 2, 6, -3, -4);

	//Vector4 *= Vector4
	a = Vector4(1, 2, 3, 4), b = Vector4(-1, -4, 6, 8);
	a *= b;
	EXPECT_VECTOR_EQ(a, -1, -8, 18, 32);

	//Vector4 *= value
	a = Vector4(1, 2, 3, 4);
	value = 5;
	a *= value;
	EXPECT_VECTOR_EQ(a, 5, 10, 15, 20);

	//Vector4 /= Vector4
	a = Vector4(1, 2, 3, 4), b = Vector4(-1, -4, 6, 8);
	a /= b;
	EXPECT_VECTOR_EQ(a, -1, -0.5f, 0.5f, 0.5f);

	//Vector4 /= value
	a = Vector4(10, 9, 8, 7);
	value = 2;
	a /= value;
	EXPECT_VECTOR_EQ(a, 5, 4.5f, 4, 3.5f);

	//Vector4 == Vector4
	a = Vector4(1, 2, 3, 4), b = Vector4(-1, -4, 6, 8);
	EXPECT_FALSE(a == b);
	a = Vector4(-1, -4, 6, 8);
	EXPECT_TRUE(a == b);

	//Vector4 != Vector4
	EXPECT_FALSE(a != b);
	b.X = 6;
	EXPECT_TRUE(a != b);
}

TEST(Vector4, Arithmetics)
{
	Vector4 a, b;
	float value;
	Vector4 result;

	//Vector4::Add(Vector4, Vector4)
	a = Vector4(1, 2, 3, 4), b = Vector4(5, 6, 1, -4);
	EXPECT_VECTOR_EQ(Vector4::Add(a, b), 6, 8, 4, 0);
	Vector4::Add(a, b, result);
	EXPECT_VECTOR_EQ(result, 6, 8, 4, 0);

	//Vector4::Subtract(Vector4, Vector4)
	a = Vector4(1, 2, 3, 4), b = Vector4(5, 6, 1, -4);
	EXPECT_VECTOR_EQ(Vector4::Subtract(a, b), -4, -4, 2, 8);
	Vector4::Subtract(a, b, result);
	EXPECT_VECTOR_EQ(result, -4, -4, 2, 8);

	//Vector4::Multiply(Vector4, Vector4)
	a = Vector4(1, 2, 3, 4), b = Vector4(5, 6, 1, -4);
	EXPECT_VECTOR_EQ(Vector4::Multiply(a, b), 5, 12, 3, -16);
	Vector4::Multiply(a, b, result);
	EXPECT_VECTOR_EQ(result, 5, 12, 3, -16);

	//Vector4::Multiply(Vector4, float)
	a = Vector4(1, 2, 3, 4);
	value = 6;
	EXPECT_VECTOR_EQ(Vector4::Multiply(a, value), 6, 12, 18, 24);
	Vector4::Multiply(a, value, result);
	EXPECT_VECTOR_EQ(result, 6, 12, 18, 24);

	//Vector4::Divide(Vector4, Vector4)
	a = Vector4(3, 9, -4, -2), b = Vector4(6, 4, 2, -1);
	EXPECT_VECTOR_EQ(Vector4::Divide(a, b), 0.5f, 2.25f, -2, 2);
	Vector4::Divide(a, b, result);
	EXPECT_VECTOR_EQ(result, 0.5f, 2.25f, -2, 2);

	//Vector4::Divide(Vector4, float)
	a = Vector4(3, 6, 9, 12);
	value = 2;
	EXPECT_VECTOR_EQ(Vector4::Divide(a, value), 1.5f, 3, 4.5f, 6);
	Vector4::Divide(a, value, result);
	EXPECT_VECTOR_EQ(result, 1.5f, 3, 4.5f, 6);

	//Vector4::Negate(Vector4)
	a = Vector4(-1, 5, 2, -10);
	EXPECT_VECTOR_EQ(Vector4::Negate(a), 1, -5, -2, 10);
	Vector4::Negate(a, result);
	EXPECT_VECTOR_EQ(result, 1, -5, -2, 10);
}

TEST(Vector4, Length)
{
	Vector4 vector;
	float result;

	//Length()
	vector = Vector4(1, 2, 3, 4);
	EXPECT_NEAR(vector.Length(), 5.48f, 0.01f);
	vector.Length(result);
	EXPECT_NEAR(result, 5.48f, 0.01f);

	//Vector4::Length(Vector4)
	vector = Vector4(6, 3, -2, -1);
	EXPECT_NEAR(Vector4::Length(vector), 7.07f, 0.01f);
	Vector4::Length(vector, result);
	EXPECT_NEAR(result, 7.07f, 0.01f);

	//LengthSquared
	vector = Vector4(8, 12, 4, -2);
	EXPECT_EQ(vector.LengthSquared(), 228);
	vector.LengthSquared(result);
	EXPECT_EQ(result, 228);

	//Vector4::LengthSquared(Vector4)
	vector = Vector4(2, 4, 8, 16);
	EXPECT_EQ(Vector4::LengthSquared(vector), 340);
	Vector4::LengthSquared(vector, result);
	EXPECT_EQ(result, 340);
}

TEST(Vector4, Distance)
{
	Vector4 a, b;
	float result;

	//Vector4::Distance(Vector4, Vector4)
	a = Vector4(4, 2, 0, -4), b = Vector4(-4, 6, 8, 1);
	EXPECT_NEAR(Vector4::Distance(a, b), 13, 0.01f);
	Vector4::Distance(a, b, result);
	EXPECT_NEAR(result, 13, 0.01f);

	//Vector4::DistanceSquared(Vector4, Vector4)
	a = Vector4(6, 45, 2, 10), b = Vector4(-4, 30, 1, 25);
	EXPECT_EQ(Vector4::DistanceSquared(a, b), 551);
	Vector4::DistanceSquared(a, b, result);
	EXPECT_EQ(result, 551);
}

TEST(Vector4, Dot)
{
	Vector4 a, b;
	float result;
	Vector4 vResult;

	//Vector3::Dot(Vector4, Vector4)
	a = Vector4(2, 3, 1, 4), b = Vector4(-1, -5, 7, 10);
	EXPECT_EQ(Vector4::Dot(a, b), 30);
	Vector4::Dot(a, b, result);
	EXPECT_EQ(result, 30);
}

TEST(Vector4, Clamp_Normalize)
{
	Vector4 vector;
	Vector4 min, max;
	Vector4 result;

	//Vector4::Clamp(Vector4, Vector4, Vector4)
	vector = Vector4(40, 30, -20, 5);
	min = Vector4(-10, -10, -5, 7), max = Vector4(20, 35, 10, 20);
	EXPECT_VECTOR_EQ(Vector4::Clamp(vector, min, max), 20, 30, -5, 7);
	Vector4::Clamp(vector, min, max, result);
	EXPECT_VECTOR_EQ(result, 20, 30, -5, 7);

	//Normalize()
	vector = Vector4(4, 2, 0, 1);
	vector.Normalize();
	EXPECT_VECTOR_NEAR(vector, 0.87f, 0.44f, 0, 0.22f, 0.01f);
	EXPECT_NEAR(vector.Length(), 1, 0.01f);

	//Vector4::Normalize(Vector4)
	vector = Vector4(7, 4, -2, 10);
	EXPECT_VECTOR_NEAR(Vector4::Normalize(vector), 0.54f, 0.31f, -0.15f, 0.77f, 0.01f);
	Vector4::Normalize(vector, result);
	EXPECT_VECTOR_NEAR(result, 0.54f, 0.31f, -0.15f, 0.77f, 0.01f);
	EXPECT_NEAR(result.Length(), 1, 0.01f);
}

TEST(Vector4, Transforms)
{
	EXPECT_TRUE(false) << "No tests written!";
}