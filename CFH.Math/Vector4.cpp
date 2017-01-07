#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"
#include "MathHelper.h"

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
	Vector4::Vector4(std::initializer_list<float> list)
	{
		auto it = list.begin();
		X = *(it++);
		Y = *(it++);
		Z = *(it++);
		W = *it;
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

	float Vector4::Length() const
	{
		float result;
		Length(*this, result);
		return result;
	}
	void Vector4::Length(float& result) const
	{
		Length(*this, result);
	}
	float Vector4::Length(Vector4 vector)
	{
		float result;
		Length(vector, result);
		return result;
	}
	void Vector4::Length(Vector4 vector, float& result)
	{
		LengthSquared(vector, result);
		result = MathHelper::Sqrt(result);
	}

	float Vector4::LengthSquared() const
	{
		float result;
		LengthSquared(*this, result);
		return result;
	}
	void Vector4::LengthSquared(float& result) const
	{
		LengthSquared(*this, result);
	}
	float Vector4::LengthSquared(Vector4 vector)
	{
		float result;
		LengthSquared(vector, result);
		return result;
	}
	void Vector4::LengthSquared(Vector4 vector, float& result)
	{
		result = (vector.X * vector.X) + (vector.Y * vector.Y) +
			(vector.Z * vector.Z) + (vector.W * vector.W);
	}

	float Vector4::Distance(Vector4 lhs, Vector4 rhs)
	{
		float result;
		Distance(lhs, rhs, result);
		return result;
	}
	void Vector4::Distance(Vector4 lhs, Vector4 rhs, float& result)
	{
		DistanceSquared(lhs, rhs, result);
		result = MathHelper::Sqrt(result);
	}
	float Vector4::DistanceSquared(Vector4 lhs, Vector4 rhs)
	{
		float result;
		DistanceSquared(lhs, rhs, result);
		return result;
	}
	void Vector4::DistanceSquared(Vector4 lhs, Vector4 rhs, float& result)
	{
		float deltaX, deltaY, deltaZ, deltaW;
		deltaX = rhs.X - lhs.X;
		deltaY = rhs.Y - lhs.Y;
		deltaZ = rhs.Z - lhs.Z;
		deltaW = rhs.W - lhs.W;
		result = (deltaX * deltaX) + (deltaY * deltaY) +
			(deltaZ * deltaZ) + (deltaW * deltaW);
	}

	float Vector4::Dot(Vector4 lhs, Vector4 rhs)
	{
		float result;
		Dot(lhs, rhs, result);
		return result;
	}
	void Vector4::Dot(Vector4 lhs, Vector4 rhs, float& result)
	{
		result = (lhs.X * rhs.X) + (lhs.Y * rhs.Y) +
			(lhs.Z * rhs.Z) + (lhs.W * rhs.W);
	}

	Vector4 Vector4::Clamp(Vector4 vector, Vector4 min, Vector4 max)
	{
		Vector4 result;
		Clamp(vector, min, max, result);
		return result;
	}
	void Vector4::Clamp(Vector4 vector, Vector4 min, Vector4 max, Vector4& result)
	{
		MathHelper::Clamp(vector.X, min.X, max.X, result.X);
		MathHelper::Clamp(vector.Y, min.Y, max.Y, result.Y);
		MathHelper::Clamp(vector.Z, min.Z, max.Z, result.Z);
		MathHelper::Clamp(vector.W, min.W, max.W, result.W);
	}
	void Vector4::Normalize()
	{
		float length = Length();
		X /= length;
		Y /= length;
		Z /= length;
		W /= length;
	}
	Vector4 Vector4::Normalize(Vector4 vector)
	{
		Vector4 result;
		Normalize(vector, result);
		return result;
	}
	void Vector4::Normalize(Vector4 vector, Vector4& result)
	{
		float length = Length(vector);
		result.X = vector.X / length;
		result.Y = vector.Y / length;
		result.Z = vector.Z / length;
		result.W = vector.W / length;
	}

	Vector4 Vector4::Transform(Vector4 vector, Matrix4 matrix)
	{
		Vector4 result;
		Transform(vector, matrix, result);
		return result;
	}
	void Vector4::Transform(Vector4 vector, Matrix4 matrix, Vector4& result)
	{
		Vector4 v;
		Vector4::Dot(vector, Vector4(matrix.M11, matrix.M21, matrix.M31, matrix.M41), v.X);
		Vector4::Dot(vector, Vector4(matrix.M12, matrix.M22, matrix.M32, matrix.M42), v.Y);
		Vector4::Dot(vector, Vector4(matrix.M13, matrix.M23, matrix.M33, matrix.M43), v.Z);
		Vector4::Dot(vector, Vector4(matrix.M14, matrix.M24, matrix.M34, matrix.M44), v.W);
		result = v;
	}
}