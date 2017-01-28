#pragma once
#include "Common.h"
#include <initializer_list>

namespace CFH
{
	namespace Math
	{
		struct Plane;
		struct Vector3;
		struct Quaternion;

		struct DLL_API Matrix4 final
		{
		public:
			static const Matrix4 Identity;
			static const Matrix4 Zero;

			float M11, M12, M13, M14,
				M21, M22, M23, M24,
				M31, M32, M33, M34,
				M41, M42, M43, M44;

			Matrix4();
			Matrix4(float value);
			Matrix4(
				float m11, float m12, float m13, float m14,
				float m21, float m22, float m23, float m24,
				float m31, float m32, float m33, float m34,
				float m41, float m42, float m43, float m44);
			Matrix4(std::initializer_list<float>);
			~Matrix4();

			Matrix4 operator+(const Matrix4& matrix) const;
			Matrix4 operator-(const Matrix4& matrix) const;
			Matrix4 operator*(const Matrix4& matrix) const;
			Matrix4 operator/(const Matrix4& matrix) const;
			const Matrix4& operator+=(const Matrix4& matrix);
			const Matrix4& operator-=(const Matrix4& matrix);
			const Matrix4& operator*=(const Matrix4& matrix);
			const Matrix4& operator/=(const Matrix4& matrix);
			bool operator==(const Matrix4& matrix) const;
			bool operator!=(const Matrix4& matrix) const;
			const Matrix4& operator=(const Matrix4& matrix);
			float& operator[](int index);
			float operator[](int index) const;

			static Matrix4 Add(const Matrix4& lhs, const Matrix4& rhs);
			static void Add(const Matrix4& lhs, const Matrix4& rhs, Matrix4& result);
			static Matrix4 Subtract(const Matrix4& lhs, const Matrix4& rhs);
			static void Subtract(const Matrix4& lhs, const Matrix4& rhs, Matrix4& result);
			static Matrix4 Multiply(const Matrix4& lhs, const Matrix4& rhs);
			static void Multiply(const Matrix4& lhs, const Matrix4& rhs, Matrix4& result);
			static Matrix4 Multiply(const Matrix4& vector, float value);
			static void Multiply(const Matrix4& vector, float value, Matrix4& result);
			static Matrix4 Divide(const Matrix4& lhs, const Matrix4& rhs);
			static void Divide(const Matrix4& lhs, const Matrix4& rhs, Matrix4& result);
			static Matrix4 Divide(const Matrix4& vector, float value);
			static void Divide(const Matrix4& vector, float value, Matrix4& result);
			static Matrix4 Negate(const Matrix4& vector);
			static void Negate(const Matrix4& vector, Matrix4& result);

			void SetForward(const Vector3& vector);
			void SetBackward(const Vector3& vector);
			void SetUp(const Vector3& vector);
			void SetDown(const Vector3& vector);
			void SetRight(const Vector3& vector);
			void SetLeft(const Vector3& vector);
			void SetTranslation(const Vector3& vector);
			void SetScale(const Vector3& scale);
			void SetScale(float value);
			void SetScaleX(float value);
			void SetScaleY(float value);
			void SetScaleZ(float value);

			Vector3 GetForward() const;
			void GetForward(Vector3& result) const;
			Vector3 GetBackward() const;
			void GetBackward(Vector3& result) const;
			Vector3 GetUp() const;
			void GetUp(Vector3& result) const;
			Vector3 GetDown() const;
			void GetDown(Vector3& result) const;
			Vector3 GetRight() const;
			void GetRight(Vector3& result) const;
			Vector3 GetLeft() const;
			void GetLeft(Vector3& result) const;
			Vector3 GetTranslation() const;
			void GetTranslation(Vector3& result) const;
			Vector3 GetScale() const;
			void GetScale(Vector3& result) const;
			float GetScaleX() const;
			void GetScaleX(float& result) const;
			float GetScaleY() const;
			void GetScaleY(float& result) const;
			float GetScaleZ() const;
			void GetScaleZ(float& result) const;

			bool Decompose(Vector3& scale, Quaternion& rotation, Vector3& translation);

			static Matrix4 CreateTranslation(const Vector3& vector);
			static void CreateTranslation(const Vector3& vector, Matrix4& result);

			static Matrix4 CreateScale(float scale);
			static void CreateScale(float scale, Matrix4& result);
			static Matrix4 CreateScale(const Vector3& scale);
			static void CreateScale(const Vector3& scale, Matrix4& result);

