#include "BoundingBox.h"
#include "BoundingFrustum.h"
#include "BoundingSphere.h"
#include "Plane.h"
#include "Ray.h"
#include "MathHelper.h"

#include <limits>
#include <stdexcept>

namespace CFH
{
	namespace Math
	{
		BoundingBox::BoundingBox() :
			Min(Vector3::Zero),
			Max(Vector3::Zero)
		{
		}
		BoundingBox::BoundingBox(Vector3 min, Vector3 max) :
			Min(min),
			Max(max)
		{
		}
		BoundingBox::~BoundingBox()
		{
		}

		bool BoundingBox::operator==(BoundingBox boundingBox)
		{
			return Min == boundingBox.Min && Max == boundingBox.Max;
		}
		bool BoundingBox::operator!=(BoundingBox boundingBox)
		{
			return Min != boundingBox.Min || Max != boundingBox.Max;
		}
		BoundingBox BoundingBox::operator=(BoundingBox boundingBox)
		{
			Min = boundingBox.Min;
			Max = boundingBox.Max;
			return *this;
		}

		BoundingBox BoundingBox::CreateFromPoints(Vector3 points[], int count)
		{
			BoundingBox result;
			CreateFromPoints(points, count, result);
			return result;
		}
		void BoundingBox::CreateFromPoints(Vector3 points[], int count, BoundingBox& result)
		{
			float minX, minY, minZ;
			float maxX, maxY, maxZ;

			minX = minY = minZ = std::numeric_limits<float>::max();
			maxX = maxY = maxZ = std::numeric_limits<float>::min();

			for (int i = 0; i < count; i++)
			{
				if (points[i].X > maxX)
					maxX = points[i].X;
				else if (points[i].X < minX)
					minX = points[i].X;
				if (points[i].Y > maxY)
					maxY = points[i].Y;
				else if (points[i].Y < minY)
					minY = points[i].Y;
				if (points[i].Z > maxZ)
					maxZ = points[i].Z;
				else if (points[i].Z < minZ)
					minZ = points[i].Z;
			}

			result.Min.X = minX;
			result.Min.Y = minY;
			result.Min.Z = minZ;
			result.Max.X = maxX;
			result.Max.Y = maxY;
			result.Max.Z = maxZ;
		}
		BoundingBox BoundingBox::CreateFromSphere(BoundingSphere boundingSphere)
		{
			BoundingBox result;
			CreateFromSphere(boundingSphere, result);
			return result;
		}
		void BoundingBox::CreateFromSphere(BoundingSphere boundingSphere, BoundingBox& result)
		{
			result.Min = result.Max = boundingSphere.Center;
			result.Min.X -= boundingSphere.Radius;
			result.Min.Y -= boundingSphere.Radius;
			result.Min.Z -= boundingSphere.Radius;
			result.Max.X += boundingSphere.Radius;
			result.Max.Y += boundingSphere.Radius;
			result.Max.Z += boundingSphere.Radius;
		}
		BoundingBox BoundingBox::CreateMerged(BoundingBox boundingBox, BoundingBox boundingBox2)
		{
			BoundingBox result;
			CreateMerged(boundingBox, boundingBox2, result);
			return result;
		}
		void BoundingBox::CreateMerged(BoundingBox boundingBox, BoundingBox boundingBox2, BoundingBox& result)
		{
			MathHelper::Min(boundingBox.Min.X, boundingBox2.Min.X, result.Min.X);
			MathHelper::Min(boundingBox.Min.Y, boundingBox2.Min.Y, result.Min.Y);
			MathHelper::Min(boundingBox.Min.Z, boundingBox2.Min.Z, result.Min.Z);

			MathHelper::Max(boundingBox.Max.X, boundingBox2.Max.X, result.Max.X);
			MathHelper::Max(boundingBox.Max.Y, boundingBox2.Max.Y, result.Max.Y);
			MathHelper::Max(boundingBox.Max.Z, boundingBox2.Max.Z, result.Max.Z);
		}

