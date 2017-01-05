#pragma once

namespace CFH {

	struct Vector2
	{
	public:
		float X; float Y;

		Vector2();
		Vector2(float value);
		Vector2(float x, float y);
		~Vector2();

		static const Vector2 UnitX;
		static const Vector2 UnitY;
		static const Vector2 One;
		static const Vector2 Zero;
		static const Vector2 Up;
		static const Vector2 Down;
		static const Vector2 Right;
		static const Vector2 Left;

		Vector2 operator+(Vector2 vector) const;
		Vector2 operator-(Vector2 vector) const;
		Vector2 operator-() const;
		Vector2 operator*(Vector2 vector) const;
		Vector2 operator*(float value) const;
		Vector2 operator/(Vector2 vector) const;
		Vector2 operator/(float value) const;
		Vector2 operator+=(Vector2 vector);
		Vector2 operator-=(Vector2 vector);
		Vector2 operator*=(Vector2 vector);
		Vector2 operator*=(float value);
		Vector2 operator/=(Vector2 vector);
		Vector2 operator/=(float value);
		bool operator==(Vector2 vector) const;
		bool operator!=(Vector2 vector) const;
		Vector2 operator=(Vector2 vector);

		static Vector2 Add(Vector2 lhs, Vector2 rhs);
		static void Add(Vector2 lhs, Vector2 rhs, Vector2& result);
		static Vector2 Subtract(Vector2 lhs, Vector2 rhs);
		static void Subtract(Vector2 lhs, Vector2 rhs, Vector2& result);
		static Vector2 Multiply(Vector2 lhs, Vector2 rhs);
		static void Multiply(Vector2 lhs, Vector2 rhs, Vector2& result);
		static Vector2 Multiply(Vector2 vector, float value);
		static void Multiply(Vector2 vector, float value, Vector2& result);
		static Vector2 Divide(Vector2 lhs, Vector2 rhs);
		static void Divide(Vector2 lhs, Vector2 rhs, Vector2& result);
		static Vector2 Divide(Vector2 vector, float value);
		static void Divide(Vector2 vector, float value, Vector2& result);
		static Vector2 Negate(Vector2 vector);
		static void Negate(Vector2 vector, Vector2& result);
	};
}

