#pragma once
#include "Common.h"
#include <initializer_list>

namespace CFH
{
	namespace Math
	{
		struct Vector2;
		struct Matrix4;
		struct Quaternion;

		struct DLL_API Vector3 final
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
			Vector3(const Vector2& vector, float z);
			Vector3(float x, float y, float z);
			Vector3(std::initializer_list<float>);
			~Vector3();

			Vector3 operator+(const Vector3& vector) const;
			Vector3 operator-(const Vector3& vector) const;
			Vector3 operator-() const;
			Vector3 operator*(const Vector3& vector) const;
			Vector3 operator*(float value) const;
			Vector3 operator/(const Vector3& vector) const;
			Vector3 operator/(float value) const;
			const Vector3& operator+=(const Vector3& vector);
			const Vector3& operator-=(const Vector3& vector);
			const Vector3& operator*=(const Vector3& vector);
			const Vector3& operator*=(float value);
			const Vector3& operator/=(const Vector3& vector);
			const Vector3& operator/=(float value);
			bool operator==(const Vector3& vector) const;
			bool operator!=(const Vector3& vector) const;
			const Vector3& operator=(const Vector3& vector);

			static Vector3 Add(const Vector3& lhs, const Vector3& rhs);
			static void Add(const Vector3& lhs, const Vector3& rhs, Vector3& result);
			static Vector3 Subtract(const Vector3& lhs, const Vector3& rhs);
			static void Subtract(const Vector3& lhs, const Vector3& rhs, Vector3& result);
			static Vector3 Multiply(const Vector3& lhs, const Vector3& rhs);
			static void Multiply(const Vector3& lhs, const Vector3& rhs, Vector3& result);
			static Vector3 Multiply(const Vector3& vector, float value);
			static void Multiply(const Vector3& vector, float value, Vector3& result);
			static Vector3 Divide(const Vector3& lhs, const Vector3& rhs);
			static void Divide(const Vector3& lhs, const Vector3& rhs, Vector3& result);
			static Vector3 Divide(const Vector3& vector, float value);
			static void Divide(const Vector3& vector, float value, Vector3& result);
			static Vector3 Negate(const Vector3& vector);
			static void Negate(const Vector3& vector, Vector3& result);

			float Length() const;
			void Length(float& result) const;
			static float Length(const Vector3& vector);
			static void Length(const Vector3& vector, float& result);
			float LengthSquared() const;
			void LengthSquared(float& result) const;
			static float LengthSquared(const Vector3& vector);
			static void LengthSquared(const Vector3& vector, float& result);

			static float Distance(const Vector3& lhs, const Vector3& rhs);
			static void Distance(const Vector3& lhs, const Vector3& rhs, float& result);
			static float DistanceSquared(const Vector3& lhs, const Vector3& rhs);
			static void DistanceSquared(const Vector3& lhs, const Vector3& rhs, float& result);

			static float Dot(const Vector3& lhs, const Vector3& rhs);
			static void Dot(const Vector3& lhs, const Vector3& rhs, float& result);
			static Vector3 Cross(const Vector3& lhs, const Vector3& rhs);
			static void Cross(const Vector3& lhs, const Vector3& rhs, Vector3& result);

			static Vector3 Clamp(const Vector3& value, const Vector3& min, const Vector3& max);
			static void Clamp(const Vector3& value, const Vector3& min, const Vector3& max, Vector3& result);
			void Normalize();
			static Vector3 Normalize(const Vector3& vector);
			static void Normalize(const Vector3& vector, Vector3& result);

			static Vector3 Transform(const Vector3& vector, const Matrix4& matrix);
			static void Transform(const Vector3& vector, const Matrix4& matrix, Vector3& result);
			static Vector3 Vector3::Transform(const Vector3& vector, const Quaternion& rotation);
			static void Vector3::Transform(const Vector3& vector, const Quaternion& rotation, Vector3& result);
			static Vector3 Vector3::TransformNormal(const Vector3& vector, const Matrix4& matrix);
			static void Vector3::TransformNormal(const Vector3& vector, const Matrix4& matrix, Vector3& result);
		};
	}
}

