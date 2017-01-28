#include "BoundingFrustum.h"
#include "BoundingBox.h"
#include "BoundingSphere.h"
#include "Vector4.h"
#include "Ray.h"
#include "MathHelper.h"

#include <stdexcept>
#include <limits>

namespace CFH
{
	namespace Math
	{
		BoundingFrustum::BoundingFrustum()
		{
		}
		BoundingFrustum::BoundingFrustum(const Matrix4& value)
		{
			SetViewProjection(value);
		}
		BoundingFrustum::~BoundingFrustum()
		{
		}

		bool BoundingFrustum::operator==(const BoundingFrustum& boundingFrustum) const
		{
			return viewProjection_ == boundingFrustum.viewProjection_;
		}
		bool BoundingFrustum::operator!=(const BoundingFrustum& boundingFrustum) const
		{
			return viewProjection_ != boundingFrustum.viewProjection_;
		}
		const BoundingFrustum& BoundingFrustum::operator=(const BoundingFrustum& boundingFrustum)
		{
			viewProjection_ = boundingFrustum.viewProjection_;
			inverseViewProjection_ = boundingFrustum.inverseViewProjection_;
			return *this;
		}

		void BoundingFrustum::CalculateCorner(int index, Vector3& result) const
		{
			Vector4 v = Vector4(0, 0, 0, 1);

			switch (index)
			{
			case 0:
				v.X = -1;
				v.Y = -1;
				v.Z = 0;
				break;
			case 1:
				v.X = -1;
				v.Y = 1;
				v.Z = 0;
				break;
			case 2:
				v.X = 1;
				v.Y = 1;
				v.Z = 0;
				break;
			case 3:
				v.X = 1;
				v.Y = -1;
				v.Z = 0;
				break;
			case 4:
				v.X = -1;
				v.Y = -1;
				v.Z = 1;
				break;
			case 5:
				v.X = -1;
				v.Y = 1;
				v.Z = 1;
				break;
			case 6:
				v.X = 1;
				v.Y = 1;
				v.Z = 1;
				break;
			case 7:
				v.X = 1;
				v.Y = -1;
				v.Z = 1;
				break;

			default:
				throw std::invalid_argument("Max valid index of a BoundingFrustrums corners is 7.");
			}

			Vector4::Transform(v, inverseViewProjection_, v);
			result.X = v.X / v.W;
			result.Y = v.Y / v.W;
			result.Z = v.Z / v.W;

		}

		void BoundingFrustum::SetViewProjection(const Matrix4& matrix)
		{
			viewProjection_ = matrix;
			Matrix4::Invert(viewProjection_, inverseViewProjection_);

			for (char i = 0; i < 8; i++)
				CalculateCorner(i, corners_[i]);

			Plane::CreateFromPoints(corners_[0], corners_[3], corners_[1], planes_[0]); //Near
			Plane::CreateFromPoints(corners_[4], corners_[5], corners_[7], planes_[1]); //Far

			Plane::CreateFromPoints(corners_[2], corners_[3], corners_[6], planes_[2]); //Right
			Plane::CreateFromPoints(corners_[1], corners_[5], corners_[0], planes_[3]); //Left

			Plane::CreateFromPoints(corners_[1], corners_[2], corners_[5], planes_[4]); //Top
			Plane::CreateFromPoints(corners_[0], corners_[4], corners_[3], planes_[5]); //Bottom
		}
		const Matrix4& BoundingFrustum::GetViewProjection() const
		{
			return viewProjection_;
		}
		void BoundingFrustum::GetViewProjection(Matrix4& result) const
		{
			result = viewProjection_;
		}
		const Matrix4& BoundingFrustum::GetInverseViewProjection() const
		{
			return inverseViewProjection_;
		}
		void BoundingFrustum::GetInverseViewProjection(Matrix4& result) const
		{
			result = inverseViewProjection_;
		}

