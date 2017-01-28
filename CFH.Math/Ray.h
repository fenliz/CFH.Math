#pragma once
#include "Common.h"
#include "Vector3.h"

namespace CFH
{
	namespace Math
	{
		struct BoundingBox;
		struct BoundingSphere;
		struct BoundingFrustum;
		struct Plane;

		struct DLL_API Ray final
		{
		public:
			Vector3 Position;
			Vector3 Direction;

			Ray();
			Ray(const Vector3& position, const Vector3&  direction);
			~Ray();

			bool operator==(const Ray& ray) const;
			bool operator!=(const Ray& ray) const;

			bool Intersects(const BoundingBox& boundingBox) const;
			bool Intersects(const BoundingBox& boundingBox, float& distance) const;
			bool Intersects(const BoundingBox& boundingBox, Vector3& point) const;
			bool Intersects(const BoundingFrustum& boundingFrustum) const;
			bool Intersects(const BoundingFrustum& boundingFrustum, float& distance) const;
			bool Intersects(const BoundingFrustum& boundingFrustum, Vector3& point) const;
			bool Intersects(const BoundingSphere& boundingSphere) const;
			bool Intersects(const BoundingSphere& boundingSphere, float& distance) const;
			bool Intersects(const BoundingSphere& boundingSphere, Vector3& point) const;
			bool Intersects(const Plane& plane) const;
			bool Intersects(const Plane& plane, float& distance) const;
			bool Intersects(const Plane& plane, Vector3& point) const;
		};
	}
}

