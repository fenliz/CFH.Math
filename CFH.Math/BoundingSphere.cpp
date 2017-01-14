#include "BoundingSphere.h"
#include "BoundingBox.h"
#include "BoundingFrustum.h"
#include "Ray.h"
#include "MathHelper.h"

namespace CFH
{
	namespace Math
	{
		BoundingSphere::BoundingSphere() :
			Center(Vector3::Zero),
			Radius(0)
		{
		}
		BoundingSphere::BoundingSphere(Vector3 center, float radius) :
			Center(center),
			Radius(radius)
		{
		}
		BoundingSphere::~BoundingSphere()
		{

		}

		bool BoundingSphere::operator==(BoundingSphere boundingSphere) const
		{
			return Center == boundingSphere.Center && Radius == boundingSphere.Radius;
		}
		bool BoundingSphere::operator!=(BoundingSphere boundingSphere) const
		{
			return Center != boundingSphere.Center || Radius != boundingSphere.Radius;
		}
		BoundingSphere BoundingSphere::operator=(BoundingSphere boundingSphere)
		{
			Center = boundingSphere.Center;
			Radius = boundingSphere.Radius;
			return *this;
		}

		BoundingSphere BoundingSphere::CreateFromBoundingBox(BoundingBox boundingBox)
		{
			BoundingSphere result;
			CreateFromBoundingBox(boundingBox, result);
			return result;
		}
		void BoundingSphere::CreateFromBoundingBox(BoundingBox boundingBox, BoundingSphere& result)
		{
			result.Center.X = (boundingBox.Min.X + boundingBox.Max.X) / 2;
			result.Center.Y = (boundingBox.Min.Y + boundingBox.Max.Y) / 2;
			result.Center.Z = (boundingBox.Min.Z + boundingBox.Max.Z) / 2;
			Vector3::Distance(result.Center, boundingBox.Max, result.Radius);
		}
		BoundingSphere BoundingSphere::CreateFromFrustum(BoundingFrustum boundingFrustum)
		{
			BoundingSphere result;
			CreateFromFrustum(boundingFrustum, result);
			return result;
		}
		void BoundingSphere::CreateFromFrustum(BoundingFrustum boundingFrustum, BoundingSphere& result)
		{
			Vector3 corners[8];
			for (char i = 0; i < BoundingFrustum::Corners; i++)
				boundingFrustum.GetCorner(i, corners[i]);
			CreateFromPoints(corners, BoundingFrustum::Corners, result);
		}
		BoundingSphere BoundingSphere::CreateFromPoints(Vector3 points[], int count)
		{
			BoundingSphere result;
			CreateFromPoints(points, count, result);
			return result;
		}
		void BoundingSphere::CreateFromPoints(Vector3 points[], int count, BoundingSphere& result)
		{
			result.Center = Vector3::Zero;
			for (int i = 0; i < count; i++)
				Vector3::Add(result.Center, points[i], result.Center);
			Vector3::Divide(result.Center, (float)count, result.Center);

			Vector3 v;
			float t = 0;
			result.Radius = 0;
			for (int i = 0; i < count; i++)
			{
				Vector3::Subtract(points[i], result.Center, v);
				v.LengthSquared(t);
				if (t > result.Radius)
					result.Radius = t;
			}

			result.Radius = MathHelper::Abs(MathHelper::Sqrt(result.Radius));
		}
		BoundingSphere BoundingSphere::CreateMerged(BoundingSphere boundingSphere, BoundingSphere boundingSphere2)
		{
			BoundingSphere result;
			CreateMerged(boundingSphere, boundingSphere2, result);
			return result;
		}
		void BoundingSphere::CreateMerged(BoundingSphere boundingSphere, BoundingSphere boundingSphere2, BoundingSphere& result)
		{
			Vector3::Subtract(boundingSphere2.Center, boundingSphere.Center, result.Center);
			float d;
			result.Center.Length(d);

			if (d <= boundingSphere.Radius + boundingSphere2.Radius)
			{
				if (boundingSphere.Radius - d >= boundingSphere2.Radius)
				{
					result = boundingSphere;
					return;
				}
				else if (boundingSphere2.Radius - d >= boundingSphere.Radius)
				{
					result = boundingSphere2;
					return;
				}
			}

			float m = (result.Radius = (d + boundingSphere2.Radius + boundingSphere.Radius) / 2) - boundingSphere.Radius;
			Vector3::Divide(result.Center, d, result.Center);
			Vector3::Multiply(result.Center, m, result.Center);
			Vector3::Add(result.Center, boundingSphere.Center, result.Center);
		}