			static Matrix4 CreateRotationX(float radians);
			static void CreateRotationX(float radians, Matrix4& result);
			static Matrix4 CreateRotationY(float radians);
			static void CreateRotationY(float radians, Matrix4& result);
			static Matrix4 CreateRotationZ(float radians);
			static void CreateRotationZ(float radians, Matrix4& result);

			static Matrix4 CreateBillboard(const Vector3& objectPosition, const Vector3& cameraPosition, const Vector3& cameraUp, const Vector3& cameraForward);
			static void CreateBillboard(const Vector3& objectPosition, const Vector3& cameraPosition, const Vector3& cameraUp, const Vector3& cameraForward, Matrix4& result);
			static Matrix4 CreateConstrainedBillboard(const Vector3& objectPosition, const Vector3& cameraPosition, const Vector3& rotateAxis, const Vector3& objectForward, const Vector3& cameraForward);
			static void CreateConstrainedBillboard(const Vector3& objectPosition, const Vector3& cameraPosition, const Vector3& rotateAxis, const Vector3& objectForward, const Vector3& cameraForward, Matrix4& result);

			static Matrix4 CreateFromAxisAngle(const Vector3& axis, float angle);
			static void CreateFromAxisAngle(const Vector3& axis, float angle, Matrix4& result);
			static Matrix4 CreateFromQuaternion(const Quaternion& quaternion);
			static void CreateFromQuaternion(const Quaternion& quaternion, Matrix4& result);
			static Matrix4 CreateFromYawPitchRoll(float yaw, float pitch, float roll);
			static void CreateFromYawPitchRoll(float yaw, float pitch, float roll, Matrix4& result);

			static Matrix4 CreateLookAt(const Vector3& cameraPosition, const Vector3& cameraTarget, const Vector3& cameraUp);
			static void CreateLookAt(const Vector3& cameraPosition, const Vector3& cameraTarget, const Vector3& cameraUp, Matrix4& result);
			static Matrix4 CreateOrthographic(float width, float height, float nearPlaneDistance, float farPlaneDistance);
			static void CreateOrthographic(float width, float height, float nearPlaneDistance, float farPlaneDistance, Matrix4& result);
			static Matrix4 CreateOrthographicOffCenter(float left, float right, float bottom, float top, float nearPlaneDistance, float farPlaneDistance);
			static void CreateOrthographicOffCenter(float left, float right, float bottom, float top, float nearPlaneDistance, float farPlaneDistance, Matrix4& result);
			static Matrix4 CreatePerspective(float width, float height, float nearPlaneDistance, float farPlaneDistance);
			static void CreatePerspective(float width, float height, float nearPlaneDistance, float farPlaneDistance, Matrix4& result);
			static Matrix4 CreatePerspectiveFieldOfView(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance);
			static void CreatePerspectiveFieldOfView(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance, Matrix4& result);
			static Matrix4 CreatePerspectiveOffCenter(float left, float right, float bottom, float top, float nearPlaneDistance, float farPlaneDistance);
			static void CreatePerspectiveOffCenter(float left, float right, float bottom, float top, float nearPlaneDistance, float farPlaneDistance, Matrix4& result);
			static Matrix4 CreateReflection(const Plane& plane);
			static void CreateReflection(const Plane& plane, Matrix4& result);
			static Matrix4 CreateShadow(const Vector3& lightDirection, const Plane& plane);
			static void CreateShadow(const Vector3& lightDirection, const Plane& plane, Matrix4& result);
			static Matrix4 CreateWorld(const Vector3& position, const Vector3& forward, const Vector3& up);
			static void CreateWorld(const Vector3& postion, const Vector3& forward, const Vector3& up, Matrix4& result);

			float Determinant() const;
			void Determinant(float& result) const;
			static Matrix4 Invert(const Matrix4& matrix);
			static void Invert(const Matrix4& matrix, Matrix4& result);
			static Matrix4 Lerp(const Matrix4& matrixA, const Matrix4& matrixB, float amount);
			static void Lerp(const Matrix4& matrixA, const Matrix4& matrixB, float amount, Matrix4& result);
			static Matrix4 Transform(const Matrix4& matrix, const Quaternion& rotation);
			static void Transform(const Matrix4& matrix, const Quaternion& rotation, Matrix4& result);
			static Matrix4 Transpose(const Matrix4& matrix);
			static void Transpose(const Matrix4& matrix, Matrix4& result);
			Vector3 ToEular() const;
			void ToEular(Vector3& result) const;

		private:
			static void GetDeterminants(const Matrix4& matrix, float& determinant, float& minor1, float& minor2, float& minor3, float& minor4, float& minor5,
				float& minor6, float& minor7, float& minor8, float& minor9, float& minor10, float& minor11, float& minor12);
		};
	}
}

