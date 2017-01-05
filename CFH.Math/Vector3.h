#pragma once

namespace CFH
{
	class Vector2;

	class Vector3
	{
	public:
		static const Vector3 UnitX;
		static const Vector3 UnitY;
		static const Vector3 UnitZ;
		static const Vector3 One;
		static const Vector3 Zero;
		static const Vector3 Forward;
		static const Vector3 Backward;
		static const Vector3 Up;
		static const Vector3 Down;
		static const Vector3 Right;
		static const Vector3 Left;

		float X; float Y; float Z;

		Vector3();
		Vector3(float value);
		Vector3(Vector2 vector, float z);
		Vector3(float x, float y, float z);
		~Vector3();

		Vector3 operator+(Vector3 vector) const;
		Vector3 operator-(Vector3 vector) const;
		Vector3 operator-() const;
		Vector3 operator*(Vector3 vector) const;
		Vector3 operator*(float value) const;
		Vector3 operator/(Vector3 vector) const;
		Vector3 operator/(float value) const;
		Vector3 operator+=(Vector3 vector);
		Vector3 operator-=(Vector3 vector);
		Vector3 operator*=(Vector3 vector);
		Vector3 operator*=(float value);
		Vector3 operator/=(Vector3 vector);
		Vector3 operator/=(float value);
		bool operator==(Vector3 vector) const;
		bool operator!=(Vector3 vector) const;
		Vector3 operator=(Vector3 vector);

		static Vector3 Add(Vector3 lhs, Vector3 rhs);
		static void Add(Vector3 lhs, Vector3 rhs, Vector3& result);
		static Vector3 Subtract(Vector3 lhs, Vector3 rhs);
		static void Subtract(Vector3 lhs, Vector3 rhs, Vector3& result);
		static Vector3 Multiply(Vector3 lhs, Vector3 rhs);
		static void Multiply(Vector3 lhs, Vector3 rhs, Vector3& result);
		static Vector3 Multiply(Vector3 vector, float value);
		static void Multiply(Vector3 vector, float value, Vector3& result);
		static Vector3 Divide(Vector3 lhs, Vector3 rhs);
		static void Divide(Vector3 lhs, Vector3 rhs, Vector3& result);
		static Vector3 Divide(Vector3 vector, float value);
		static void Divide(Vector3 vector, float value, Vector3& result);
		static Vector3 Negate(Vector3 vector);
		static void Negate(Vector3 vector, Vector3& result);
	};
}

