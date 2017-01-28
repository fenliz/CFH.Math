#pragma once
#include "Common.h"
#include <initializer_list>

namespace CFH
{
	namespace Math
	{
		struct Vector2;
		struct Vector3;
		struct Matrix4;

		struct DLL_API Vector4 final
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
			Vector4(const Vector2& vector, float z, float w);
			Vector4(const Vector3& vector, float w);
			Vector4(float x, float y, float z, float w);
			Vector4(std::initializer_list<float>);
			~Vector4();

			Vector4 operator+(const Vector4& vector) const;
			Vector4 operator-(const Vector4& vector) const;
			Vector4 operator-() const;
			Vector4 operator*(const Vector4& vector) const;
			Vector4 operator*(float value) const;
			Vector4 operator/(const Vector4& vector) const;
			Vector4 operator/(float value) const;
			const Vector4& operator+=(const Vector4& vector);
			const Vector4& operator-=(const Vector4& vector);
			const Vector4& operator*=(const Vector4& vector);
			const Vector4& operator*=(float value);
			const Vector4& operator/=(const Vector4& vector);
			const Vector4& operator/=(float value);
			bool operator==(const Vector4& vector) const;
			bool operator!=(const Vector4& vector) const;
			const Vector4& operator=(const Vector4& vector);

			static Vector4 Add(const Vector4& lhs, const Vector4& rhs);
			static void Add(const Vector4& lhs, const Vector4& rhs, Vector4& result);
			static Vector4 Subtract(const Vector4& lhs, const Vector4& rhs);
			static void Subtract(const Vector4& lhs, const Vector4& rhs, Vector4& result);
			static Vector4 Multiply(const Vector4& lhs, const Vector4& rhs);
			static void Multiply(const Vector4& lhs, const Vector4& rhs, Vector4& result);
			static Vector4 Multiply(const Vector4& vector, float value);
			static void Multiply(const Vector4& vector, float value, Vector4& result);
			static Vector4 Divide(const Vector4& lhs, const Vector4& rhs);
			static void Divide(const Vector4& lhs, const Vector4& rhs, Vector4& result);
			static Vector4 Divide(const Vector4& vector, float value);
			static void Divide(const Vector4& vector, float value, Vector4& result);
			static Vector4 Negate(const Vector4& vector);
			static void Negate(const Vector4& vector, Vector4& result);

			float Length() const;
			void Length(float& result) const;
			static float Length(const Vector4& vector);
			static void Length(const Vector4& vector, float& result);
			float LengthSquared() const;
			void LengthSquared(float& result) const;
			static float LengthSquared(const Vector4& vector);
			static void LengthSquared(const Vector4& vector, float& result);

			static float Distance(const Vector4& lhs, const Vector4& rhs);
			static void Distance(const Vector4& lhs, const Vector4& rhs, float& result);
			static float DistanceSquared(const Vector4& lhs, const Vector4& rhs);
			static void DistanceSquared(const Vector4& lhs, const Vector4& rhs, float& result);

			static float Dot(const Vector4& lhs, const Vector4& rhs);
			static void Dot(const Vector4& lhs, const Vector4& rhs, float& result);

			static Vector4 Clamp(const Vector4& vector, const Vector4& min, const Vector4& max);
			static void Clamp(const Vector4& vector, const Vector4& min, const Vector4& max, Vector4& result);
			void Normalize();
			static Vector4 Normalize(const Vector4& vector);
			static void Normalize(const Vector4& vector, Vector4& result);

			static Vector4 Transform(const Vector4& vector, const Matrix4& matrix);
			static void Transform(const Vector4& vector, const Matrix4& matrix, Vector4& result);
		};
	}
}

