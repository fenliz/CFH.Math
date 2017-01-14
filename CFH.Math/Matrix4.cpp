#include "Matrix4.h"
#include "Vector3.h"
#include "Plane.h"
#include "Quaternion.h"
#include "MathHelper.h"

#include <stdexcept>

namespace CFH
{
	namespace Math
	{
		const Matrix4 Matrix4::Identity = Matrix4(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1);
		const Matrix4 Matrix4::Zero = Matrix4();

		Matrix4::Matrix4() :
			M11(0), M12(0), M13(0), M14(0),
			M21(0), M22(0), M23(0), M24(0),
			M31(0), M32(0), M33(0), M34(0),
			M41(0), M42(0), M43(0), M44(0)
		{
		}
		Matrix4::Matrix4(float value) :
			M11(value), M12(value), M13(value), M14(value),
			M21(value), M22(value), M23(value), M24(value),
			M31(value), M32(value), M33(value), M34(value),
			M41(value), M42(value), M43(value), M44(value)
		{
		}
		Matrix4::Matrix4(
			float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44) :
			M11(m11), M12(m12), M13(m13), M14(m14),
			M21(m21), M22(m22), M23(m23), M24(m24),
			M31(m31), M32(m32), M33(m33), M34(m34),
			M41(m41), M42(m42), M43(m43), M44(m44)
		{
		}
		Matrix4::Matrix4(std::initializer_list<float> list)
		{
			auto it = list.begin();
			M11 = *(it++);
			M12 = *(it++);
			M13 = *(it++);
			M14 = *(it++);

			M21 = *(it++);
			M22 = *(it++);
			M23 = *(it++);
			M24 = *(it++);

			M31 = *(it++);
			M32 = *(it++);
			M33 = *(it++);
			M34 = *(it++);

			M41 = *(it++);
			M42 = *(it++);
			M43 = *(it++);
			M44 = *it;
		}
		Matrix4::~Matrix4()
		{
		}

		Matrix4 Matrix4::operator+(Matrix4 matrix) const
		{
			Matrix4 result;
			Add(*this, matrix, result);
			return result;
		}
		Matrix4 Matrix4::operator-(Matrix4 matrix) const
		{
			Matrix4 result;
			Subtract(*this, matrix, result);
			return result;
		}
		Matrix4 Matrix4::operator*(Matrix4 matrix) const
		{
			Matrix4 result;
			Multiply(*this, matrix, result);
			return result;
		}
		Matrix4 Matrix4::operator/(Matrix4 matrix) const
		{
			Matrix4 result;
			Divide(*this, matrix, result);
			return result;
		}
		Matrix4 Matrix4::operator+=(Matrix4 matrix)
		{
			Matrix4 temp;
			Add(*this, matrix, temp);
			*this = temp;
			return *this;
		}
		Matrix4 Matrix4::operator-=(Matrix4 matrix)
		{
			Matrix4 temp;
			Subtract(*this, matrix, temp);
			*this = temp;
			return *this;
		}
		Matrix4 Matrix4::operator*=(Matrix4 matrix)
		{
			Matrix4 temp;
			Multiply(*this, matrix, temp);
			*this = temp;
			return *this;
		}
		Matrix4 Matrix4::operator/=(Matrix4 matrix)
		{
			Matrix4 temp;
			Divide(*this, matrix, temp);
			*this = temp;
			return *this;
		}
		bool Matrix4::operator==(Matrix4 matrix) const
		{
			return
				M11 == matrix.M11 && M12 == matrix.M12 && M13 == matrix.M13 && M14 == matrix.M14 &&
				M21 == matrix.M21 && M22 == matrix.M22 && M23 == matrix.M23 && M24 == matrix.M24 &&
				M31 == matrix.M31 && M32 == matrix.M32 && M33 == matrix.M33 && M34 == matrix.M34 &&
				M41 == matrix.M41 && M42 == matrix.M42 && M43 == matrix.M43 && M44 == matrix.M44;
		}
		bool Matrix4::operator!=(Matrix4 matrix) const
		{
			return
				M11 != matrix.M11 || M12 != matrix.M12 || M13 != matrix.M13 || M14 != matrix.M14 ||
				M21 != matrix.M21 || M22 != matrix.M22 || M23 != matrix.M23 || M24 != matrix.M24 ||
				M31 != matrix.M31 || M32 != matrix.M32 || M33 != matrix.M33 || M34 != matrix.M34 ||
				M41 != matrix.M41 || M42 != matrix.M42 || M43 != matrix.M43 || M44 != matrix.M44;
		}
		Matrix4 Matrix4::operator=(Matrix4 matrix)
		{
			M11 = matrix.M11; M12 = matrix.M12; M13 = matrix.M13; M14 = matrix.M14;
			M21 = matrix.M21; M22 = matrix.M22; M23 = matrix.M23; M24 = matrix.M24;
			M31 = matrix.M31; M32 = matrix.M32; M33 = matrix.M33; M34 = matrix.M34;
			M41 = matrix.M41; M42 = matrix.M42; M43 = matrix.M43; M44 = matrix.M44;
			return *this;
		}
		float& Matrix4::operator[](int index)
		{
			switch (index)
			{
			case 0: return M11;
			case 1: return M12;
			case 2: return M13;
			case 3: return M14;

			case 4: return M21;
			case 5: return M22;
			case 6: return M23;
			case 7: return M24;

			case 8: return M31;
			case 9: return M32;
			case 10: return M33;
			case 11: return M34;

			case 12: return M41;
			case 13: return M42;
			case 14: return M43;
			case 15: return M44;

			default:
				throw std::invalid_argument("Max valid index of a Matrix4 is 15.");
			}
		}
		float Matrix4::operator[](int index) const
		{
			switch (index)
			{
			case 0: return M11;
			case 1: return M12;
			case 2: return M13;
			case 3: return M14;

			case 4: return M21;
			case 5: return M22;
			case 6: return M23;
			case 7: return M24;

			case 8: return M31;
			case 9: return M32;
			case 10: return M33;
			case 11: return M34;

			case 12: return M41;
			case 13: return M42;
			case 14: return M43;
			case 15: return M44;

			default:
				throw std::invalid_argument("Max valid index of a Matrix4 is 15.");
			}
		}

