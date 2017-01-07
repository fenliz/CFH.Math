#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"
#include "Quaternion.h"
#include "MathHelper.h"

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
	Vector3::Vector3(std::initializer_list<float> list)
	{
		auto it = list.begin();
		X = *(it++);
		Y = *(it++);
		Z = *it;
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
	Vector3 operator*(float value, Vector3 v)
	{
		return v * value;
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

	float Vector3::Length() const
	{
		float result;
		Length(*this, result);
		return result;
	}
	void Vector3::Length(float& result) const
	{
		Length(*this, result);
	}
	float Vector3::Length(Vector3 vector)
	{
		float result;
		Length(vector, result);
		return result;
	}
	void Vector3::Length(Vector3 vector, float& result)
	{
		LengthSquared(vector, result);
		result = MathHelper::Sqrt(result);
	}

	float Vector3::LengthSquared() const
	{
		float result;
		LengthSquared(*this, result);
		return result;
	}
	void Vector3::LengthSquared(float& result) const
	{
		LengthSquared(*this, result);
	}
	float Vector3::LengthSquared(Vector3 vector)
	{
		float result;
		LengthSquared(vector, result);
		return result;
	}
	void Vector3::LengthSquared(Vector3 vector, float& result)
	{
		result = (vector.X * vector.X) + (vector.Y * vector.Y) +
			(vector.Z * vector.Z);
	}

	float Vector3::Distance(Vector3 lhs, Vector3 rhs)
	{
		float result;
		Distance(lhs, rhs, result);
		return result;
	}
	void Vector3::Distance(Vector3 lhs, Vector3 rhs, float& result)
	{
		DistanceSquared(lhs, rhs, result);
		result = MathHelper::Sqrt(result);
	}
	float Vector3::DistanceSquared(Vector3 lhs, Vector3 rhs)
	{
		float result;
		DistanceSquared(lhs, rhs, result);
		return result;
	}
	void Vector3::DistanceSquared(Vector3 lhs, Vector3 rhs, float& result)
	{
		float deltaX, deltaY, deltaZ;
		deltaX = rhs.X - lhs.X;
		deltaY = rhs.Y - lhs.Y;
		deltaZ = rhs.Z - lhs.Z;
		result = (deltaX * deltaX) + (deltaY * deltaY) +
			(deltaZ * deltaZ);
	}

	float Vector3::Dot(Vector3 lhs, Vector3 rhs)
	{
		float result;
		Dot(lhs, rhs, result);
		return result;
	}
	void Vector3::Dot(Vector3 lhs, Vector3 rhs, float& result)
	{
		result = (lhs.X * rhs.X) + (lhs.Y * rhs.Y) +
			(lhs.Z * rhs.Z);
	}

	Vector3 Vector3::Cross(Vector3 lhs, Vector3 rhs)
	{
		Vector3 result;
		Cross(lhs, rhs, result);
		return result;
	}
	void Vector3::Cross(Vector3 lhs, Vector3 rhs, Vector3& result)
	{
		result.X = (lhs.Y * rhs.Z) - (lhs.Z * rhs.Y);
		result.Y = (lhs.Z * rhs.X) - (lhs.X * rhs.Z);
		result.Z = (lhs.X * rhs.Y) - (lhs.Y * rhs.X);
	}

	Vector3 Vector3::Clamp(Vector3 value, Vector3 min, Vector3 max)
	{
		Vector3 result;
		Clamp(value, min, max, result);
		return result;
	}
	void Vector3::Clamp(Vector3 value, Vector3 min, Vector3 max, Vector3& result)
	{
		MathHelper::Clamp(value.X, min.X, max.X, result.X);
		MathHelper::Clamp(value.Y, min.Y, max.Y, result.Y);
		MathHelper::Clamp(value.Z, min.Z, max.Z, result.Z);
	}

	void Vector3::Normalize()
	{
		float length = Length();
		X /= length;
		Y /= length;
		Z /= length;
	}
	Vector3 Vector3::Normalize(Vector3 vector)
	{
		Vector3 result;
		Normalize(vector, result);
		return result;
	}
	void Vector3::Normalize(Vector3 vector, Vector3& result)
	{
		float length = Length(vector);
		result.X = vector.X / length;
		result.Y = vector.Y / length;
		result.Z = vector.Z / length;
	}

	Vector3 Vector3::Transform(Vector3 vector, Matrix4 matrix)
	{
		Vector3 result;
		Transform(vector, matrix, result);
		return result;
	}
	void Vector3::Transform(Vector3 vector, Matrix4 matrix, Vector3& result)
	{
		Vector3 v;
		Vector4::Dot(Vector4(vector.X, vector.Y, vector.Z, 1), Vector4(matrix.M11, matrix.M21, matrix.M31, matrix.M41), v.X);
		Vector4::Dot(Vector4(vector.X, vector.Y, vector.Z, 1), Vector4(matrix.M12, matrix.M22, matrix.M32, matrix.M42), v.Y);
		Vector4::Dot(Vector4(vector.X, vector.Y, vector.Z, 1), Vector4(matrix.M13, matrix.M23, matrix.M33, matrix.M43), v.Z);
		result = v;
	}
	Vector3 Vector3::Transform(Vector3 vector, Quaternion rotation)
	{
		Vector3 result;
		Transform(vector, rotation, result);
		return result;
	}
	void Vector3::Transform(Vector3 vector, Quaternion rotation, Vector3& result)
	{
		Vector3 u = Vector3(rotation.X, rotation.Y, rotation.Z);
		float s = rotation.W;

		result = 2.0f * Vector3::Dot(u, vector) * u
			+ (s * s - Vector3::Dot(u, u)) * vector
			+ 2.0f * s * Vector3::Cross(u, vector);
	}
	Vector3 Vector3::TransformNormal(Vector3 normal, Matrix4 matrix)
	{
		Vector3 result;
		TransformNormal(normal, matrix, result);
		return result;
	}
	void Vector3::TransformNormal(Vector3 vector, Matrix4 matrix, Vector3& result)
	{
		Vector4::Dot(Vector4(vector.X, vector.Y, vector.Z, 1), Vector4(matrix.M11, matrix.M21, matrix.M31, 0), result.X);
		Vector4::Dot(Vector4(vector.X, vector.Y, vector.Z, 1), Vector4(matrix.M12, matrix.M22, matrix.M32, 0), result.Y);
		Vector4::Dot(Vector4(vector.X, vector.Y, vector.Z, 1), Vector4(matrix.M13, matrix.M23, matrix.M33, 0), result.Z);
	}
}
