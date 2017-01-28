#include "Quaternion.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"
#include "MathHelper.h"

namespace CFH
{
	namespace Math
	{
		const Quaternion Quaternion::Identity = Quaternion(0, 0, 0, 1);

		Quaternion::Quaternion() :
			X(0),
			Y(0),
			Z(0),
			W(0)
		{
		}
		Quaternion::Quaternion(float x, float y, float z, float w) :
			X(x),
			Y(y),
			Z(z),
			W(w)
		{
		}
		Quaternion::Quaternion(const Vector3& vector, float w) :
			X(vector.X),
			Y(vector.Y),
			Z(vector.Z),
			W(w)
		{
		}
		Quaternion::Quaternion(const Vector4& vector) :
			X(vector.X),
			Y(vector.Y),
			Z(vector.Z),
			W(vector.W)
		{
		}
		Quaternion::~Quaternion()
		{

		}

		Quaternion Quaternion::operator+(const Quaternion& quaternion) const
		{
			Quaternion result;
			Add(*this, quaternion, result);
			return result;
		}
		Quaternion Quaternion::operator/(const Quaternion& quaternion) const
		{
			Quaternion result;
			Divide(*this, quaternion, result);
			return result;
		}
		Quaternion Quaternion::operator/(float factor) const
		{
			Quaternion result;
			Divide(*this, factor, result);
			return result;
		}
		Quaternion Quaternion::operator*(const Quaternion& quaternion) const
		{
			Quaternion result;
			Multiply(*this, quaternion, result);
			return result;
		}
		Quaternion Quaternion::operator*(float factor) const
		{
			Quaternion result;
			Multiply(*this, factor, result);
			return result;
		}
		Quaternion Quaternion::operator-(const Quaternion& quaternion) const
		{
			Quaternion result;
			Subtract(*this, quaternion, result);
			return result;
		}
		Quaternion Quaternion::operator-() const
		{
			Quaternion result;
			Negate(*this, result);
			return result;
		}
		const Quaternion& Quaternion::operator+=(const Quaternion& quaternion)
		{
			Add(*this, quaternion, *this);
			return *this;
		}
		const Quaternion& Quaternion::operator-=(const Quaternion& quaternion)
		{
			Subtract(*this, quaternion, *this);
			return *this;
		}
		const Quaternion& Quaternion::operator*=(const Quaternion& quaternion)
		{
			Multiply(*this, quaternion, *this);
			return *this;
		}
		const Quaternion& Quaternion::operator/=(const Quaternion& quaternion)
		{
			Divide(*this, quaternion, *this);
			return *this;
		}
		bool Quaternion::operator==(const Quaternion& quaternion) const
		{
			return X == quaternion.X && Y == quaternion.Y &&
				Z == quaternion.Z && W == quaternion.W;
		}
		bool Quaternion::operator!=(const Quaternion& quaternion) const
		{
			return X != quaternion.X || Y != quaternion.Y ||
				Z != quaternion.Z || W != quaternion.W;
		}
		const Quaternion& Quaternion::operator=(const Quaternion& quaternion)
		{
			X = quaternion.X;
			Y = quaternion.Y;
			Z = quaternion.Z;
			W = quaternion.W;
			return *this;
		}

		Vector3 Quaternion::GetForward() const
		{
			Vector3 result;
			GetForward(result);
			return result;
		}
		void Quaternion::GetForward(Vector3& result) const
		{
			result = Vector3(2 * (X * Z + W * Z),
				2 * (Y * Z - W * X),
				1 - 2 * (X * X + Y * Y));
		}
		Vector3 Quaternion::GetBackward() const
		{
			Vector3 result;
			GetBackward(result);
			return result;
		}
		void Quaternion::GetBackward(Vector3& result) const
		{
			GetForward(result);
			Vector3::Negate(result, result);
		}
		Vector3 Quaternion::GetRight() const
		{
			Vector3 result;
			GetRight(result);
			return result;
		}
		void Quaternion::GetRight(Vector3& result) const
		{
			result = Vector3(1 - 2 * (Y * Y + Z * Z),
				2 * (X * Y + W * Z),
				2 * (X * Z - W * Y));
		}
		Vector3 Quaternion::GetLeft() const
		{
			Vector3 result;
			GetLeft(result);
			return result;
		}
		void Quaternion::GetLeft(Vector3& result) const
		{
			GetRight(result);
			Vector3::Negate(result, result);
		}
		Vector3 Quaternion::GetUp() const
		{
			Vector3 result;
			GetUp(result);
			return result;
		}
		void Quaternion::GetUp(Vector3& result) const
		{
			result = Vector3(2 * (X * Y - W * Z),
				1 - 2 * (X * X + Z * Z),
				2 * (Y * Z + W * X));
		}
		Vector3 Quaternion::GetDown() const
		{
			Vector3 result;
			GetDown(result);
			return result;
		}
		void Quaternion::GetDown(Vector3& result) const
		{
			GetUp(result);
			Vector3::Negate(result, result);
		}