		Matrix4 Matrix4::Add(Matrix4 lhs, Matrix4 rhs)
		{
			Matrix4 result;
			Add(lhs, rhs, result);
			return result;
		}
		void Matrix4::Add(Matrix4 lhs, Matrix4 rhs, Matrix4& result)
		{
			result.M11 = lhs.M11 + rhs.M11;
			result.M12 = lhs.M12 + rhs.M12;
			result.M13 = lhs.M13 + rhs.M13;
			result.M14 = lhs.M14 + rhs.M14;
			result.M21 = lhs.M21 + rhs.M21;
			result.M22 = lhs.M22 + rhs.M22;
			result.M23 = lhs.M23 + rhs.M23;
			result.M24 = lhs.M24 + rhs.M24;
			result.M31 = lhs.M31 + rhs.M31;
			result.M32 = lhs.M32 + rhs.M32;
			result.M33 = lhs.M33 + rhs.M33;
			result.M34 = lhs.M34 + rhs.M34;
			result.M41 = lhs.M41 + rhs.M41;
			result.M42 = lhs.M42 + rhs.M42;
			result.M43 = lhs.M43 + rhs.M43;
			result.M44 = lhs.M44 + rhs.M44;
		}
		Matrix4 Matrix4::Subtract(Matrix4 lhs, Matrix4 rhs)
		{
			Matrix4 result;
			Subtract(lhs, rhs, result);
			return result;
		}
		void Matrix4::Subtract(Matrix4 lhs, Matrix4 rhs, Matrix4& result)
		{
			result.M11 = lhs.M11 - rhs.M11;
			result.M12 = lhs.M12 - rhs.M12;
			result.M13 = lhs.M13 - rhs.M13;
			result.M14 = lhs.M14 - rhs.M14;
			result.M21 = lhs.M21 - rhs.M21;
			result.M22 = lhs.M22 - rhs.M22;
			result.M23 = lhs.M23 - rhs.M23;
			result.M24 = lhs.M24 - rhs.M24;
			result.M31 = lhs.M31 - rhs.M31;
			result.M32 = lhs.M32 - rhs.M32;
			result.M33 = lhs.M33 - rhs.M33;
			result.M34 = lhs.M34 - rhs.M34;
			result.M41 = lhs.M41 - rhs.M41;
			result.M42 = lhs.M42 - rhs.M42;
			result.M43 = lhs.M43 - rhs.M43;
			result.M44 = lhs.M44 - rhs.M44;
		}
		Matrix4 Matrix4::Multiply(Matrix4 lhs, Matrix4 rhs)
		{
			Matrix4 result;
			Multiply(lhs, rhs, result);
			return result;
		}
		void Matrix4::Multiply(Matrix4 lhs, Matrix4 rhs, Matrix4& result)
		{
			result.M11 = lhs.M11 * rhs.M11 + lhs.M12 * rhs.M21 + lhs.M13 * rhs.M31 + lhs.M14 * rhs.M41;
			result.M12 = lhs.M11 * rhs.M12 + lhs.M12 * rhs.M22 + lhs.M13 * rhs.M32 + lhs.M14 * rhs.M42;
			result.M13 = lhs.M11 * rhs.M13 + lhs.M12 * rhs.M23 + lhs.M13 * rhs.M33 + lhs.M14 * rhs.M43;
			result.M14 = lhs.M11 * rhs.M14 + lhs.M12 * rhs.M24 + lhs.M13 * rhs.M34 + lhs.M14 * rhs.M44;

			result.M21 = lhs.M21 * rhs.M11 + lhs.M22 * rhs.M21 + lhs.M23 * rhs.M31 + lhs.M24 * rhs.M41;
			result.M22 = lhs.M21 * rhs.M12 + lhs.M22 * rhs.M22 + lhs.M23 * rhs.M32 + lhs.M24 * rhs.M42;
			result.M23 = lhs.M21 * rhs.M13 + lhs.M22 * rhs.M23 + lhs.M23 * rhs.M33 + lhs.M24 * rhs.M43;
			result.M24 = lhs.M21 * rhs.M14 + lhs.M22 * rhs.M24 + lhs.M23 * rhs.M34 + lhs.M24 * rhs.M44;

			result.M31 = lhs.M31 * rhs.M11 + lhs.M32 * rhs.M21 + lhs.M33 * rhs.M31 + lhs.M34 * rhs.M41;
			result.M32 = lhs.M31 * rhs.M12 + lhs.M32 * rhs.M22 + lhs.M33 * rhs.M32 + lhs.M34 * rhs.M42;
			result.M33 = lhs.M31 * rhs.M13 + lhs.M32 * rhs.M23 + lhs.M33 * rhs.M33 + lhs.M34 * rhs.M43;
			result.M34 = lhs.M31 * rhs.M14 + lhs.M32 * rhs.M24 + lhs.M33 * rhs.M34 + lhs.M34 * rhs.M44;

			result.M41 = lhs.M41 * rhs.M11 + lhs.M42 * rhs.M21 + lhs.M43 * rhs.M31 + lhs.M44 * rhs.M41;
			result.M42 = lhs.M41 * rhs.M12 + lhs.M42 * rhs.M22 + lhs.M43 * rhs.M32 + lhs.M44 * rhs.M42;
			result.M43 = lhs.M41 * rhs.M13 + lhs.M42 * rhs.M23 + lhs.M43 * rhs.M33 + lhs.M44 * rhs.M43;
			result.M44 = lhs.M41 * rhs.M14 + lhs.M42 * rhs.M24 + lhs.M43 * rhs.M34 + lhs.M44 * rhs.M44;
		}
		Matrix4 Matrix4::Multiply(Matrix4 matrix, float value)
		{
			Matrix4 result;
			Multiply(matrix, value, result);
			return result;
		}
		void Matrix4::Multiply(Matrix4 matrix, float value, Matrix4& result)
		{
			result.M11 = matrix.M11 * value;
			result.M12 = matrix.M12 * value;
			result.M13 = matrix.M13 * value;
			result.M14 = matrix.M14 * value;
			result.M21 = matrix.M21 * value;
			result.M22 = matrix.M22 * value;
			result.M23 = matrix.M23 * value;
			result.M24 = matrix.M24 * value;
			result.M31 = matrix.M31 * value;
			result.M32 = matrix.M32 * value;
			result.M33 = matrix.M33 * value;
			result.M34 = matrix.M34 * value;
			result.M41 = matrix.M41 * value;
			result.M42 = matrix.M42 * value;
			result.M43 = matrix.M43 * value;
			result.M44 = matrix.M44 * value;
		}
		Matrix4 Matrix4::Divide(Matrix4 lhs, Matrix4 rhs)
		{
			Matrix4 result;
			Divide(lhs, rhs, result);
			return result;
		}
		void Matrix4::Divide(Matrix4 lhs, Matrix4 rhs, Matrix4& result)
		{
			result.M11 = lhs.M11 / rhs.M11;
			result.M12 = lhs.M12 / rhs.M12;
			result.M13 = lhs.M13 / rhs.M13;
			result.M14 = lhs.M14 / rhs.M14;
			result.M21 = lhs.M21 / rhs.M21;
			result.M22 = lhs.M22 / rhs.M22;
			result.M23 = lhs.M23 / rhs.M23;
			result.M24 = lhs.M24 / rhs.M24;
			result.M31 = lhs.M31 / rhs.M31;
			result.M32 = lhs.M32 / rhs.M32;
			result.M33 = lhs.M33 / rhs.M33;
			result.M34 = lhs.M34 / rhs.M34;
			result.M41 = lhs.M41 / rhs.M41;
			result.M42 = lhs.M42 / rhs.M42;
			result.M43 = lhs.M43 / rhs.M43;
			result.M44 = lhs.M44 / rhs.M44;
		}
		Matrix4 Matrix4::Divide(Matrix4 matrix, float value)
		{
			Matrix4 result;
			Divide(matrix, value, result);
			return result;
		}
		void Matrix4::Divide(Matrix4 matrix, float value, Matrix4& result)
		{
			result.M11 = matrix.M11 / value;
			result.M12 = matrix.M12 / value;
			result.M13 = matrix.M13 / value;
			result.M14 = matrix.M14 / value;
			result.M21 = matrix.M21 / value;
			result.M22 = matrix.M22 / value;
			result.M23 = matrix.M23 / value;
			result.M24 = matrix.M24 / value;
			result.M31 = matrix.M31 / value;
			result.M32 = matrix.M32 / value;
			result.M33 = matrix.M33 / value;
			result.M34 = matrix.M34 / value;
			result.M41 = matrix.M41 / value;
			result.M42 = matrix.M42 / value;
			result.M43 = matrix.M43 / value;
			result.M44 = matrix.M44 / value;
		}
		Matrix4 Matrix4::Negate(Matrix4 vector)
		{
			Matrix4 result;
			Negate(vector, result);
			return result;
		}
		void Matrix4::Negate(Matrix4 vector, Matrix4& result)
		{
			result.M11 = -vector.M11;
			result.M12 = -vector.M12;
			result.M13 = -vector.M13;
			result.M14 = -vector.M14;
			result.M21 = -vector.M21;
			result.M22 = -vector.M22;
			result.M23 = -vector.M23;
			result.M24 = -vector.M24;
			result.M31 = -vector.M31;
			result.M32 = -vector.M32;
			result.M33 = -vector.M33;
			result.M34 = -vector.M34;
			result.M41 = -vector.M41;
			result.M42 = -vector.M42;
			result.M43 = -vector.M43;
			result.M44 = -vector.M44;
		}

