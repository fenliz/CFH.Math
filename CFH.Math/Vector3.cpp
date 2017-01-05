#include "Vector3.h"

#include "Vector2.h"

namespace CFH
{
	const Vector3 Vector3::UnitX = Vector3(1, 0, 0);
	const Vector3 Vector3::UnitY = Vector3(0, 1, 0);
	const Vector3 Vector3::UnitZ = Vector3(0, 0, 1);
	const Vector3 Vector3::One = Vector3(1, 1, 1);
	const Vector3 Vector3::Zero = Vector3(0, 0, 0);
	const Vector3 Vector3::Forward = Vector3(0, 0, -1);
	const Vector3 Vector3::Backward = Vector3(0, 0, 1);
	const Vector3 Vector3::Up = Vector3(0, 1, 0);
	const Vector3 Vector3::Down = Vector3(0, -1, 0);
	const Vector3 Vector3::Right = Vector3(1, 0, 0);
	const Vector3 Vector3::Left = Vector3(-1, 0, 0);

	Vector3::Vector3() :
		X(0),
		Y(0),
		Z(0)
	{
	}
	Vector3::Vector3(float value) :
		X(value),
		Y(value),
		Z(value)
	{
	}
	Vector3::Vector3(Vector2 vector, float z) :
		X(vector.X),
		Y(vector.Y),
		Z(z)
	{
	}
	Vector3::Vector3(float x, float y, float z) :
		X(x),
		Y(y),
		Z(z)
	{
	}
	Vector3::~Vector3()
	{
	}

	Vector3 Vector3::operator+(Vector3 vector) const
	{
		return Vector3(X + vector.X, Y + vector.Y, Z + vector.Z);
	}
	Vector3 Vector3::operator-(Vector3 vector) const
	{
		return Vector3(X - vector.X, Y - vector.Y, Z - vector.Z);
	}
	Vector3 Vector3::operator-() const
	{
		return Vector3(-X, -Y, -Z);
	}
	Vector3 Vector3::operator*(Vector3 vector) const
	{
		return Vector3(X * vector.X, Y * vector.Y, Z * vector.Z);
	}
	Vector3 Vector3::operator*(float value) const
	{
		return Vector3(X * value, Y * value, Z * value);
	}
	Vector3 Vector3::operator/(Vector3 vector) const
	{
		return Vector3(X / vector.X, Y / vector.Y, Z / vector.Z);
	}
	Vector3 Vector3::operator/(float value) const
	{
		return Vector3(X / value, Y / value, Z / value);
	}
	Vector3 Vector3::operator+=(Vector3 vector)
	{
		X += vector.X;
		Y += vector.Y;
		Z += vector.Z;
		return *this;
	}
	Vector3 Vector3::operator-=(Vector3 vector)
	{
		X -= vector.X;
		Y -= vector.Y;
		Z -= vector.Z;
		return *this;
	}
	Vector3 Vector3::operator*=(Vector3 vector)
	{
		X *= vector.X;
		Y *= vector.Y;
		Z *= vector.Z;
		return *this;
	}
	Vector3 Vector3::operator*=(float value)
	{
		X *= value;
		Y *= value;
		Z *= value;
		return *this;
	}
	Vector3 Vector3::operator/=(Vector3 vector)
	{
		X /= vector.X;
		Y /= vector.Y;
		Z /= vector.Z;
		return *this;
	}
	Vector3 Vector3::operator/=(float value)
	{
		X /= value;
		Y /= value;
		Z /= value;
		return *this;
	}
	bool Vector3::operator==(Vector3 vector) const
	{
		return (X == vector.X && Y == vector.Y && Z == vector.Z);
	}
	bool Vector3::operator!=(Vector3 vector) const
	{
		return (X != vector.X || Y != vector.Y || Z != vector.Z);
	}
	Vector3 Vector3::operator=(Vector3 vector)
	{
		X = vector.X;
		Y = vector.Y;
		Z = vector.Z;
		return *this;
	}

	Vector3 Vector3::Add(Vector3 lhs, Vector3 rhs)
	{
		Vector3 result;
		Add(lhs, rhs, result);
		return result;
	}
	void Vector3::Add(Vector3 lhs, Vector3 rhs, Vector3& result)
	{
		result.X = lhs.X + rhs.X;
		result.Y = lhs.Y + rhs.Y;
		result.Z = lhs.Z + rhs.Z;
	}
	Vector3 Vector3::Subtract(Vector3 lhs, Vector3 rhs)
	{
		Vector3 result;
		Subtract(lhs, rhs, result);
		return result;
	}
	void Vector3::Subtract(Vector3 lhs, Vector3 rhs, Vector3& result)
	{
		result.X = lhs.X - rhs.X;
		result.Y = lhs.Y - rhs.Y;
		result.Z = lhs.Z - rhs.Z;
	}
	Vector3 Vector3::Multiply(Vector3 lhs, Vector3 rhs)
	{
		Vector3 result;
		Multiply(lhs, rhs, result);
		return result;
	}
	void Vector3::Multiply(Vector3 lhs, Vector3 rhs, Vector3& result)
	{
		result.X = lhs.X * rhs.X;
		result.Y = lhs.Y * rhs.Y;
		result.Z = lhs.Z * rhs.Z;
	}
	Vector3 Vector3::Multiply(Vector3 vector, float value)
	{
		Vector3 result;
		Multiply(vector, value, result);
		return result;
	}
	void Vector3::Multiply(Vector3 vector, float value, Vector3& result)
	{
		result.X = vector.X * value;
		result.Y = vector.Y * value;
		result.Z = vector.Z * value;
	}
	Vector3 Vector3::Divide(Vector3 lhs, Vector3 rhs)
	{
		Vector3 result;
		Divide(lhs, rhs, result);
		return result;
	}
	void Vector3::Divide(Vector3 lhs, Vector3 rhs, Vector3& result)
	{
		result.X = lhs.X / rhs.X;
		result.Y = lhs.Y / rhs.Y;
		result.Z = lhs.Z / rhs.Z;
	}
	Vector3 Vector3::Divide(Vector3 vector, float value)
	{
		Vector3 result;
		Divide(vector, value, result);
		return result;
	}
	void Vector3::Divide(Vector3 vector, float value, Vector3& result)
	{
		result.X = vector.X / value;
		result.Y = vector.Y / value;
		result.Z = vector.Z / value;
	}
	Vector3 Vector3::Negate(Vector3 vector)
	{
		Vector3 result;
		Negate(vector, result);
		return result;
	}
	void Vector3::Negate(Vector3 vector, Vector3& result)
	{
		result.X = -vector.X;
		result.Y = -vector.Y;
		result.Z = -vector.Z;
	}
}