		const Plane& BoundingFrustum::GetTop() const
		{
			return planes_[4];
		}
		void BoundingFrustum::GetTop(Plane& result) const
		{
			result = planes_[4];
		}
		const Plane& BoundingFrustum::GetBottom() const
		{
			return planes_[5];
		}
		void BoundingFrustum::GetBottom(Plane& result) const
		{
			result = planes_[5];
		}
		const Plane& BoundingFrustum::GetFar() const
		{
			return planes_[1];
		}
		void BoundingFrustum::GetFar(Plane& result) const
		{
			result = planes_[1];
		}
		const Plane& BoundingFrustum::GetNear() const
		{
			return planes_[0];
		}
		void BoundingFrustum::GetNear(Plane& result) const
		{
			result = planes_[0];
		}
		const Plane& BoundingFrustum::GetLeft() const
		{
			return planes_[3];
		}
		void BoundingFrustum::GetLeft(Plane& result) const
		{
			result = planes_[3];
		}
		const Plane& BoundingFrustum::GetRight() const
		{
			return planes_[2];
		}
		void BoundingFrustum::GetRight(Plane& result) const
		{
			result = planes_[2];
		}
		void BoundingFrustum::GetCorners(Vector3* corners, int size) const
		{
			for (char i = 0; i < 8 && i < size; i++)
				GetCorner(i, corners[i]);
		}
		const Vector3& BoundingFrustum::GetCorner(int index) const
		{
			return corners_[index];
		}
		void BoundingFrustum::GetCorner(int index, Vector3& result) const
		{
			result = corners_[index];
		}
		const Plane& BoundingFrustum::GetPlane(int index) const
		{
			if (index >= 0 && index <= 5)
				return planes_[index];
			else
				throw std::invalid_argument("Max valid index of a BoundingFrustrums planes is 5.");
		}
		void BoundingFrustum::GetPlane(int index, Plane& result) const
		{
			if (index >= 0 && index <= 5)
				result = planes_[index];
			else
				throw std::invalid_argument("Max valid index of a BoundingFrustrums planes is 5.");
		}