		void Matrix4::SetForward(Vector3 vector)
		{
			M31 = vector.X;
			M32 = vector.Y;
			M33 = vector.Z;
		}
		void Matrix4::SetBackward(Vector3 vector)
		{
			M31 = -vector.X;
			M32 = -vector.Y;
			M33 = -vector.Z;
		}
		void Matrix4::SetUp(Vector3 vector)
		{
			M21 = vector.X;
			M22 = vector.Y;
			M23 = vector.Z;
		}
		void Matrix4::SetDown(Vector3 vector)
		{
			M21 = -vector.X;
			M22 = -vector.Y;
			M23 = -vector.Z;
		}
		void Matrix4::SetRight(Vector3 vector)
		{
			M11 = vector.X;
			M12 = vector.Y;
			M13 = vector.Z;
		}
		void Matrix4::SetLeft(Vector3 vector)
		{
			M11 = -vector.X;
			M12 = -vector.Y;
			M13 = -vector.Z;
		}
		void Matrix4::SetTranslation(Vector3 vector)
		{
			M41 = vector.X;
			M42 = vector.Y;
			M43 = vector.Z;
		}
		void Matrix4::SetScale(Vector3 vector)
		{
			float scaleX, scaleY, scaleZ;
			GetScaleX(scaleX);
			GetScaleY(scaleY);
			GetScaleZ(scaleZ);
			M11 = (M11 / scaleX) * vector.X;
			M12 = (M12 / scaleX) * vector.X;
			M13 = (M13 / scaleX) * vector.X;
			M21 = (M21 / scaleY) * vector.Y;
			M22 = (M22 / scaleY) * vector.Y;
			M23 = (M23 / scaleY) * vector.Y;
			M31 = (M31 / scaleZ) * vector.Z;
			M32 = (M32 / scaleZ) * vector.Z;
			M33 = (M33 / scaleZ) * vector.Z;
		}
		void Matrix4::SetScale(float value)
		{
			float scaleX, scaleY, scaleZ;
			GetScaleX(scaleX);
			GetScaleY(scaleY);
			GetScaleZ(scaleZ);
			M11 = (M11 / scaleX) * value;
			M12 = (M12 / scaleX) * value;
			M13 = (M13 / scaleX) * value;
			M21 = (M21 / scaleY) * value;
			M22 = (M22 / scaleY) * value;
			M23 = (M23 / scaleY) * value;
			M31 = (M31 / scaleZ) * value;
			M32 = (M32 / scaleZ) * value;
			M33 = (M33 / scaleZ) * value;
		}
		void Matrix4::SetScaleX(float value)
		{
			float scaleX;
			GetScaleX(scaleX);
			M11 = (M11 / scaleX) * value;
			M12 = (M12 / scaleX) * value;
			M13 = (M13 / scaleX) * value;
		}
		void Matrix4::SetScaleY(float value)
		{
			float scaleY;
			GetScaleY(scaleY);
			M21 = (M21 / scaleY) * value;
			M22 = (M22 / scaleY) * value;
			M23 = (M23 / scaleY) * value;
		}
		void Matrix4::SetScaleZ(float value)
		{
			float scaleZ;
			GetScaleZ(scaleZ);
			M31 = (M31 / scaleZ) * value;
			M32 = (M32 / scaleZ) * value;
			M33 = (M33 / scaleZ) * value;
		}

