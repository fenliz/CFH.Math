#pragma once
#include "Common.h"
#include <initializer_list>

namespace CFH 
{
	namespace Math
	{
		struct DLL_API Vector2 final
		{
		public:
			static const Vector2 UnitX;
			static const Vector2 UnitY;
			static const Vector2 One;
			static const Vector2 Zero;
			static const Vector2 Up;
			static const Vector2 Down;
			static const Vector2 Right;
			static const Vector2 Left;

			float X; float Y;

			Vector2();
			Vector2(float value);
			Vector2(float x, float y);
			Vector2(std::initializer_list<float>);
			~Vector2();

			Vector2 operator+(const Vector2& vector) const;
			Vector2 operator-(const Vector2& vector) const;
			Vector2 operator-() const;
			Vector2 operator*(const Vector2& vector) const;
			Vector2 operator*(float value) const;
			Vector2 operator/(const Vector2& vector) const;
			Vector2 operator/(float value) const;
			const Vector2& operator+=(const Vector2& vector);
			const Vector2& operator-=(const Vector2& vector);
			const Vector2& operator*=(const Vector2& vector);
			const Vector2& operator*=(float value);
			const Vector2& operator/=(const Vector2& vector);
			const Vector2& operator/=(float value);
			bool operator==(const Vector2& vector) const;
			bool operator!=(const Vector2& vector) const;
			const Vector2& operator=(const Vector2& vector);

			static Vector2 Add(const Vector2& lhs, const Vector2& rhs);
			static void Add(const Vector2& lhs, const Vector2& rhs, Vector2& result);
			static Vector2 Subtract(const Vector2& lhs, const Vector2& rhs);
			static void Subtract(const Vector2& lhs, const Vector2& rhs, Vector2& result);
			static Vector2 Multiply(const Vector2& lhs, const Vector2& rhs);
			static void Multiply(const Vector2& lhs, const Vector2& rhs, Vector2& result);
			static Vector2 Multiply(const Vector2& vector, float value);
			static void Multiply(const Vector2& vector, float value, Vector2& result);
			static Vector2 Divide(const Vector2& lhs, const Vector2& rhs);
			static void Divide(const Vector2& lhs, const Vector2& rhs, Vector2& result);
			static Vector2 Divide(const Vector2& vector, float value);
			static void Divide(const Vector2& vector, float value, Vector2& result);
			static Vector2 Negate(const Vector2& vector);
			static void Negate(const Vector2& vector, Vector2& result);

			float Length() const;
			void Length(float& result) const;
			static float Length(const Vector2& vector);
			static void Length(const Vector2& vector, float& result);
			float LengthSquared() const;
			void LengthSquared(float& result) const;
			static float LengthSquared(const Vector2& vector);
			static void LengthSquared(const Vector2& vector, float& result);

			static float Distance(const Vector2& lhs, const Vector2& rhs);
			static void Distance(const Vector2& lhs, const Vector2& rhs, float& result);
			static float DistanceSquared(const Vector2& lhs, const Vector2& rhs);
			static void DistanceSquared(const Vector2& lhs, const Vector2& rhs, float& result);

			static float Dot(const Vector2& lhs, const Vector2& rhs);
			static void Dot(const Vector2& lhs, const Vector2& rhs, float& result);

			static Vector2 Clamp(const Vector2& value, const Vector2& min, const Vector2& max);
			static void Clamp(const Vector2& value, const Vector2& min, const Vector2& max, Vector2& result);
			void Normalize();
			static Vector2 Normalize(const Vector2& vector);
			static void Normalize(const Vector2& vector, Vector2& result);
		};
	}
}

