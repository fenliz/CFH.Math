#include "Ray.h"
#include "Plane.h"
#include "BoundingBox.h"
#include "BoundingSphere.h"
#include "BoundingFrustum.h"
#include "MathHelper.h"

#include <limits>

namespace CFH
{
	Ray::Ray() :
		Position(Vector3::Zero),
		Direction(Vector3::Zero)
	{
	}
	Ray::Ray(Vector3 position, Vector3 direction) :
		Position(position),
		Direction(direction)
	{
	}
	Ray::~Ray()
	{
	}

	bool Ray::operator==(Ray ray) const
	{
		return Position == ray.Position && Direction == ray.Direction;
	}
	bool Ray::operator!=(Ray ray) const
	{
		return Position != ray.Position || Direction != ray.Direction;
	}

	bool Ray::Intersects(BoundingBox boundingBox) const
	{
		float distance;
		return Intersects(boundingBox, distance);
	}
	bool Ray::Intersects(BoundingBox boundingBox, float& distance) const
	{
		Vector3 invDir(1.0f / Direction.X, 1.0f / Direction.Y, 1.0f / Direction.Z);

		float t1 = (boundingBox.Min.X - Position.X) * invDir.X;
		float t2 = (boundingBox.Max.X - Position.X) * invDir.X;
		float t3 = (boundingBox.Min.Y - Position.Y) * invDir.Y;
		float t4 = (boundingBox.Max.Y - Position.Y) * invDir.Y;
		float t5 = (boundingBox.Min.Z - Position.Z) * invDir.Z;
		float t6 = (boundingBox.Max.Z - Position.Z) * invDir.Z;

		float tmin = MathHelper::Max(MathHelper::Max(MathHelper::Min(t1, t2), MathHelper::Min(t3, t4)), MathHelper::Min(t5, t6));
		float tmax = MathHelper::Min(MathHelper::Min(MathHelper::Max(t1, t2), MathHelper::Max(t3, t4)), MathHelper::Max(t5, t6));

		if (tmax < 0)
		{
			distance = tmax;
			return false;
		}

		if (tmin > tmax)
		{
			distance = tmax;
			return false;
		}

		distance = tmin;
		return true;
	}
	bool Ray::Intersects(BoundingFrustum boundingFrustum) const
	{
		float distance;
		return Intersects(boundingFrustum, distance);
	}
	bool Ray::Intersects(BoundingFrustum boundingFrustum, float& distance) const
	{
		ContainmentType c;
		boundingFrustum.Contains(Position, c);
		if (c != ContainmentType::Disjoint)
		{
			distance = 0;
			return true;
		}

		Vector3 v;
		float max = std::numeric_limits<float>::max();
		Vector3 end = Vector3((float)(Direction.X * max * 1e-5), (float)(Direction.Y * max * 1e-5), (float)(Direction.Z * max * 1e-5));
		Plane plane;
		float dist, aMax, aMin, bMax, bMin;
		for (char i = 0, k = 0; i < BoundingFrustum::Planes; i++)
		{
			aMin = bMin = max;
			aMax = bMax = -max;
			boundingFrustum.GetPlane(i, plane);

			for (k = 0; k < BoundingFrustum::Corners; k++)
			{
				boundingFrustum.GetCorner(k, v);
				plane.Distance(v, dist);
				MathHelper::Min(dist, aMin, aMin);
				MathHelper::Max(dist, aMax, aMax);
			}

			plane.Distance(Position, dist);
			MathHelper::Min(dist, bMin, bMin);
			MathHelper::Max(dist, bMax, bMax);
			plane.Distance(end, dist);
			MathHelper::Min(dist, bMin, bMin);
			MathHelper::Max(dist, bMax, bMax);

			if (aMin > bMax || aMax < bMin)
			{
				distance = 0;
				return false;
			}
		}
		return true;
	}
	bool Ray::Intersects(BoundingSphere boundingSphere) const
	{
		float distance;
		return Intersects(boundingSphere, distance);
	}
	bool Ray::Intersects(BoundingSphere boundingSphere, float& distance) const
	{
		Vector3 diff;
		Vector3::Subtract(boundingSphere.Center, Position, diff);
		float diffLengthSquared;
		diff.LengthSquared(diffLengthSquared);
		float r2 = boundingSphere.Radius * boundingSphere.Radius;

		if (diffLengthSquared < r2)
		{
			distance = 0;
			return true;
		}

		Vector3::Dot(Direction, diff, distance);
		if (distance < 0)
		{
			distance = 0;
			return false;
		}

		float u2 = (diffLengthSquared - distance * distance);
		if (u2 < r2)
		{
			distance = distance - MathHelper::Sqrt(r2 - u2);
			return true;
		}

		distance = 0;
		return false;
	}
	bool Ray::Intersects(Plane plane) const
	{
		float distance;
		return Intersects(plane, distance);
	}
	bool Ray::Intersects(Plane plane, float& distance) const
	{
		float dot;
		Vector3::Dot(Direction, plane.Normal, dot);
		if (abs(dot) < 1e-5)
		{
			distance = 0;
			return false;
		}

		distance = (-plane.D - Vector3::Dot(plane.Normal, Position) / dot);

		if (distance <  0)
		{
			distance = 0;
			if (distance < -1e-5)
				return false;
			else
				return true;
		}

		return false;
	}
}