		Vector3 Matrix4::GetForward() const
		{
			Vector3 result;
			GetForward(result);
			return result;
		}
		void Matrix4::GetForward(Vector3& result) const
		{
			result.X = -M31;
			result.Y = -M32;
			result.Z = -M33;
		}
		Vector3 Matrix4::GetBackward() const
		{
			Vector3 result;
			GetBackward(result);
			return result;
		}
		void Matrix4::GetBackward(Vector3& result) const
		{
			result.X = M31;
			result.Y = M32;
			result.Z = M33;
		}
		Vector3 Matrix4::GetUp() const
		{
			Vector3 result;
			GetUp(result);
			return result;
		}
		void Matrix4::GetUp(Vector3& result) const
		{
			result.X = M21;
			result.Y = M22;
			result.Z = M23;
		}
		Vector3 Matrix4::GetDown() const
		{
			Vector3 result;
			GetDown(result);
			return result;
		}
		void Matrix4::GetDown(Vector3& result) const
		{
			result.X = -M21;
			result.Y = -M22;
			result.Z = -M23;
		}
		Vector3 Matrix4::GetRight() const
		{
			Vector3 result;
			GetRight(result);
			return result;
		}
		void Matrix4::GetRight(Vector3& result) const
		{
			result.X = M11;
			result.Y = M12;
			result.Z = M13;
		}
		Vector3 Matrix4::GetLeft() const
		{
			Vector3 result;
			GetLeft(result);
			return result;
		}
		void Matrix4::GetLeft(Vector3& result) const
		{
			result.X = -M11;
			result.Y = -M12;
			result.Z = -M13;
		}
		Vector3 Matrix4::GetTranslation() const
		{
			Vector3 result;
			GetTranslation(result);
			return result;
		}
		void Matrix4::GetTranslation(Vector3& result) const
		{
			result.X = M41;
			result.Y = M42;
			result.Z = M43;
		}
		Vector3 Matrix4::GetScale() const
		{
			Vector3 result;
			GetScale(result);
			return result;
		}
		void Matrix4::GetScale(Vector3& result) const
		{
			GetScaleX(result.X);
			GetScaleY(result.Y);
			GetScaleZ(result.Z);
		}
		float Matrix4::GetScaleX() const
		{
			float result;
			GetScaleX(result);
			return result;
		}
		void Matrix4::GetScaleX(float& result) const
		{
			result = MathHelper::Sqrt((M11 * M11) +
				(M12 * M12) * (M13 * M13));
		}
		float Matrix4::GetScaleY() const
		{
			float result;
			GetScaleY(result);
			return result;
		}
		void Matrix4::GetScaleY(float& result) const
		{
			result = MathHelper::Sqrt((M21 * M21) +
				(M22 * M22) * (M23 * M23));
		}
		float Matrix4::GetScaleZ() const
		{
			float result;
			GetScaleZ(result);
			return result;
		}
		void Matrix4::GetScaleZ(float& result) const
		{
			result = MathHelper::Sqrt((M31 * M31) +
				(M32 * M32) * (M33 * M33));
		}

		bool Matrix4::Decompose(Vector3& scale, Quaternion& rotation, Vector3& translation)
		{
			GetScale(scale);
			if (scale.X == 0 || scale.Y == 0 || scale.Z == 0)
				return false;

			Matrix4 temp = *this;
			temp.M11 /= scale.X;
			temp.M12 /= scale.X;
			temp.M13 /= scale.X;
			temp.M21 /= scale.Y;
			temp.M22 /= scale.Y;
			temp.M23 /= scale.Y;
			temp.M31 /= scale.Z;
			temp.M32 /= scale.Z;
			temp.M33 /= scale.Z;
			Quaternion::CreateFromRotationMatrix(temp, rotation);
			GetTranslation(translation);
			return true;
		}

		Matrix4 Matrix4::CreateTranslation(Vector3 vector)
		{
			Matrix4 result;
			CreateTranslation(vector, result);
			return result;
		}
		void Matrix4::CreateTranslation(Vector3 vector, Matrix4& result)
		{
			result = Matrix4::Zero;
			result.M41 = vector.X;
			result.M42 = vector.Y;
			result.M43 = vector.Z;
			result.M11 = result.M22 = result.M33 = result.M44 = 1;
		}

		Matrix4 Matrix4::CreateScale(float value)
		{
			Matrix4 result;
			CreateScale(Vector3(value, value, value), result);
			return result;
		}
		void Matrix4::CreateScale(float value, Matrix4& result)
		{
			CreateScale(Vector3(value, value, value), result);
		}
		Matrix4 Matrix4::CreateScale(Vector3 vector)
		{
			Matrix4 result;
			CreateScale(vector, result);
			return result;
		}
		void Matrix4::CreateScale(Vector3 vector, Matrix4& result)
		{
			result = Matrix4::Zero;
			result.M11 = vector.X;
			result.M22 = vector.Y;
			result.M33 = vector.Z;
			result.M44 = 1;
		}