		ContainmentType BoundingBox::Contains(BoundingBox boundingBox) const
		{
			ContainmentType result;
			Contains(boundingBox, result);
			return result;
		}
		void BoundingBox::Contains(BoundingBox boundingBox, ContainmentType& result) const
		{
			if ((Max.X < boundingBox.Min.X || Min.X > boundingBox.Max.X) ||
				(Max.Y < boundingBox.Min.Y || Min.Y > boundingBox.Max.Y) ||
				(Max.Z < boundingBox.Min.Z || Min.Z > boundingBox.Max.Z))
				result = ContainmentType::Disjoint;
			else if ((Min.X <= boundingBox.Min.X && Max.X >= boundingBox.Max.X) &&
				(Min.Y <= boundingBox.Min.Y && Max.Y >= boundingBox.Max.Y) &&
				(Min.Z <= boundingBox.Min.Z && Max.Z >= boundingBox.Max.Z))
				result = ContainmentType::Contains;
			else
				result = ContainmentType::Intersects;
		}
		ContainmentType BoundingBox::Contains(BoundingFrustum boundingFrustum) const
		{
			ContainmentType result;
			Contains(boundingFrustum, result);
			return result;
		}
		void BoundingBox::Contains(BoundingFrustum boundingFrustum, ContainmentType& result) const
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
		ContainmentType BoundingBox::Contains(BoundingSphere boundingSphere) const
		{
			ContainmentType result;
			Contains(boundingSphere, result);
			return result;
		}
		void BoundingBox::Contains(BoundingSphere boundingSphere, ContainmentType& result) const
		{
			Vector3 p;
			Vector3::Clamp(boundingSphere.Center, Min, Max, p);
			float d;
			Vector3::DistanceSquared(p, boundingSphere.Center, d);

			if (d > boundingSphere.Radius * boundingSphere.Radius)
			{
				result = ContainmentType::Disjoint;
				return;
			}
			else if (boundingSphere.Center.X + boundingSphere.Radius <= Max.X && boundingSphere.Center.X - boundingSphere.Radius >= Min.X &&
				boundingSphere.Center.Y + boundingSphere.Radius <= Max.Y && boundingSphere.Center.Y - boundingSphere.Radius >= Min.Y &&
				boundingSphere.Center.Z + boundingSphere.Radius <= Max.Z && boundingSphere.Center.Z - boundingSphere.Radius >= Min.Z)
			{
				result = ContainmentType::Contains;
				return;
			}

			result = ContainmentType::Intersects;
		}
		ContainmentType BoundingBox::Contains(Vector3 point) const
		{
			ContainmentType result;
			Contains(point, result);
			return result;
		}
		void BoundingBox::Contains(Vector3 point, ContainmentType& result) const
		{
			if (point.X > Max.X || point.Y > Max.Y || point.Z > Max.Z
				|| point.X < Min.X || point.Y < Min.Y || point.Z < Min.Z)
				result = ContainmentType::Disjoint;
			else
				result = ContainmentType::Contains;
		}

		bool BoundingBox::Intersects(BoundingBox boundingBox) const
		{
			bool result;
			Intersects(boundingBox, result);
			return result;
		}
		void BoundingBox::Intersects(BoundingBox boundingBox, bool& result) const
		{
			result = Contains(boundingBox) != ContainmentType::Disjoint;
		}
		bool BoundingBox::Intersects(BoundingFrustum boundingFrustum) const
		{
			bool result;
			Intersects(boundingFrustum, result);
			return result;
		}
		void BoundingBox::Intersects(BoundingFrustum boundingFrustum, bool& result) const
		{
			result = Contains(boundingFrustum) != ContainmentType::Disjoint;
		}
		bool BoundingBox::Intersects(BoundingSphere boundingSphere) const
		{
			bool result;
			Intersects(boundingSphere, result);
			return result;
		}
		void BoundingBox::Intersects(BoundingSphere boundingSphere, bool& result) const
		{
			result = Contains(boundingSphere) != ContainmentType::Disjoint;
		}
		PlaneIntersectionType BoundingBox::Intersects(Plane plane) const
		{
			PlaneIntersectionType result;
			Intersects(plane, result);
			return result;
		}
		void BoundingBox::Intersects(Plane plane, PlaneIntersectionType& result) const
		{
			plane.Intersects(*this, result);
		}
		bool BoundingBox::Intersects(Ray ray, float& distance) const
		{
			bool result;
			Intersects(ray, distance, result);
			return result;
		}
		void BoundingBox::Intersects(Ray ray, float& distance, bool& result) const
		{
			result = ray.Intersects(*this, distance);
		}

		void BoundingBox::GetCorners(Vector3* corners) const
		{
			for (int i = 0; i < BoundingBox::Corners; i++)
				GetCorner(i, corners[i]);
		}
		Vector3 BoundingBox::GetCorner(int index) const
		{
			Vector3 result;
			GetCorner(index, result);
			return result;
		}
		void BoundingBox::GetCorner(int index, Vector3& result) const
		{
			switch (index)
			{
			case 0:
				result = Min;
				return;

			case 1:
				result = Min;
				result.Y += Max.Y - Min.Y;
				return;

			case 2:
				result = Max;
				result.Z -= Max.Z - Min.Z;
				return;

			case 3:
				result = Min;
				result.X += Max.X - Min.X;
				return;

			case 4:
				result = Min;
				result.Z += Max.Z - Min.Z;
				return;

			case 5:
				result = Max;
				result.X -= Max.X - Min.X;
				return;

			case 6:
				result = Max;
				return;

			case 7:
				result = Max;
				result.Y -= Max.Y - Min.Y;
				return;

			default:
				throw std::invalid_argument("Max valid index for a BoundingBox corner is 8.");
			}
		}
	}
}