		Quaternion Quaternion::Add(const Quaternion& quaternionA, const Quaternion& quaternionB)
		{
			Quaternion result;
			Add(quaternionA, quaternionB, result);
			return result;
		}
		void Quaternion::Add(const Quaternion& quaternionA, const Quaternion& quaternionB, Quaternion& result)
		{
			result.X = quaternionA.X + quaternionB.X;
			result.Y = quaternionA.Y + quaternionB.Y;
			result.Z = quaternionA.Z + quaternionB.Z;
			result.W = quaternionA.W + quaternionB.W;
		}
		Quaternion Quaternion::Subtract(const Quaternion& quaternionA, const Quaternion& quaternionB)
		{
			Quaternion result;
			Subtract(quaternionA, quaternionB, result);
			return result;
		}
		void Quaternion::Subtract(const Quaternion& quaternionA, const Quaternion& quaternionB, Quaternion& result)
		{
			result.X = quaternionA.X - quaternionB.X;
			result.Y = quaternionA.Y - quaternionB.Y;
			result.Z = quaternionA.Z - quaternionB.Z;
			result.W = quaternionA.W - quaternionB.W;
		}
		Quaternion Quaternion::Multiply(const Quaternion& quaternionA, const Quaternion& quaternionB)
		{
			Quaternion result;
			Multiply(quaternionA, quaternionB, result);
			return result;
		}
		void Quaternion::Multiply(const Quaternion& quaternionA, const Quaternion& quaternionB, Quaternion& result)
		{
			result.X = quaternionA.W * quaternionB.X + quaternionB.W * quaternionA.X + quaternionA.Y * quaternionB.Z - quaternionA.Z * quaternionB.Y;
			result.Y = quaternionA.W * quaternionB.Y + quaternionB.W * quaternionA.Y + quaternionA.Z * quaternionB.X - quaternionA.X * quaternionB.Z;
			result.Z = quaternionA.W * quaternionB.Z + quaternionB.W * quaternionA.Z + quaternionA.X * quaternionB.Y - quaternionA.Y * quaternionB.X;
			result.W = quaternionA.W * quaternionB.W - quaternionA.X * quaternionB.X - quaternionA.Y * quaternionB.Y - quaternionA.Z * quaternionB.Z;
		}
		Quaternion Quaternion::Multiply(const Quaternion& quaternionA, float scalar)
		{
			Quaternion result;
			Multiply(quaternionA, scalar, result);
			return result;
		}
		void Quaternion::Multiply(const Quaternion& quaternion, float scalar, Quaternion& result)
		{
			result.X = quaternion.X * scalar;
			result.Y = quaternion.Y * scalar;
			result.Z = quaternion.Z * scalar;
			result.W = quaternion.W * scalar;
		}
		Quaternion Quaternion::Divide(const Quaternion& quaternionA, const Quaternion& quaternionB)
		{
			Quaternion result;
			Divide(quaternionA, quaternionB, result);
			return result;
		}
		void Quaternion::Divide(const Quaternion& quaternionA, const Quaternion& quaternionB, Quaternion& result)
		{
			Inverse(quaternionB, result);
			Multiply(quaternionA, result, result);
		}
		Quaternion Quaternion::Divide(const Quaternion& quaternion, float factor)
		{
			Quaternion result;
			Divide(quaternion, factor, result);
			return result;
		}
		void Quaternion::Divide(const Quaternion& quaternion, float factor, Quaternion& result)
		{
			result.X = quaternion.X / factor;
			result.Y = quaternion.Y / factor;
			result.Z = quaternion.Z / factor;
			result.W = quaternion.W / factor;
		}
		Quaternion Quaternion::Negate(const Quaternion& quaternion)
		{
			Quaternion result;
			Negate(quaternion, result);
			return result;
		}
		void Quaternion::Negate(const Quaternion& quaternion, Quaternion& result)
		{
			result.X = -quaternion.X;
			result.Y = -quaternion.Y;
			result.Z = -quaternion.Z;
			result.W = -quaternion.W;
		}

