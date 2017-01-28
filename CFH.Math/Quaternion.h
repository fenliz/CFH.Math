#pragma once
#include "Common.h"

namespace CFH
{
	namespace Math
	{
		struct Vector3;
		struct Vector4;
		struct Matrix4;

		struct DLL_API Quaternion final
		{
		public:
			static const Quaternion Identity;
			float X, Y, Z, W;

			Quaternion();
			Quaternion(float x, float y, float z, float w);
			Quaternion(const Vector3& vector, float w);
			Quaternion(const Vector4& vector);
			~Quaternion();

			Quaternion operator+(const Quaternion& quaternion) const;
			Quaternion operator/(const Quaternion& quaternion) const;
			Quaternion operator/(float scaleFactor) const;
			Quaternion operator*(const Quaternion& quaternion) const;
			Quaternion operator*(float scaleFactor) const;
			Quaternion operator-(const Quaternion& quaternion) const;
			Quaternion operator-() const;
			const Quaternion& operator+=(const Quaternion& quaternion);
			const Quaternion& operator-=(const Quaternion& quaternion);
			const Quaternion& operator*=(const Quaternion& quaternion);
			const Quaternion& operator/=(const Quaternion& quaternion);
			const Quaternion& operator=(const Quaternion& quaternion);
			bool operator==(const Quaternion& quaternion) const;
			bool operator!=(const Quaternion& quaternion) const;

			Vector3 GetForward() const;
			void GetForward(Vector3& result) const;
			Vector3 GetBackward() const;
			void GetBackward(Vector3& result) const;
			Vector3 GetRight() const;
			void GetRight(Vector3& result) const;
			Vector3 GetLeft() const;
			void GetLeft(Vector3& result) const;
			Vector3 GetUp() const;
			void GetUp(Vector3& result) const;
			Vector3 GetDown() const;
			void GetDown(Vector3& result) const;

			static Quaternion Add(const Quaternion& quaternionA, const Quaternion& quaternionB);
			static void Add(const Quaternion& quaternionA, const Quaternion& quaternionB, Quaternion& result);
			static Quaternion Subtract(const Quaternion& quaternionA, const Quaternion& quaternionB);
			static void Subtract(const Quaternion& quaternionA, const Quaternion& quaternionB, Quaternion& result);
			static Quaternion Multiply(const Quaternion& quaternionA, const Quaternion& quaternionB);
			static void Multiply(const Quaternion& quaternionA, const Quaternion& quaternionB, Quaternion& result);
			static Quaternion Multiply(const Quaternion& quaternionA, float scaleFactor);
			static void Multiply(const Quaternion& quaternionA, float scaleFactor, Quaternion& result);
			static Quaternion Divide(const Quaternion& quaternionA, const Quaternion& quaternionB);
			static void Divide(const Quaternion& quaternionA, const Quaternion& quaternionB, Quaternion& result);
			static Quaternion Divide(const Quaternion& quaternionA, float scaleFactor);
			static void Divide(const Quaternion& quaternionA, float scaleFactor, Quaternion& result);
			static Quaternion Negate(const Quaternion& quaternion);
			static void Negate(const Quaternion& quaternion, Quaternion& result);

			static Quaternion CreateFromAxisAngle(const Vector3& axis, float angle);
			static void CreateFromAxisAngle(const Vector3& axis, float angle, Quaternion& result);
			static Quaternion CreateFromRotationMatrix(const Matrix4& matrix);
			static void CreateFromRotationMatrix(const Matrix4& matrix, Quaternion& result);
			static Quaternion CreateFromYawPitchRoll(float yaw, float pitch, float roll);
			static void CreateFromYawPitchRoll(float yaw, float pitch, float roll, Quaternion& result);

			static Quaternion Concatenate(const Quaternion& quaternion, const Quaternion& quaternion2);
			static void Concatenate(const Quaternion& quaternion, const Quaternion& quaternion2, Quaternion& result);
			void Conjugate();
			static Quaternion Conjugate(const Quaternion& quaternion);
			static void Conjugate(const Quaternion& quaternion, Quaternion& result);
			static float Dot(const Quaternion& quaternion, const Quaternion& quaternion2);
			static void Dot(const Quaternion& quaternion, const Quaternion& quaternion2, float& result);
			static Quaternion Inverse(const Quaternion& quaternion);
			static void Inverse(const Quaternion& quaternion, Quaternion& result);
			float Length() const;
			void Length(float& result) const;
			float LengthSquared() const;
			void LengthSquared(float& result) const;
			static Quaternion Lerp(const Quaternion& quaternion, const Quaternion& quaternion2, float amount);
			static void Lerp(const Quaternion& quaternion, const Quaternion& quaternion2, float amount, Quaternion& result);
			void Normalize();
			static Quaternion Normalize(const Quaternion& quaternion);
			static void Normalize(const Quaternion& quaternion, Quaternion& result);
			static Quaternion Slerp(const Quaternion& quaternion, const Quaternion& quaternion2, float amount);
			static void Slerp(const Quaternion& quaternion, const Quaternion& quaternion2, float amount, Quaternion& result);
			Vector3 ToEular() const;
			void ToEular(Vector3& result) const;
		};
	}
}