		Matrix4 Matrix4::CreateRotationX(float radians)
		{
			Matrix4 result;
			CreateRotationX(radians, result);
			return result;
		}
		void Matrix4::CreateRotationX(float radians, Matrix4& result)
		{
			result = Matrix4::Zero;
			result.M11 = result.M44 = 1;
			result.M22 = result.M33 = MathHelper::Cos(radians);
			result.M23 = MathHelper::Sin(radians);
			result.M32 = -result.M23;
		}
		Matrix4 Matrix4::CreateRotationY(float radians)
		{
			Matrix4 result;
			CreateRotationY(radians, result);
			return result;
		}
		void Matrix4::CreateRotationY(float radians, Matrix4& result)
		{
			result = Matrix4::Zero;
			result.M22 = result.M44 = 1;
			result.M11 = result.M33 = MathHelper::Cos(radians);
			result.M31 = MathHelper::Sin(radians);
			result.M13 = -result.M31;
		}
		Matrix4 Matrix4::CreateRotationZ(float radians)
		{
			Matrix4 result;
			CreateRotationZ(radians, result);
			return result;
		}
		void Matrix4::CreateRotationZ(float radians, Matrix4& result)
		{
			result = Matrix4::Zero;
			result.M33 = result.M44 = 1;
			result.M11 = result.M22 = MathHelper::Cos(radians);
			result.M12 = MathHelper::Sin(radians);
			result.M21 = -result.M12;
		}

		Matrix4 Matrix4::CreateFromAxisAngle(Vector3 axis, float angle)
		{
			Matrix4 result;
			CreateFromAxisAngle(axis, angle, result);
			return result;
		}
		void Matrix4::CreateFromAxisAngle(Vector3 axis, float angle, Matrix4& result)
		{
			Vector3 temp = axis;
			float length;
			axis.LengthSquared(length);
			if (length < 1e-9 && length > -1e-9)
				Vector3::Divide(temp, MathHelper::Sqrt(length), temp);

			float cos = MathHelper::Cos(angle);
			float sin = MathHelper::Sin(angle);
			float tan = 1 - cos;

			result.M11 = tan * temp.X * temp.X + cos;
			result.M12 = tan * temp.X * temp.Y + temp.Z * sin;
			result.M13 = tan * temp.X * temp.Z - temp.Y * sin;
			result.M14 = 0;

			result.M21 = tan * temp.X * temp.Y - temp.Z * sin;
			result.M22 = tan * temp.Y * temp.Y + cos;
			result.M23 = tan * temp.Y * temp.Z + temp.X * sin;
			result.M24 = 0;

			result.M31 = tan * temp.X * temp.Z + temp.Y * sin;
			result.M32 = tan * temp.Y * temp.Z - temp.X * sin;
			result.M33 = tan * temp.Z * temp.Z + cos;
			result.M34 = 0;

			result.M41 = 0;
			result.M42 = 0;
			result.M43 = 0;
			result.M44 = 1;
		}
		Matrix4 Matrix4::CreateFromQuaternion(Quaternion quaternion)
		{
			Matrix4 result;
			CreateFromQuaternion(quaternion, result);
			return result;
		}
		void Matrix4::CreateFromQuaternion(Quaternion quaternion, Matrix4& result)
		{
			result.M11 = (2 * quaternion.X * quaternion.X) + (2 * quaternion.W * quaternion.W) - 1;
			result.M12 = (2 * quaternion.X * quaternion.Y) + (2 * quaternion.Z * quaternion.W);
			result.M13 = (2 * quaternion.X * quaternion.Z) - (2 * quaternion.Y * quaternion.W);
			result.M14 = 0;

			result.M21 = (2 * quaternion.X * quaternion.Y) - (2 * quaternion.Z * quaternion.W);
			result.M22 = (2 * quaternion.Y * quaternion.Y) + (2 * quaternion.W * quaternion.W) - 1;
			result.M23 = (2 * quaternion.Y * quaternion.Z) + (2 * quaternion.X * quaternion.W);
			result.M24 = 0;

			result.M31 = (2 * quaternion.X * quaternion.Z) + (2 * quaternion.Y * quaternion.W);
			result.M32 = (2 * quaternion.Y * quaternion.Z) - (2 * quaternion.X * quaternion.W);
			result.M33 = (2 * quaternion.Z * quaternion.Z) + (2 * quaternion.W * quaternion.W) - 1;
			result.M34 = 0;

			result.M41 = 0;
			result.M42 = 0;
			result.M43 = 0;
			result.M44 = 1;
		}
		Matrix4 Matrix4::CreateFromYawPitchRoll(float yaw, float pitch, float roll)
		{
			Matrix4 result;
			CreateFromYawPitchRoll(yaw, pitch, roll, result);
			return result;
		}
		void Matrix4::CreateFromYawPitchRoll(float yaw, float pitch, float roll, Matrix4& result)
		{
			Matrix4::CreateFromQuaternion(Quaternion::CreateFromYawPitchRoll(yaw, pitch, roll), result);
		}

