#include "Plane.h"
#include "Vector4.h"
#include "Matrix4.h"
#include "BoundingBox.h"
#include "BoundingSphere.h"
#include "BoundingFrustum.h"

namespace CFH
{
	namespace Math
	{
		Plane::Plane() :
			Normal(Vector3::Zero),
			D(0)
		{
		}
		Plane::Plane(float a, float b, float c, float d) :
			Normal(Vector3(a, b, c)),
			D(d)
		{
		}
		Plane::Plane(Vector3 normal, float d) :
			Normal(normal),
			D(d)
		{
		}
		Plane::Plane(Vector3 p1, Vector3 p2, Vector3 p3)
		{
			CreateFromPoints(p1, p2, p3, *this);
		}
		Plane::Plane(Vector4 value) :
			Normal(Vector3(value.X, value.Y, value.Z)),
			D(value.W)
		{
		}
		Plane::~Plane()
		{
		}

		Plane Plane::operator=(Plane plane)
		{
			Normal = plane.Normal;
			D = plane.D;
			return *this;
		}

		Plane Plane::CreateFromPoints(Vector3 point1, Vector3 point2, Vector3 point3)
		{
			Plane result;
			CreateFromPoints(point1, point2, point3, result);
			return result;
		}
		void Plane::CreateFromPoints(Vector3 point1, Vector3 point2, Vector3 point3, Plane& result)
		{
			Vector3 a, b;
			Vector3::Subtract(point2, point1, a);
			Vector3::Subtract(point3, point1, b);
			Vector3::Cross(a, b, result.Normal);
			result.Normal.Normalize();

			Vector3::Dot(result.Normal, point1, result.D);
			result.D = -result.D;
		}

		float Plane::Dot(Vector4 vector) const
		{
			float result;
			Dot(vector, result);
			return result;
		}
		void Plane::Dot(Vector4 vector, float& result) const
		{
			result = (Normal.X * vector.X) + (Normal.Y * vector.Y) +
				(Normal.Z * vector.Z) + (D * vector.W);
		}
		float Plane::DotCoordinate(Vector3 vector) const
		{
			float result;
			DotCoordinate(vector, result);
			return result;
		}
		void Plane::DotCoordinate(Vector3 vector, float& result) const
		{
			result = (Normal.X * vector.X) + (Normal.Y * vector.Y) +
				(Normal.Z * vector.Z) + D;
		}
		float Plane::DotNormal(Vector3 vector) const
		{
			float result;
			DotNormal(vector, result);
			return result;
		}
		void Plane::DotNormal(Vector3 vector, float& result) const
		{
			result = (Normal.X * vector.X) + (Normal.Y * vector.Y) +
				(Normal.Z * vector.Z);
		}

		void Plane::Normalize()
		{
			Normalize(*this, *this);
		}
		Plane Plane::Normalize(Plane plane)
		{
			Plane result;
			Normalize(plane, result);
			return result;
		}
		void Plane::Normalize(Plane plane, Plane& result)
		{
			float length = plane.Normal.Length();
			Vector3::Normalize(plane.Normal, result.Normal);
			result.D = plane.D / length;
		}

		float Plane::Distance(Vector3 point) const
		{
			float result;
			Distance(point, result);
			return result;
		}
		void Plane::Distance(Vector3 point, float& result) const
		{
			Vector3 v;
			GetLocation(v);
			Vector3::Subtract(point, v, v);
			Vector3::Dot(Normal, v, result);
		}
		Vector3 Plane::DistanceVector(Vector3 point) const
		{
			Vector3 result;
			DistanceVector(point, result);
			return result;
		}
		void Plane::DistanceVector(Vector3 point, Vector3& result) const
		{
			GetLocation(result);
			Vector3::Subtract(point, result, result);
			float lengthSquared;
			Normal.LengthSquared(lengthSquared);
			if (lengthSquared == 0)
			{
				result == Vector3::Zero;
				return;
			}

			Vector3::Multiply(Normal, Vector3::Dot(result, Normal) / lengthSquared, result);
		}

		Vector3 Plane::GetLocation() const
		{
			Vector3 result;
			GetLocation(result);
			return result;
		}
		void Plane::GetLocation(Vector3& result) const
		{
			result = Normal * -D;
		}

