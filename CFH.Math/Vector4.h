#pragma once

namespace CFH
{
	class Vector2;
	class Vector3;

	class Vector4
	{
	public:
		static const Vector4 UnitX;
		static const Vector4 UnitY;
		static const Vector4 UnitZ;
		static const Vector4 UnitW;
		static const Vector4 One;
		static const Vector4 Zero;

		float X; float Y; float Z; float W;

		Vector4();
		Vector4(float value);
		Vector4(Vector2 vector, float z, float w);
		Vector4(Vector3 vector, float w);
		Vector4(float x, float y, float z, float w);
		~Vector4();

		Vector4 operator+(Vector4 vector) const;
		Vector4 operator-(Vector4 vector) const;
		Vector4 operator-() const;
		Vector4 operator*(Vector4 vector) const;
		Vector4 operator*(float value) const;
		Vector4 operator/(Vector4 vector) const;
		Vector4 operator/(float value) const;
		Vector4 operator+=(Vector4 vector);
		Vector4 operator-=(Vector4 vector);
		Vector4 operator*=(Vector4 vector);
		Vector4 operator*=(float value);
		Vector4 operator/=(Vector4 vector);
		Vector4 operator/=(float value);
		bool operator==(Vector4 vector) const;
		bool operator!=(Vector4 vector) const;
		Vector4 operator=(Vector4 vector);

		static Vector4 Add(Vector4 lhs, Vector4 rhs);
		static void Add(Vector4 lhs, Vector4 rhs, Vector4& result);
		static Vector4 Subtract(Vector4 lhs, Vector4 rhs);
		static void Subtract(Vector4 lhs, Vector4 rhs, Vector4& result);
		static Vector4 Multiply(Vector4 lhs, Vector4 rhs);
		static void Multiply(Vector4 lhs, Vector4 rhs, Vector4& result);
		static Vector4 Multiply(Vector4 vector, float value);
		static void Multiply(Vector4 vector, float value, Vector4& result);
		static Vector4 Divide(Vector4 lhs, Vector4 rhs);
		static void Divide(Vector4 lhs, Vector4 rhs, Vector4& result);
		static Vector4 Divide(Vector4 vector, float value);
		static void Divide(Vector4 vector, float value, Vector4& result);
		static Vector4 Negate(Vector4 vector);
		static void Negate(Vector4 vector, Vector4& result);
	};
}