		Matrix4 Matrix4::CreateLookAt(Vector3 cameraPosition, Vector3 cameraTarget, Vector3 cameraUp)
		{
			Matrix4 result;
			CreateLookAt(cameraPosition, cameraTarget, cameraUp, result);
			return result;
		}
		void Matrix4::CreateLookAt(Vector3 cameraPosition, Vector3 cameraTarget, Vector3 cameraUp, Matrix4& result)
		{
			Vector3 pos;
			Vector3::Subtract(cameraPosition, cameraTarget, pos);
			Vector3 vz;
			Vector3::Normalize(pos, vz);

			Vector3 cross;
			Vector3::Cross(cameraUp, vz, cross);
			Vector3 vx;
			Vector3::Normalize(cross, vx);

			Vector3 vy;
			Vector3::Cross(vz, vx, vy);

			float dvx, dvy, dvz;
			Vector3::Dot(vx, cameraPosition, dvx);
			Vector3::Dot(vy, cameraPosition, dvy);
			Vector3::Dot(vz, cameraPosition, dvz);

			result = Matrix4::Identity;
			result.M11 = vx.X;
			result.M12 = vy.X;
			result.M13 = vz.X;
			result.M21 = vx.Y;
			result.M22 = vy.Y;
			result.M23 = vz.Y;
			result.M31 = vx.Z;
			result.M32 = vy.Z;
			result.M33 = vz.Z;
			result.M41 = -dvx;
			result.M42 = -dvy;
			result.M43 = -dvz;
		}
		Matrix4 Matrix4::CreateOrthographic(float width, float height, float nearPlaneDistance, float farPlaneDistance)
		{
			Matrix4 result;
			CreateOrthographic(width, height, nearPlaneDistance, farPlaneDistance, result);
			return result;
		}
		void Matrix4::CreateOrthographic(float width, float height, float nearPlaneDistance, float farPlaneDistance, Matrix4& result)
		{
			result.M12 = result.M13 = result.M14 =
				result.M21 = result.M23 = result.M24 =
				result.M31 = result.M32 = result.M34 =
				result.M41 = result.M42 = 0;

			result.M11 = 2 / width;
			result.M22 = 2 / height;
			result.M33 = 1 / (nearPlaneDistance - farPlaneDistance);
			result.M43 = nearPlaneDistance / (nearPlaneDistance - farPlaneDistance);
			result.M44 = 1;
		}
		Matrix4 Matrix4::CreateOrthographicOffCenter(float left, float right, float bottom, float top, float nearPlaneDistance, float farPlaneDistance)
		{
			Matrix4 result;
			CreateOrthographicOffCenter(left, right, bottom, top, nearPlaneDistance, farPlaneDistance, result);
			return result;
		}
		void Matrix4::CreateOrthographicOffCenter(float left, float right, float bottom, float top, float nearPlaneDistance, float farPlaneDistance, Matrix4& result)
		{
			result.M12 = result.M13 = result.M14 =
				result.M21 = result.M23 = result.M24 =
				result.M31 = result.M32 = result.M34 = 0;

			result.M11 = 2 / (right - left);
			result.M22 = 2 / (top - bottom);
			result.M33 = 1 / (nearPlaneDistance - farPlaneDistance);
			result.M41 = (left + right) / (left - right);
			result.M42 = (top + bottom) / (bottom + top);
			result.M43 = nearPlaneDistance / (nearPlaneDistance - farPlaneDistance);
			result.M44 = 1;

			for (int i = 0; i < 16; i++)
				if (result[i] != result[i])
					result[i] = 0;
		}
		Matrix4 Matrix4::CreatePerspective(float width, float height, float nearPlaneDistance, float farPlaneDistance)
		{
			Matrix4 result;
			CreatePerspective(width, height, nearPlaneDistance, farPlaneDistance, result);
			return result;
		}
		void Matrix4::CreatePerspective(float width, float height, float nearPlaneDistance, float farPlaneDistance, Matrix4& result)
		{
			result.M12 = result.M13 = result.M14 =
				result.M21 = result.M23 = result.M24 =
				result.M31 = result.M32 =
				result.M41 = result.M42 = result.M44 = 0;

			result.M11 = 2 * nearPlaneDistance / width;
			result.M22 = 2 * nearPlaneDistance / height;
			result.M33 = farPlaneDistance / (nearPlaneDistance - farPlaneDistance);
			result.M34 = -1;
			result.M43 = nearPlaneDistance * farPlaneDistance / (nearPlaneDistance - farPlaneDistance);
		}
		Matrix4 Matrix4::CreatePerspectiveFieldOfView(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance)
		{
			Matrix4 result;
			CreatePerspectiveFieldOfView(fieldOfView, aspectRatio, nearPlaneDistance, farPlaneDistance, result);
			return result;
		}
		void Matrix4::CreatePerspectiveFieldOfView(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance, Matrix4& result)
		{
			result.M12 = result.M13 = result.M14 =
				result.M21 = result.M23 = result.M24 =
				result.M31 = result.M32 =
				result.M41 = result.M42 = result.M44 = 0;

			result.M22 = 1.0f / MathHelper::Tan(fieldOfView / 2);
			result.M11 = result.M22 / aspectRatio;
			result.M33 = farPlaneDistance / (nearPlaneDistance - farPlaneDistance);
			result.M34 = -1;
			result.M43 = nearPlaneDistance * farPlaneDistance / (nearPlaneDistance - farPlaneDistance);
		}
		Matrix4 Matrix4::CreatePerspectiveOffCenter(float left, float right, float bottom, float top, float nearPlaneDistance, float farPlaneDistance)
		{
			Matrix4 result;
			CreatePerspectiveOffCenter(left, right, bottom, top, nearPlaneDistance, farPlaneDistance, result);
			return result;
		}
		void Matrix4::CreatePerspectiveOffCenter(float left, float right, float bottom, float top, float nearPlaneDistance, float farPlaneDistance, Matrix4& result)
		{
			result.M12 = result.M13 = result.M14 =
				result.M21 = result.M23 = result.M24 =
				result.M41 = result.M42 = result.M44 = 0;

			result.M11 = 2 * nearPlaneDistance / (right - left);
			result.M22 = 2 * nearPlaneDistance / (top - bottom);
			result.M31 = (left + right) / (right - left);
			result.M32 = (top + bottom) / (top - bottom);
			result.M33 = farPlaneDistance / (nearPlaneDistance - farPlaneDistance);
			result.M34 = -1;
			result.M43 = nearPlaneDistance * farPlaneDistance / (nearPlaneDistance - farPlaneDistance);
		}
		Matrix4 Matrix4::CreateReflection(Plane plane)
		{
			Matrix4 result;
			CreateReflection(plane, result);
			return result;
		}
		void Matrix4::CreateReflection(Plane plane, Matrix4& result)
		{
			result = Matrix4::Identity;

			Plane temp;
			Plane::Normalize(plane, temp);
			result.M11 = -2 * temp.Normal.X * temp.Normal.X + 1;
			result.M12 = -2 * temp.Normal.Y * temp.Normal.X;
			result.M13 = -2 * temp.Normal.Z * temp.Normal.X;
			result.M14 = 0;

			result.M21 = -2 * temp.Normal.X * temp.Normal.Y;
			result.M22 = -2 * temp.Normal.Y * temp.Normal.Y + 1;
			result.M23 = -2 * temp.Normal.Z * temp.D;
			result.M24 = 0;

			result.M31 = -2 * temp.Normal.X * temp.Normal.Z;
			result.M32 = -2 * temp.Normal.Y * temp.Normal.Z;
			result.M33 = -2 * temp.Normal.Z * temp.Normal.Z + 1;
			result.M34 = 0;

			result.M41 = -2 * temp.Normal.X * temp.D;
			result.M42 = -2 * temp.Normal.Y * temp.D;
			result.M43 = -2 * temp.Normal.Z * temp.D;
			result.M44 = 1;
		}
		Matrix4 Matrix4::CreateShadow(Vector3 lightDirection, Plane plane)
		{
			Matrix4 result;
			CreateShadow(lightDirection, plane, result);
			return result;
		}
		void Matrix4::CreateShadow(Vector3 lightDirection, Plane plane, Matrix4& result)
		{
			Plane temp;
			Plane::Normalize(plane, temp);
			float dot;

			Vector3::Dot(temp.Normal, lightDirection, dot);
			result.M11 = dot - lightDirection.X * plane.Normal.X;
			result.M21 = 0.f - lightDirection.X * plane.Normal.Y;
			result.M31 = 0.f - lightDirection.X * plane.Normal.Z;
			result.M41 = 0.f - lightDirection.X * plane.D;
			result.M12 = 0.f - lightDirection.Y * plane.Normal.X;
			result.M22 = dot - lightDirection.Y * plane.Normal.Y;
			result.M32 = 0.f - lightDirection.Y * plane.Normal.Z;
			result.M42 = 0.f - lightDirection.Y * plane.D;
			result.M13 = 0.f - lightDirection.Z * plane.Normal.X;
			result.M23 = 0.f - lightDirection.Z * plane.Normal.Y;
			result.M33 = dot - lightDirection.Z * plane.Normal.Z;
			result.M43 = 0.f - lightDirection.Z * plane.D;

			result.M14 = 0;
			result.M24 = 0;
			result.M34 = 0;
			result.M44 = dot;
		}
		Matrix4 Matrix4::CreateWorld(Vector3 position, Vector3 forward, Vector3 up)
		{
			Matrix4 result;
			CreateWorld(position, forward, up, result);
			return result;
		}
		void Matrix4::CreateWorld(Vector3 position, Vector3 forward, Vector3 up, Matrix4& result)
		{
			Vector3 x, y, z;
			Vector3::Cross(forward, up, x);
			Vector3::Cross(x, forward, y);

			Vector3::Normalize(forward, z);
			x.Normalize();
			y.Normalize();

			result.SetRight(x);
			result.SetUp(y);
			result.SetForward(z);
			result.SetTranslation(position);
			result.M44 = 1.0f;
		}