		Vector3 Plane::Project(Vector3 point, Plane plane)
		{
			Vector3 result;
			Project(point, plane, result);
			return result;
		}
		void Plane::Project(Vector3 point, Plane plane, Vector3& result)
		{
			Vector3 temp = point - plane.GetLocation();
			float f = temp.X * plane.Normal.X + temp.Y * plane.Normal.Y +
				temp.Z * plane.Normal.Z;
			result = temp - plane.Normal * f;
		}

		PlaneIntersectionType Plane::Intersects(Vector3 point) const
		{
			PlaneIntersectionType result;
			Intersects(point, result);
			return result;
		}
		void Plane::Intersects(Vector3 point, PlaneIntersectionType& result) const
		{
			float distance;
			Intersects(point, distance, result);
		}
		PlaneIntersectionType Plane::Intersects(Vector3 point, float& distance) const
		{
			PlaneIntersectionType result;
			Intersects(point, distance, result);
			return result;
		}
		void Plane::Intersects(Vector3 point, float& distance, PlaneIntersectionType& result) const
		{
			Distance(point, distance);
			if (distance > 1e-9)
				result = PlaneIntersectionType::Front;
			else if (distance < -1e-9)
				result = PlaneIntersectionType::Back;
			else
				result = PlaneIntersectionType::Intersecting;
		}
		PlaneIntersectionType Plane::Intersects(BoundingBox boundingBox) const
		{
			PlaneIntersectionType result;
			Intersects(boundingBox, result);
			return result;
		}
		void Plane::Intersects(BoundingBox boundingBox, PlaneIntersectionType& result) const
		{
			Vector3 a, b;
			if (Normal.X >= 0)
			{
				b.X = boundingBox.Max.X;
				a.X = boundingBox.Min.X;
			}
			else
			{
				b.X = boundingBox.Min.X;
				a.X = boundingBox.Max.X;
			}

			if (Normal.Y >= 0)
			{
				b.Y = boundingBox.Max.Y;
				a.Y = boundingBox.Min.Y;
			}
			else
			{
				b.Y = boundingBox.Min.Y;
				a.Y = boundingBox.Max.Y;
			}

			if (Normal.Z >= 0)
			{
				b.Z = boundingBox.Max.Z;
				a.Z = boundingBox.Min.Z;
			}
			else
			{
				b.Z = boundingBox.Min.Z;
				a.Z = boundingBox.Max.Z;
			}

			float dist;
			PlaneIntersectionType p;
			Intersects(a, dist, result);
			Intersects(b, dist, p);
			if (result != p)
				result = PlaneIntersectionType::Intersecting;
		}
		PlaneIntersectionType Plane::Intersects(BoundingFrustum boundingFrustum) const
		{
			PlaneIntersectionType result;
			Intersects(boundingFrustum, result);
			return result;
		}
		void Plane::Intersects(BoundingFrustum boundingFrustum, PlaneIntersectionType& result) const
		{
			Vector3 v;
			float d;
			char back = 0, front = 0;
			Vector3 location;
			GetLocation(location);

			for (char i = 0; i < 8; i++)
			{
				boundingFrustum.GetCorner(i, v);
				Vector3::Subtract(v, location, v);
				Distance(v, d);
				if (d > 0)
					back++;
				else if (d < 0)
					front++;
				else
				{
					result = PlaneIntersectionType::Intersecting;
					return;
				}

				if (back > 0 && front > 0)
				{
					result = PlaneIntersectionType::Intersecting;
					return;
				}
			}

			if (front == 8)
				result = PlaneIntersectionType::Front;
			else
				result = PlaneIntersectionType::Back;
		}
		PlaneIntersectionType Plane::Intersects(BoundingSphere boundingSphere) const
		{
			PlaneIntersectionType result;
			Intersects(boundingSphere, result);
			return result;
		}
		void Plane::Intersects(BoundingSphere boundingSphere, PlaneIntersectionType& result) const
		{
			float d;
			Intersects(boundingSphere.Center, d, result);
			if (d < boundingSphere.Radius)
				result = PlaneIntersectionType::Intersecting;
		}
	}
}
