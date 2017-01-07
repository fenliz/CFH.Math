#include "..\HelperMethods.h"

TEST(Vector2, Constructors)
{
	Vector2 vector, vector2;
	float value, x, y;

	//Vector2()
	vector = Vector2();
	EXPECT_VECTOR_EQ(vector, 0, 0);

	//Vector2(float)
	value = 3;
	vector = Vector2(value);
	EXPECT_VECTOR_EQ(vector, value, value);

	//Vector2(x, y)
	x = 2, y = -4;
	vector = Vector2(x, y);
	EXPECT_VECTOR_EQ(vector, x, y);

	//Vector2(std::initailizer_list<float>)
	x = -1, y = 20;
	vector = { x, y };
	EXPECT_VECTOR_EQ(vector, x, y);
}

TEST(Vector2, Constants)
{
	Vector2 vector;

	//Vector2(1, 0)
	vector = Vector2::UnitX;
	EXPECT_VECTOR_EQ(vector, 1, 0);

	//Vector2(0, 1)
	vector = Vector2::UnitY;
	EXPECT_VECTOR_EQ(vector, 0, 1);

	//Vector2(1, 1)
	vector = Vector2::One;
	EXPECT_VECTOR_EQ(vector, 1, 1);

	//Vector2(0, 0)
	vector = Vector2::Zero;
	EXPECT_VECTOR_EQ(vector, 0, 0);

	//Vector2(0, 1)
	vector = Vector2::Up;
	EXPECT_VECTOR_EQ(vector, 0, 1);

	//Vector2(0, -1)
	vector = Vector2::Down;
	EXPECT_VECTOR_EQ(vector, 0, -1);

	//Vector2(1, 0)
	vector = Vector2::Right;
	EXPECT_VECTOR_EQ(vector, 1, 0);

	//Vector2(-1, 0)
	vector = Vector2::Left;
	EXPECT_VECTOR_EQ(vector, -1, 0);
}

TEST(Vector2, Operators)
{
	Vector2 a = Vector2(1, 2), b = Vector2(4, 4);
	float value = 3;
	Vector2 result;

	//Vector2 + Vector2
	result = a + b;
	EXPECT_VECTOR_EQ(result, 5, 6);

	//Vector2 - Vector2
	result = a - b;
	EXPECT_VECTOR_EQ(result, -3, -2);

	//Vector2 * Vector2
	result = a * b;
	EXPECT_VECTOR_EQ(result, 4, 8);

	//Vector2 * float
	result = a * value;
	EXPECT_VECTOR_EQ(result, 3, 6);

	//Vector2 / Vector2
	result = a / b;
	EXPECT_VECTOR_EQ(result, 0.25f, 0.5f);

	//Vector2 / float
	result = a / value;
	EXPECT_VECTOR_NEAR(result, 0.33f, 0.66f, 0.01f);


	//Vector2 += Vector2
	a = Vector2(1, 0), b = Vector2(4, 4);
	a += b;
	EXPECT_VECTOR_EQ(a, 5, 4);

	//Vector2 -= Vector2
	a = Vector2(1, 0), b = Vector2(4, 4);
	a -= b;
	EXPECT_VECTOR_EQ(a, -3, -4);

	//Vector2 *= Vector2
	a = Vector2(1, 2), b = Vector2(-3, 8);
	a *= b;
	EXPECT_VECTOR_EQ(a, -3, 16);

	//Vector2 *= float
	a = Vector2(3, -2);
	value = 3;
	a *= value;
	EXPECT_VECTOR_EQ(a, 9, -6);

	//Vector2 /= Vector2
	a = Vector2(2, 2), b = Vector2(-2, 1);
	a /= b;
	EXPECT_VECTOR_EQ(a, -1, 2);

	//Vector2 /= float
	a = Vector2(1, 3);
	value = -3;
	a /= value;
	EXPECT_VECTOR_NEAR(a, -0.33f, -1, 0.01f);

	//Vector2 == Vector2
	a = Vector2(-3, 2), b = Vector2(3, -2);
	EXPECT_FALSE(a == b);
	b = Vector2::Negate(b);
	EXPECT_TRUE(a == b);

	//Vector2 != Vector2
	EXPECT_FALSE(a != b);
	b.X = 1;
	EXPECT_TRUE(a != b);
}