		float Matrix4::Determinant() const
		{
			float result;
			Determinant(result);
			return result;
		}
		void Matrix4::Determinant(float& result) const
		{
			result =
				M11 * (
					M22 * (M33 * M44 - M43 * M34) -
					M23 * (M32 * M44 - M42 * M34) +
					M24 * (M32 * M43 - M42 * M33)
					)
				-
				M12 * (
					M21 * (M33 * M44 - M43 * M34) -
					M23 * (M31 * M44 - M41 * M34) +
					M24 * (M31 * M43 - M41 * M33)
					)
				+
				M13 * (
					M21 * (M32 * M44 - M42 * M34) -
					M22 * (M31 * M44 - M41 * M34) +
					M24 * (M31 * M42 - M41 * M32)
					)
				-
				M14 * (
					M21 *(M32 * M43 - M42 * M33) -
					M22 *(M31 * M43 - M41 * M33) +
					M23 *(M31 * M42 - M41 * M32)
					);
		}
		Matrix4 Matrix4::Invert(Matrix4 matrix)
		{
			Matrix4 result;
			Invert(matrix, result);
			return result;
		}
		void Matrix4::Invert(Matrix4 matrix, Matrix4& result)
		{
			float determinant, minor1, minor2, minor3, minor4, minor5, minor6, minor7, minor8, minor9, minor10, minor11, minor12;
			GetDeterminants(matrix, determinant, minor1, minor2, minor3, minor4, minor5, minor6, minor7, minor8, minor9, minor10, minor11, minor12);
			float oneOverDeterminant = 1.0f / determinant;

			result = Matrix4::Zero;
			result.M11 = (matrix.M22 * minor12 - matrix.M23 * minor11 + matrix.M24 * minor10) * oneOverDeterminant;
			result.M12 = (-matrix.M12 * minor12 + matrix.M13 * minor11 - matrix.M14 * minor10) * oneOverDeterminant;
			result.M13 = (matrix.M42 * minor6 - matrix.M43 * minor5 + matrix.M44 * minor4) * oneOverDeterminant;
			result.M14 = (-matrix.M32 * minor6 + matrix.M33 * minor5 - matrix.M34 * minor4) * oneOverDeterminant;
			result.M21 = (-matrix.M21 * minor12 + matrix.M23 * minor9 - matrix.M24 * minor8) * oneOverDeterminant;
			result.M22 = (matrix.M11 * minor12 - matrix.M13 * minor9 + matrix.M14 * minor8) * oneOverDeterminant;
			result.M23 = (-matrix.M41 * minor6 + matrix.M43 * minor3 - matrix.M44 * minor2) * oneOverDeterminant;
			result.M24 = (matrix.M31 * minor6 - matrix.M33 * minor3 + matrix.M34 * minor2) * oneOverDeterminant;
			result.M31 = (matrix.M21 * minor11 - matrix.M22 * minor9 + matrix.M24 * minor7) * oneOverDeterminant;
			result.M32 = (-matrix.M11 * minor11 + matrix.M12 * minor9 - matrix.M14 * minor7) * oneOverDeterminant;
			result.M33 = (matrix.M41 * minor5 - matrix.M42 * minor3 + matrix.M44 * minor1) * oneOverDeterminant;
			result.M34 = (-matrix.M31 * minor5 + matrix.M32 * minor3 - matrix.M34 * minor1) * oneOverDeterminant;
			result.M41 = (-matrix.M21 * minor10 + matrix.M22 * minor8 - matrix.M23 * minor7) * oneOverDeterminant;
			result.M42 = (matrix.M11 * minor10 - matrix.M12 * minor8 + matrix.M13 * minor7) * oneOverDeterminant;
			result.M43 = (-matrix.M41 * minor4 + matrix.M42 * minor2 - matrix.M43 * minor1) * oneOverDeterminant;
			result.M44 = (matrix.M31 * minor4 - matrix.M32 * minor2 + matrix.M33 * minor1) * oneOverDeterminant;
		}
		void Matrix4::GetDeterminants(Matrix4 matrix, float& determinant, float& minor1, float& minor2, float& minor3, float& minor4, float& minor5,
			float& minor6, float& minor7, float& minor8, float& minor9, float& minor10, float& minor11, float& minor12)
		{
			minor1 = matrix.M11 * matrix.M22 - matrix.M12 * matrix.M21;
			minor2 = matrix.M11 * matrix.M23 - matrix.M13 * matrix.M21;
			minor3 = matrix.M11 * matrix.M24 - matrix.M14 * matrix.M21;
			minor4 = matrix.M12 * matrix.M23 - matrix.M13 * matrix.M22;
			minor5 = matrix.M12 * matrix.M24 - matrix.M14 * matrix.M22;
			minor6 = matrix.M13 * matrix.M24 - matrix.M14 * matrix.M23;

			minor7 = matrix.M31 * matrix.M42 - matrix.M32 * matrix.M41;
			minor8 = matrix.M31 * matrix.M43 - matrix.M33 * matrix.M41;
			minor9 = matrix.M31 * matrix.M44 - matrix.M34 * matrix.M41;
			minor10 = matrix.M32 * matrix.M43 - matrix.M33 * matrix.M42;
			minor11 = matrix.M32 * matrix.M44 - matrix.M34 * matrix.M42;
			minor12 = matrix.M33 * matrix.M44 - matrix.M34 * matrix.M43;

			determinant = minor1 * minor12 - minor2 * minor11 + minor3 * minor10 + minor4 * minor9 - minor5 * minor8 + minor6 * minor7;
		}
		Matrix4 Matrix4::Lerp(Matrix4 matrixA, Matrix4 matrixB, float amount)
		{
			Matrix4 result;
			Lerp(matrixA, matrixB, amount, result);
			return result;
		}
		void Matrix4::Lerp(Matrix4 matrixA, Matrix4 matrixB, float amount, Matrix4& result)
		{
			result.M11 = matrixA.M11 + (matrixB.M11 - matrixA.M11) * amount;
			result.M12 = matrixA.M12 + (matrixB.M12 - matrixA.M12) * amount;
			result.M13 = matrixA.M13 + (matrixB.M13 - matrixA.M13) * amount;
			result.M14 = matrixA.M14 + (matrixB.M14 - matrixA.M14) * amount;
			result.M21 = matrixA.M21 + (matrixB.M21 - matrixA.M21) * amount;
			result.M22 = matrixA.M22 + (matrixB.M22 - matrixA.M22) * amount;
			result.M23 = matrixA.M23 + (matrixB.M23 - matrixA.M23) * amount;
			result.M24 = matrixA.M24 + (matrixB.M24 - matrixA.M24) * amount;
			result.M31 = matrixA.M31 + (matrixB.M31 - matrixA.M31) * amount;
			result.M32 = matrixA.M32 + (matrixB.M32 - matrixA.M32) * amount;
			result.M33 = matrixA.M33 + (matrixB.M33 - matrixA.M33) * amount;
			result.M34 = matrixA.M34 + (matrixB.M34 - matrixA.M34) * amount;
			result.M41 = matrixA.M41 + (matrixB.M41 - matrixA.M41) * amount;
			result.M42 = matrixA.M42 + (matrixB.M42 - matrixA.M42) * amount;
			result.M43 = matrixA.M43 + (matrixB.M43 - matrixA.M43) * amount;
			result.M44 = matrixA.M44 + (matrixB.M44 - matrixA.M44) * amount;
		}
		Matrix4 Matrix4::Transform(Matrix4 matrix, Quaternion rotation)
		{
			Matrix4 result;
			Transform(matrix, rotation, result);
			return result;
		}
		void Matrix4::Transform(Matrix4 matrix, Quaternion rotation, Matrix4& result)
		{
			CreateFromQuaternion(rotation, result);
			Multiply(matrix, result, result);
		}
		Matrix4 Matrix4::Transpose(Matrix4 matrix)
		{
			Matrix4 result;
			Transpose(matrix, result);
			return result;
		}
		void Matrix4::Transpose(Matrix4 matrix, Matrix4& result)
		{
			result = Matrix4::Zero;
			result.M11 = matrix.M11;
			result.M21 = matrix.M12;
			result.M31 = matrix.M13;
			result.M41 = matrix.M14;

			result.M12 = matrix.M21;
			result.M22 = matrix.M22;
			result.M32 = matrix.M23;
			result.M42 = matrix.M24;

			result.M13 = matrix.M31;
			result.M23 = matrix.M32;
			result.M33 = matrix.M33;
			result.M43 = matrix.M34;

			result.M14 = matrix.M41;
			result.M24 = matrix.M42;
			result.M34 = matrix.M43;
			result.M44 = matrix.M44;
		}
		Vector3 Matrix4::ToEular() const
		{
			Vector3 v;
			ToEular(v);
			return v;
		}
		void Matrix4::ToEular(Vector3& result) const
		{
			if (M21 > 0.998)
			{
				result.Y = atan2(M13, M33);
				result.X = 0;
				result.Z = MathHelper::PIOver2;
				return;
			}

			if (M21 < -0.998)
			{
				result.Y = atan2(M13, M33);
				result.X = 0;
				result.Z = -MathHelper::PIOver2;
				return;
			}

			result.Y = -atan2(-M31, M11);
			result.Z = -asin(M21);
			result.X = -atan2(-M23, M22);
		}
	}
}