		Quaternion Quaternion::CreateFromAxisAngle(const Vector3& axis, float angle)
		{
			Quaternion result;
			CreateFromAxisAngle(axis, angle, result);
			return result;
		}
		void Quaternion::CreateFromAxisAngle(const Vector3& axis, float angle, Quaternion& result)
		{
			float a = angle * 0.5f;
			Vector3 v = axis;
			v.Normalize();
			Vector3::Multiply(v, MathHelper::Sin(a), v);
			result.X = v.X;
			result.Y = v.Y;
			result.Z = v.Z;
			result.W = MathHelper::Cos(a);
		}
		Quaternion Quaternion::CreateFromRotationMatrix(const Matrix4& matrix)
		{
			Quaternion result;
			CreateFromRotationMatrix(matrix, result);
			return result;
		}
		void Quaternion::CreateFromRotationMatrix(const Matrix4& matrix, Quaternion& result)
		{
			result.W = MathHelper::Sqrt(matrix.M11 + matrix.M22 + matrix.M33 + 1) / 2;
			result.X = (matrix.M23 - matrix.M32) / (4 * result.W);
			result.Y = (matrix.M31 - matrix.M13) / (4 * result.W);
			result.Z = (matrix.M12 - matrix.M21) / (4 * result.W);
			result.Normalize();
		}
		Quaternion Quaternion::CreateFromYawPitchRoll(float yaw, float pitch, float roll)
		{
			Quaternion result;
			CreateFromYawPitchRoll(yaw, pitch, roll, result);
			return result;
		}
		void Quaternion::CreateFromYawPitchRoll(float yaw, float pitch, float roll, Quaternion& result)
		{
			float ro2 = roll * 0.5f;
			float cro2 = MathHelper::Cos(ro2);
			float sro2 = MathHelper::Sin(ro2);

			float po2 = pitch * 0.5f;
			float cpo2 = MathHelper::Cos(po2);
			float spo2 = MathHelper::Sin(po2);

			float yo2 = yaw * 0.5f;
			float cyo2 = MathHelper::Cos(yo2);
			float syo2 = MathHelper::Sin(yo2);

			result.W = cyo2 * cpo2 * cro2 + syo2 * spo2 * sro2;
			result.Z = cyo2 * cpo2 * sro2 - syo2 * spo2 * cro2;
			result.X = cyo2 * spo2 * cro2 + syo2 * cpo2 * sro2;
			result.Y = syo2 * cpo2 * cro2 - cyo2 * spo2 * sro2;
		}