		ContainmentType BoundingSphere::Contains(Vector3 point) const
		{
			ContainmentType result;
			Contains(point, result);
			return result;
		}
		void BoundingSphere::Contains(Vector3 point, ContainmentType& result) const
		{
			float d, r2 = Radius * Radius;
			Vector3::DistanceSquared(point, Center, d);
			if (d < r2)
				result = ContainmentType::Contains;
			else if (d > r2)
				result = ContainmentType::Disjoint;
			else
				result = ContainmentType::Intersects;
		}
		ContainmentType BoundingSphere::Contains(BoundingBox boundingBox) const
		{
			ContainmentType result;
			Contains(boundingBox, result);
			return result;
		}
		void BoundingSphere::Contains(BoundingBox boundingBox, ContainmentType& result) const
		{
			Vector3 v;
			char i;
			bool containsAll = true;
			for (i = 0; i < BoundingBox::Corners; i++)
			{
				boundingBox.GetCorner(i, v);
				Contains(v, result);
				if (result == ContainmentType::Disjoint)
				{
					containsAll = false;
					break;
				}
			}

			if (containsAll)
			{
				result = ContainmentType::Contains;
				return;
			}

			boundingBox.Contains(*this, result);
			if (result != ContainmentType::Disjoint)
				result = ContainmentType::Intersects;
		}
		ContainmentType BoundingSphere::Contains(BoundingFrustum boundingFrustum) const
		{
			ContainmentType result;
			Contains(boundingFrustum, result);
			return result;
		}
		void BoundingSphere::Contains(BoundingFrustum boundingFrustum, ContainmentType& result) const
		{
			Vector3 v;
			bool containsAll = true;
			for (char i = 0; i < BoundingFrustum::Corners; i++)
			{
				boundingFrustum.GetCorner(i, v);
				Contains(v, result);
				if (result == ContainmentType::Disjoint)
				{
					containsAll = false;
					break;
				}
			}

			if (containsAll)
			{
				result = ContainmentType::Contains;
				return;
			}

			boundingFrustum.Contains(*this, result);
			if (result != ContainmentType::Disjoint)
				result = ContainmentType::Intersects;
		}
		ContainmentType BoundingSphere::Contains(BoundingSphere boundingSphere) const
		{
			ContainmentType result;
			Contains(boundingSphere, result);
			return result;
		}
		void BoundingSphere::Contains(BoundingSphere boundingSphere, ContainmentType& result) const
		{
			float d;
			Vector3::Distance(Center, boundingSphere.Center, d);
			if (d + boundingSphere.Radius <= Radius)
				result = ContainmentType::Contains;
			else if (d > Radius + boundingSphere.Radius)
				result = ContainmentType::Disjoint;
			else
				result = ContainmentType::Intersects;
		}

		bool BoundingSphere::Intersects(BoundingBox boundingBox) const
		{
			ContainmentType result;
			Contains(boundingBox, result);
			return result != ContainmentType::Disjoint;
		}
		bool BoundingSphere::Intersects(BoundingFrustum boundingFrustum) const
		{
			ContainmentType result;
			Contains(boundingFrustum, result);
			return result != ContainmentType::Disjoint;
		}
		bool BoundingSphere::Intersects(BoundingSphere boundingSphere) const
		{
			ContainmentType result;
			Contains(boundingSphere, result);
			return result != ContainmentType::Disjoint;
		}
		PlaneIntersectionType BoundingSphere::Intersects(Plane plane) const
		{
			PlaneIntersectionType p;
			Intersects(plane, p);
			return p;
		}
		void BoundingSphere::Intersects(Plane plane, PlaneIntersectionType& result) const
		{
			plane.Intersects(*this, result);
		}
		bool BoundingSphere::Intersects(Ray ray, float& distance) const
		{
			return ray.Intersects(*this, distance);
		}

		BoundingSphere BoundingSphere::Transform(Matrix4 matrix)
		{
			BoundingSphere result;
			Transform(matrix, result);
			return result;
		}
		void BoundingSphere::Transform(Matrix4 matrix, BoundingSphere& result)
		{
			Vector3::Transform(Center, matrix, result.Center);

			float scale;
			MathHelper::Max(MathHelper::Max(matrix.GetScaleX(), matrix.GetScaleY()), matrix.GetScaleZ(), scale);
			result.Radius *= scale;
		}
	}
}
