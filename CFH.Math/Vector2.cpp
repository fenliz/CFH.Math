#include "Vector2.h"

namespace CFH
{
	const Vector2 Vector2::UnitX = Vector2(1, 0);
	const Vector2 Vector2::UnitY = Vector2(0, 1);
	const Vector2 Vector2::One = Vector2(1, 1);
	const Vector2 Vector2::Zero = Vector2(0, 0);
	const Vector2 Vector2::Up = Vector2(0, 1);
	const Vector2 Vector2::Down = Vector2(0, -1);
	const Vector2 Vector2::Right = Vector2(1, 0);
	const Vector2 Vector2::Left = Vector2(-1, 0);

	Vector2::Vector2() :
		X(0),
		Y(0)
	{
	}
	Vector2::Vector2(float value) :
		X(value),
		Y(value)
	{
	}
	Vector2::Vector2(float x, float y) :
		X(x),
		Y(y)
	{
	}
	Vector2::~Vector2()
	{
	}

	Vector2 Vector2::operator+(Vector2 vector) const
	{
		return Vector2(X + vector.X, Y + vector.Y);
	}
	Vector2 Vector2::operator-(Vector2 vector) const
	{
		return Vector2(X - vector.X, Y - vector.Y);
	}
	Vector2 Vector2::operator-() const
	{
		return Vector2(-X, -Y);
	}
	Vector2 Vector2::operator*(Vector2 vector) const
	{
		return Vector2(X * vector.X, Y * vector.Y);
	}
	Vector2 Vector2::operator*(float value) const
	{
		return Vector2(X * value, Y * value);
	}
	Vector2 Vector2::operator/(Vector2 vector) const
	{
		return Vector2(X / vector.X, Y / vector.Y);
	}
	Vector2 Vector2::operator/(float value) const
	{
		return Vector2(X / value, Y / value);
	}
	Vector2 Vector2::operator+=(Vector2 vector)
	{
		X += vector.X;
		Y += vector.Y;
		return *this;
	}
	Vector2 Vector2::operator-=(Vector2 vector)
	{
		X -= vector.X;
		Y -= vector.Y;
		return *this;
	}
	Vector2 Vector2::operator*=(Vector2 vector)
	{
		X *= vector.X;
		Y *= vector.Y;
		return *this;
	}
	Vector2 Vector2::operator*=(float value)
	{
		X *= value;
		Y *= value;
		return *this;
	}
	Vector2 Vector2::operator/=(Vector2 vector)
	{
		X /= vector.X;
		Y /= vector.Y;
		return *this;
	}
	Vector2 Vector2::operator/=(float value)
	{
		X /= value;
		Y /= value;
		return *this;
	}
	bool Vector2::operator==(Vector2 vector) const
	{
		return (X == vector.X && Y == vector.Y);
	}
	bool Vector2::operator!=(Vector2 vector) const
	{
		return (X != vector.X || Y != vector.Y);
	}
	Vector2 Vector2::operator=(Vector2 vector)
	{
		X = vector.X;
		Y = vector.Y;
		return *this;
	}

	Vector2 Vector2::Add(Vector2 lhs, Vector2 rhs)
	{
		Vector2 result;
		Add(lhs, rhs, result);
		return result;
	}
	void Vector2::Add(Vector2 lhs, Vector2 rhs, Vector2& result)
	{
		result.X = lhs.X + rhs.X;
		result.Y = lhs.Y + rhs.Y;
	}
	Vector2 Vector2::Subtract(Vector2 lhs, Vector2 rhs)
	{
		Vector2 result;
		Subtract(lhs, rhs, result);
		return result;
	}
	void Vector2::Subtract(Vector2 lhs, Vector2 rhs, Vector2& result)
	{
		result.X = lhs.X - rhs.X;
		result.Y = lhs.Y - rhs.Y;
	}
	Vector2 Vector2::Multiply(Vector2 lhs, Vector2 rhs)
	{
		Vector2 result;
		Multiply(lhs, rhs, result);
		return result;
	}
	void Vector2::Multiply(Vector2 lhs, Vector2 rhs, Vector2& result)
	{
		result.X = lhs.X * rhs.X;
		result.Y = lhs.Y * rhs.Y;
	}
	Vector2 Vector2::Multiply(Vector2 vector, float value)
	{
		Vector2 result;
		Multiply(vector, value, result);
		return result;
	}
	void Vector2::Multiply(Vector2 vector, float value, Vector2& result)
	{
		result.X = vector.X * value;
		result.Y = vector.Y * value;
	}
	Vector2 Vector2::Divide(Vector2 lhs, Vector2 rhs)
	{
		Vector2 result;
		Divide(lhs, rhs, result);
		return result;
	}
	void Vector2::Divide(Vector2 lhs, Vector2 rhs, Vector2& result)
	{
		result.X = lhs.X / rhs.X;
		result.Y = lhs.Y / rhs.Y;
	}
	Vector2 Vector2::Divide(Vector2 vector, float value)
	{
		Vector2 result;
		Divide(vector, value, result);
		return result;
	}
	void Vector2::Divide(Vector2 vector, float value, Vector2& result)
	{
		result.X = vector.X / value;
		result.Y = vector.Y / value;
	}
	Vector2 Vector2::Negate(Vector2 vector)
	{
		Vector2 result;
		Negate(vector, result);
		return result;
	}
	void Vector2::Negate(Vector2 vector, Vector2& result)
	{
		result.X = -vector.X;
		result.Y = -vector.Y;
	}
}