		Quaternion Quaternion::Concatenate(const Quaternion& quaternionA, const Quaternion& quaternionB)
		{
			Quaternion result;
			Concatenate(quaternionA, quaternionB, result);
			return result;
		}
		void Quaternion::Concatenate(const Quaternion& quaternionA, const Quaternion& quaternionB, Quaternion& result)
		{
			Multiply(quaternionA, quaternionB, result);
		}
		void Quaternion::Conjugate()
		{
			Conjugate(*this, *this);
		}
		Quaternion Quaternion::Conjugate(const Quaternion& quaternion)
		{
			Quaternion result;
			Conjugate(quaternion, result);
			return result;
		}
		void Quaternion::Conjugate(const Quaternion& quaternion, Quaternion& result)
		{
			result.X = -quaternion.X;
			result.Y = -quaternion.Y;
			result.Z = -quaternion.Z;
			result.W = quaternion.W;
		}
		float Quaternion::Dot(const Quaternion& quaternionA, const Quaternion& quaternionB)
		{
			float result;
			Dot(quaternionA, quaternionB, result);
			return result;
		}
		void Quaternion::Dot(const Quaternion& quaternionA, const Quaternion& quaternionB, float& result)
		{
			result = quaternionA.X * quaternionB.X + quaternionA.Y * quaternionB.Y +
				quaternionA.Z * quaternionB.Z + quaternionA.W * quaternionB.W;
		}
		Quaternion Quaternion::Inverse(const Quaternion& quaternion)
		{
			Quaternion result;
			Inverse(quaternion, result);
			return result;
		}
		void Quaternion::Inverse(const Quaternion& quaternion, Quaternion& result)
		{
			Conjugate(quaternion, result);
			Multiply(result, 1.0f / result.LengthSquared(), result);
		}
		float Quaternion::Length() const
		{
			float result;
			Length(result);
			return result;
		}
		void Quaternion::Length(float& result) const
		{
			LengthSquared(result);
			result = MathHelper::Sqrt(result);
		}
		float Quaternion::LengthSquared() const
		{
			float result;
			LengthSquared(result);
			return result;
		}
		void Quaternion::LengthSquared(float& result) const
		{
			result = X * X + Y * Y +
				Z * Z + W * W;
		}
		Quaternion Quaternion::Lerp(const Quaternion& quaternionA, const Quaternion& quaternionB, float amount)
		{
			Quaternion result;
			Lerp(quaternionA, quaternionB, amount, result);
			return result;
		}
		void Quaternion::Lerp(const Quaternion& quaternionA, const Quaternion& quaternionB, float amount, Quaternion& result)
		{
			Multiply(quaternionA, 1.0f - amount, result);
			Add(result, Multiply(quaternionB, amount), result);
			result.Normalize();
		}
		void Quaternion::Normalize()
		{
			Normalize(*this, *this);
		}
		Quaternion Quaternion::Normalize(const Quaternion& quaternion)
		{
			Quaternion result;
			Normalize(quaternion, result);
			return result;
		}
		void Quaternion::Normalize(const Quaternion& quaternion, Quaternion& result)
		{
			Multiply(quaternion, 1.0f / quaternion.Length(), result);
		}
		Quaternion Quaternion::Slerp(const Quaternion& quaternionA, const Quaternion& quaternionB, float amount)
		{
			Quaternion result;
			Slerp(quaternionA, quaternionB, amount, result);
			return result;
		}
		void Quaternion::Slerp(const Quaternion& quaternionA, const Quaternion& quaternionB, float amount, Quaternion& result)
		{
			Quaternion p = quaternionA;
			Quaternion q = quaternionB;

			if ((p - q).LengthSquared() > (p + q).LengthSquared())
				p = -p;

			float cosPhi;
			Dot(p, q, cosPhi);

			if (cosPhi > 0.999f)
			{
				Lerp(p, q, amount, result);
				return;
			}

			float phi = MathHelper::ACos(cosPhi);
			float sinPhi = MathHelper::Sin(phi);

			Multiply(p, MathHelper::Sin(phi * (1.0f - amount)) / sinPhi, p);
			Multiply(q, MathHelper::Sin(phi * amount) / sinPhi, q);
			Add(p, q, result);
			result.Normalize();
		}
		Vector3 Quaternion::ToEular() const
		{
			Vector3 result;
			ToEular(result);
			return result;
		}
		void Quaternion::ToEular(Vector3& result) const
		{
			float t = X * Y + Z * W;

			if (t > 0.499)
			{
				result.Y = 2 * MathHelper::ATan2(X, W);
				result.X = MathHelper::PIOver2;
				result.Z = 0;
				return;
			}
			else if (t < -0.499)
			{
				result.Y = -2 * MathHelper::ATan2(X, W);
				result.X = -MathHelper::PIOver2;
				result.Z = 0;
				return;
			}

			double sqx = X * X;
			double sqy = Y * Y;
			double sqz = Z * Z;
			result.X = MathHelper::ATan2(2 * Y * W - 2 * X * Z, (float)(1 - 2 * sqy - 2 * sqz));
			result.Z = MathHelper::ASin(2 * t);
			result.Y = MathHelper::ATan2(2 * X * W - 2 * Y * Z, (float)(1 - 2 * sqx - 2 * sqz));
		}
	}
}