		ContainmentType BoundingFrustum::Contains(const Vector3& point) const
		{
			ContainmentType result;
			Contains(point, result);
			return result;
		}
		void BoundingFrustum::Contains(const Vector3& point, ContainmentType& result) const
		{
			Vector4 v = Vector4(point.X, point.Y, point.Z, 1);
			Vector4::Transform(v, viewProjection_, v);
			Vector4::Divide(v, v.W, v);

			if (v.X > 1 || v.X < -1 || v.Y > 1 || v.Y < -1 || v.Z > 1 || v.Z < 0)
				result = ContainmentType::Disjoint;
			else
				result = ContainmentType::Contains;
		}
		ContainmentType BoundingFrustum::Contains(const BoundingBox& boundingBox) const
		{
			ContainmentType result;
			Contains(boundingBox, result);
			return result;
		}
		void BoundingFrustum::Contains(const BoundingBox& boundingBox, ContainmentType& result) const
		{
			Vector3 v;
			char i, in = 0, out = 0;
			for (i = 0; i < BoundingBox::Corners; i++)
			{
				boundingBox.GetCorner(i, v);
				Contains(v, result);
				if (result == ContainmentType::Contains)
					in++;
				else
					out++;

				if (in > 0 && out > 0)
				{
					result = ContainmentType::Intersects;
					return;
				}
			}

			if (in == BoundingBox::Corners)
			{
				result = ContainmentType::Contains;
				return;
			}

			for (i = 0; i < BoundingFrustum::Corners; i++)
			{
				GetCorner(i, v);
				MathHelper::Clamp(v.X, boundingBox.Min.X, boundingBox.Max.X, v.X);
				MathHelper::Clamp(v.Y, boundingBox.Min.Y, boundingBox.Max.Y, v.Y);
				MathHelper::Clamp(v.Z, boundingBox.Min.Z, boundingBox.Max.Z, v.Z);
				Contains(v, result);

				if (result != ContainmentType::Disjoint)
				{
					result = ContainmentType::Intersects;
					return;
				}
			}

			result = ContainmentType::Disjoint;
		}
		ContainmentType BoundingFrustum::Contains(const BoundingFrustum& boundingFrustum) const
		{
			ContainmentType result;
			Contains(boundingFrustum, result);
			return result;
		}
		void BoundingFrustum::Contains(const BoundingFrustum& boundingFrustum, ContainmentType& result) const
		{
			Vector3 v;
			float dist, aMax, aMin, bMax, bMin;
			bool containsAll = true;
			for (char i = 0, k = 0; i < BoundingFrustum::Planes; i++)
			{
				aMin = bMin = std::numeric_limits<float>::max();
				aMax = bMax = -std::numeric_limits<float>::max();

				for (k = 0; k < BoundingFrustum::Corners; k++)
				{
					boundingFrustum.GetCorner(k, v);
					planes_[i].Distance(v, dist);
					MathHelper::Min(dist, aMin, aMin);
					MathHelper::Max(dist, aMax, aMax);

					if (dist > 1e-9)
						containsAll = false;

					GetCorner(k, v);
					planes_[i].Distance(v, dist);
					MathHelper::Min(dist, bMin, bMin);
					MathHelper::Max(dist, bMax, bMax);
				}

				if (aMin > bMax || aMax < bMin)
				{
					result = ContainmentType::Disjoint;
					return;
				}
			}

			if (containsAll)
				result = ContainmentType::Contains;
			else
				result = ContainmentType::Intersects;
		}
		ContainmentType BoundingFrustum::Contains(const BoundingSphere& boundingSphere) const
		{
			ContainmentType result;
			Contains(boundingSphere, result);
			return result;
		}
		void BoundingFrustum::Contains(const BoundingSphere& boundingSphere, ContainmentType& result) const
		{
			bool intersection = false;
			float dist;
			for (char i = 0; i < Planes; i++)
			{
				planes_[i].Distance(boundingSphere.Center, dist);

				if (dist - boundingSphere.Radius > 0)
				{
					result = ContainmentType::Disjoint;
					return;
				}
				else if (dist >= -boundingSphere.Radius && dist <= boundingSphere.Radius)
					intersection = true;
			}

			if (intersection)
				result = ContainmentType::Intersects;
			else
				result = ContainmentType::Contains;
		}

		bool BoundingFrustum::Intersects(const BoundingBox& boundingBox) const
		{
			bool result;
			Intersects(boundingBox, result);
			return result;
		}
		void BoundingFrustum::Intersects(const BoundingBox& boundingBox, bool& result) const
		{
			ContainmentType c;
			Contains(boundingBox, c);
			result = c != ContainmentType::Disjoint;
		}
		bool BoundingFrustum::Intersects(const BoundingFrustum& boundingFrustum) const
		{
			bool result;
			Intersects(boundingFrustum, result);
			return result;
		}
		void BoundingFrustum::Intersects(const BoundingFrustum& boundingFrustum, bool& result) const
		{
			ContainmentType c;
			Contains(boundingFrustum, c);
			result = c != ContainmentType::Disjoint;
		}
		bool BoundingFrustum::Intersects(const BoundingSphere& boundingSphere) const
		{
			bool result;
			Intersects(boundingSphere, result);
			return result;
		}
		void BoundingFrustum::Intersects(const BoundingSphere& boundingSphere, bool& result) const
		{
			ContainmentType c;
			Contains(boundingSphere, c);
			result = c != ContainmentType::Disjoint;
		}
		PlaneIntersectionType BoundingFrustum::Intersects(const Plane& plane) const
		{
			PlaneIntersectionType result;
			Intersects(plane, result);
			return result;
		}
		void BoundingFrustum::Intersects(const Plane& plane, PlaneIntersectionType& result) const
		{
			plane.Intersects(*this, result);
		}
		bool BoundingFrustum::Intersects(const Ray& ray, float& distance) const
		{
			bool result;
			Intersects(ray, distance, result);
			return result;
		}
		void BoundingFrustum::Intersects(const Ray& ray, float& distance, bool& result) const
		{
			result = ray.Intersects(*this, distance);
		}
	}
}