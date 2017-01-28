#pragma once
#include "Common.h"
#include "Vector3.h"

namespace CFH
{
	namespace Math
	{
		enum class ContainmentType;
		enum class PlaneIntersectionType;
		struct BoundingBox;
		struct BoundingFrustum;
		struct Plane;
		struct Ray;
		struct Matrix4;

		struct DLL_API BoundingSphere final
		{
		public:
			Vector3 Center;
			float Radius;

			BoundingSphere();
			BoundingSphere(const Vector3& center, float radius);
			~BoundingSphere();

			bool operator==(const BoundingSphere& boundingSphere) const;
			bool operator!=(const BoundingSphere& boundingSphere) const;
			const BoundingSphere& operator=(const BoundingSphere& boundingSphere);

			static BoundingSphere CreateFromBoundingBox(const BoundingBox& boundingBox);
			static void CreateFromBoundingBox(const BoundingBox& boundingBox, BoundingSphere& result);
			static BoundingSphere CreateFromFrustum(const BoundingFrustum& boundingFrustum);
			static void CreateFromFrustum(const BoundingFrustum& boundingFrustum, BoundingSphere& result);
			static BoundingSphere CreateFromPoints(const Vector3 points[], int count);
			static void CreateFromPoints(const Vector3 points[], int count, BoundingSphere& result);
			static BoundingSphere CreateMerged(const BoundingSphere& boundingSphere, const BoundingSphere& boundingSphere2);
			static void CreateMerged(const BoundingSphere& boundingSphere, const BoundingSphere& boundingSphere2, BoundingSphere& result);

			ContainmentType Contains(const Vector3& point) const;
			void Contains(const Vector3& point, ContainmentType& result) const;
			ContainmentType Contains(const BoundingBox& boundingBox) const;
			void Contains(const BoundingBox& boundingBox, ContainmentType& result) const;
			ContainmentType Contains(const BoundingFrustum& boundingFrustum) const;
			void Contains(const BoundingFrustum& boundingFrustum, ContainmentType& result) const;
			ContainmentType Contains(const BoundingSphere& boundingSphere) const;
			void Contains(const BoundingSphere& boundingSphere, ContainmentType& result) const;

			bool Intersects(const BoundingBox& boundingBox) const;
			bool Intersects(const BoundingFrustum& boundingFrustum) const;
			bool Intersects(const BoundingSphere& boundingSphere) const;
			PlaneIntersectionType Intersects(const Plane& plane) const;
			void Intersects(const Plane& plane, PlaneIntersectionType& result) const;
			bool Intersects(const Ray& ray, float& distance) const;

			BoundingSphere Transform(const Matrix4& matrix);
			void Transform(Matrix4 matrix, BoundingSphere& result);
		};
	}
}


