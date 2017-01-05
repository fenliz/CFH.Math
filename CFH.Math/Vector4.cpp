#include "Vector4.h"

#include "Vector2.h"
#include "Vector3.h"

namespace CFH
{
	const Vector4 Vector4::UnitX = Vector4(1, 0, 0, 0);
	const Vector4 Vector4::UnitY = Vector4(0, 1, 0, 0);
	const Vector4 Vector4::UnitZ = Vector4(0, 0, 1, 0);
	const Vector4 Vector4::UnitW = Vector4(0, 0, 0, 1);
	const Vector4 Vector4::Zero = Vector4(0, 0, 0, 0);
	const Vector4 Vector4::One = Vector4(1, 1, 1, 1);

	Vector4::Vector4() :
		X(0),
		Y(0),
		Z(0),
		W(0)
	{
	}
	Vector4::Vector4(float value) :
		X(value),
		Y(value),
		Z(value),
		W(value)
	{
	}
	Vector4::Vector4(Vector2 vector, float z, float w) :
		X(vector.X),
		Y(vector.Y),
		Z(z),
		W(w)
	{
	}
	Vector4::Vector4(Vector3 vector, float w) :
		X(vector.X),
		Y(vector.Y),
		Z(vector.Z),
		W(w)
	{
	}
	Vector4::Vector4(float x, float y, float z, float w) :
		X(x),
		Y(y),
		Z(z),
		W(w)
	{
	}
	Vector4::~Vector4()
	{
	}

	Vector4 Vector4::operator+(Vector4 vector) const
	{
		return Vector4(X + vector.X, Y + vector.Y, Z + vector.Z, W + vector.W);
	}
	Vector4 Vector4::operator-(Vector4 vector) const
	{
		return Vector4(X - vector.X, Y - vector.Y, Z - vector.Z, W - vector.W);
	}
	Vector4 Vector4::operator-() const
	{
		return Vector4(-X, -Y, -Z, -W);
	}
	Vector4 Vector4::operator*(Vector4 vector) const
	{
		return Vector4(X * vector.X, Y * vector.Y, Z * vector.Z, W * vector.W);
	}
	Vector4 Vector4::operator*(float value) const
	{
		return Vector4(X * value, Y * value, Z * value, W * value);
	}
	Vector4 Vector4::operator/(Vector4 vector) const
	{
		return Vector4(X / vector.X, Y / vector.Y, Z / vector.Z, W / vector.W);
	}
	Vector4 Vector4::operator/(float value) const
	{
		return Vector4(X / value, Y / value, Z / value, W / value);
	}
	Vector4 Vector4::operator+=(Vector4 vector)
	{
		X += vector.X;
		Y += vector.Y;
		Z += vector.Z;
		W += vector.W;
		return *this;
	}
	Vector4 Vector4::operator-=(Vector4 vector)
	{
		X -= vector.X;
		Y -= vector.Y;
		Z -= vector.Z;
		W -= vector.W;
		return *this;
	}
	Vector4 Vector4::operator*=(Vector4 vector)
	{
		X *= vector.X;
		Y *= vector.Y;
		Z *= vector.Z;
		W *= vector.W;
		return *this;
	}
	Vector4 Vector4::operator*=(float value)
	{
		X *= value;
		Y *= value;
		Z *= value;
		W *= value;
		return *this;
	}
	Vector4 Vector4::operator/=(Vector4 vector)
	{
		X /= vector.X;
		Y /= vector.Y;
		Z /= vector.Z;
		W /= vector.W;
		return *this;
	}
	Vector4 Vector4::operator/=(float value)
	{
		X /= value;
		Y /= value;
		Z /= value;
		W /= value;
		return *this;
	}
	bool Vector4::operator==(Vector4 vector) const
	{
		return (X == vector.X && Y == vector.Y && Z == vector.Z && W == vector.W);
	}
	bool Vector4::operator!=(Vector4 vector) const
	{
		return (X != vector.X || Y != vector.Y || Z != vector.Z || W != vector.W);
	}
	Vector4 Vector4::operator=(Vector4 vector)
	{
		X = vector.X;
		Y = vector.Y;
		Z = vector.Z;
		W = vector.W;
		return *this;
	}

	Vector4 Vector4::Add(Vector4 lhs, Vector4 rhs)
	{
		Vector4 result;
		Add(lhs, rhs, result);
		return result;
	}
	void Vector4::Add(Vector4 lhs, Vector4 rhs, Vector4& result)
	{
		result.X = lhs.X + rhs.X;
		result.Y = lhs.Y + rhs.Y;
		result.Z = lhs.Z + rhs.Z;
		result.W = lhs.W + rhs.W;
	}
	Vector4 Vector4::Subtract(Vector4 lhs, Vector4 rhs)
	{
		Vector4 result;
		Subtract(lhs, rhs, result);
		return result;
	}
	void Vector4::Subtract(Vector4 lhs, Vector4 rhs, Vector4& result)
	{
		result.X = lhs.X - rhs.X;
		result.Y = lhs.Y - rhs.Y;
		result.Z = lhs.Z - rhs.Z;
		result.W = lhs.W - rhs.W;
	}
	Vector4 Vector4::Multiply(Vector4 lhs, Vector4 rhs)
	{
		Vector4 result;
		Multiply(lhs, rhs, result);
		return result;
	}
	void Vector4::Multiply(Vector4 lhs, Vector4 rhs, Vector4& result)
	{
		result.X = lhs.X * rhs.X;
		result.Y = lhs.Y * rhs.Y;
		result.Z = lhs.Z * rhs.Z;
		result.W = lhs.W * rhs.W;
	}
	Vector4 Vector4::Multiply(Vector4 vector, float value)
	{
		Vector4 result;
		Multiply(vector, value, result);
		return result;
	}
	void Vector4::Multiply(Vector4 vector, float value, Vector4& result)
	{
		result.X = vector.X * value;
		result.Y = vector.Y * value;
		result.Z = vector.Z * value;
		result.W = vector.W * value;
	}
	Vector4 Vector4::Divide(Vector4 lhs, Vector4 rhs)
	{
		Vector4 result;
		Divide(lhs, rhs, result);
		return result;
	}
	void Vector4::Divide(Vector4 lhs, Vector4 rhs, Vector4& result)
	{
		result.X = lhs.X / rhs.X;
		result.Y = lhs.Y / rhs.Y;
		result.Z = lhs.Z / rhs.Z;
		result.W = lhs.W / rhs.W;
	}
	Vector4 Vector4::Divide(Vector4 vector, float value)
	{
		Vector4 result;
		Divide(vector, value, result);
		return result;
	}
	void Vector4::Divide(Vector4 vector, float value, Vector4& result)
	{
		result.X = vector.X / value;
		result.Y = vector.Y / value;
		result.Z = vector.Z / value;
		result.W = vector.W / value;
	}
	Vector4 Vector4::Negate(Vector4 vector)
	{
		Vector4 result;
		Negate(vector, result);
		return result;
	}
	void Vector4::Negate(Vector4 vector, Vector4& result)
	{
		result.X = -vector.X;
		result.Y = -vector.Y;
		result.Z = -vector.Z;
		result.W = -vector.W;
	}
}