TEST(Vector2, Arithmetics)
{
	Vector2 a, b;
	float value;
	Vector2 result;

	//Vector2::Add(Vector2, Vector2)
	a = Vector2(5, 4), b = Vector2(-1, -2);
	EXPECT_VECTOR_EQ(Vector2::Add(a, b), 4, 2);
	Vector2::Add(a, b, result);
	EXPECT_VECTOR_EQ(result, 4, 2);

	//Vector2::Subtract(Vector2, Vector2)
	a = Vector2(1, 2), b = Vector2(5, -7);
	EXPECT_VECTOR_EQ(Vector2::Subtract(a, b), -4, 9);
	Vector2::Subtract(a, b, result);
	EXPECT_VECTOR_EQ(result, -4, 9);

	//Vector2::Multiply(Vector2, Vector2)
	a = Vector2(5, -2), b = Vector2(-2, 1);
	EXPECT_VECTOR_EQ(Vector2::Multiply(a, b), -10, -2);
	Vector2::Multiply(a, b, result);
	EXPECT_VECTOR_EQ(result, -10, -2);

	//Vector2::Mulitply(Vector2, float)
	a = Vector2(-2, 9);
	value = -3;
	EXPECT_VECTOR_EQ(Vector2::Multiply(a, value), 6, -27);
	Vector2::Multiply(a, value, result);
	EXPECT_VECTOR_EQ(result, 6, -27);

	//Vector2::Divide(Vector2, Vector2)
	a = Vector2(4, 6), b = Vector2(2, 3);
	EXPECT_VECTOR_EQ(Vector2::Divide(a, b), 2, 2);
	Vector2::Divide(a, b, result);
	EXPECT_VECTOR_EQ(result, 2, 2);

	//Vector2::Divide(Vector2, float)
	a = Vector2(-3, 9);
	value = 3;
	EXPECT_VECTOR_EQ(Vector2::Divide(a, value), -1, 3);
	Vector2::Divide(a, value, result);
	EXPECT_VECTOR_EQ(result, -1, 3);

	//Vector2::Negate(Vector2)
	a = Vector2(-2, 17);
	EXPECT_VECTOR_EQ(Vector2::Negate(a), 2, -17);
	Vector2::Negate(a, result);
	EXPECT_VECTOR_EQ(result, 2, -17);
}

TEST(Vector2, Length)
{
	Vector2 vector;
	float result;

	//Length()
	vector = Vector2(2, 4);
	EXPECT_NEAR(vector.Length(), 4.47f, 0.01f);
	vector.Length(result);
	EXPECT_NEAR(result, 4.47f, 0.01f);

	//Vector2::Length(Vector3)
	vector = Vector2(-66, 20);
	EXPECT_NEAR(Vector2::Length(vector), 68.96f, 0.01f);
	Vector2::Length(vector, result);
	EXPECT_NEAR(result, 68.96f, 0.01f);

	//LengthSquared()
	vector = Vector2(-12, -24);
	EXPECT_EQ(vector.LengthSquared(), 720);
	vector.LengthSquared(result);
	EXPECT_EQ(result, 720);

	//Vector2::LengthSquared(Vector2)
	vector = Vector2(45, 78);
	EXPECT_EQ(Vector2::LengthSquared(vector), 8109);
	Vector2::LengthSquared(vector, result);
	EXPECT_EQ(result, 8109);
}

TEST(Vector2, Distance)
{
	Vector2 a, b;
	float result;

	//Vector2::Distance(Vector2, Vector2)
	a = Vector2(4, 5), b = Vector2(-1, 7);
	EXPECT_NEAR(Vector2::Distance(a, b), 5.39f, 0.01f);
	Vector2::Distance(a, b, result);
	EXPECT_NEAR(result, 5.39f, 0.01f);

	//Vector2::DistanceSquared(Vector2, Vector2)
	a = Vector2(2, 6), b = Vector2(-4, -5);
	EXPECT_EQ(Vector2::DistanceSquared(a, b), 157);
	Vector2::DistanceSquared(a, b, result);
	EXPECT_EQ(result, 157);
}

TEST(Vector2, Dot)
{
	Vector2 a, b;
	float result;

	//Vector2::Dot(Vector2, Vector2)
	a = Vector2(4, 5), b = Vector2(-3, -6);
	EXPECT_EQ(Vector2::Dot(a, b), -42);
	Vector2::Dot(a, b, result);
	EXPECT_EQ(result, -42);
}

TEST(Vector2, Clamp_Normalize)
{
	Vector2 vector;
	Vector2 min, max;
	Vector2 result;

	//Vector2::Clamp(Vector2, Vector2, Vector2)
	vector = Vector2(20, -10);
	min = Vector2(1, 2), max = Vector2(10, 9);
	EXPECT_VECTOR_EQ(Vector2::Clamp(vector, min, max), 10, 2);
	Vector2::Clamp(vector, min, max, result);
	EXPECT_VECTOR_EQ(result, 10, 2);

	//Normalize
	vector = Vector2(2, 4);
	vector.Normalize();
	EXPECT_VECTOR_NEAR(vector, 0.45f, 0.89f, 0.01f);
	EXPECT_NEAR(vector.Length(), 1, 0.001f);

	//Vector2::Normalize
	vector = Vector2(6, -4);
	EXPECT_VECTOR_NEAR(Vector2::Normalize(vector), 0.83f, -0.55f, 0.01f);
	Vector2::Normalize(vector, result);
	EXPECT_VECTOR_NEAR(result, 0.83f, -0.55f, 0.01f);
}