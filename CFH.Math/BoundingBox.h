#pragma once
#include "Common.h"
#include "Vector3.h"

namespace CFH
{
	namespace Math
	{
		struct BoundingFrustum;
		struct BoundingSphere;
		struct Ray;
		struct Plane;
		enum class PlaneIntersectionType;

		enum class DLL_API ContainmentType
		{
			Disjoint,
			Contains,
			Intersects
		};

		struct DLL_API BoundingBox final
		{
		public:
			static const int Corners = 8;
			static const int Planes = 6;
			Vector3 Min, Max;

			BoundingBox();
			BoundingBox(Vector3 min, Vector3 max);
			~BoundingBox();

			bool operator==(const BoundingBox& boundingBox);
			bool operator!=(const BoundingBox& boundingBox);
			const BoundingBox& operator=(const BoundingBox& boundingBox);

			static BoundingBox CreateFromPoints(const Vector3 points[], int count);
			static void CreateFromPoints(const Vector3 points[], int count, BoundingBox& result);
			static BoundingBox CreateFromSphere(const BoundingSphere& boundingSphere);
			static void CreateFromSphere(const BoundingSphere& boundingSphere, BoundingBox& result);
			static BoundingBox CreateMerged(const BoundingBox& boundingBox, const BoundingBox& boundingBox2);
			static void CreateMerged(const BoundingBox& boundingBox, const BoundingBox& boundingBox2, BoundingBox& result);

			ContainmentType Contains(const Vector3& point) const;
			void Contains(const Vector3& point, ContainmentType& result) const;
			ContainmentType Contains(const BoundingBox& boundingBox) const;
			void Contains(const BoundingBox& boundingBox, ContainmentType& result) const;
			ContainmentType Contains(const BoundingFrustum& boundingFrustum) const;
			void Contains(const BoundingFrustum& boundingFrustum, ContainmentType& result) const;
			ContainmentType Contains(const BoundingSphere& boundingSphere) const;
			void Contains(const BoundingSphere& boundingSphere, ContainmentType& result) const;

			bool Intersects(const BoundingBox& boundingBox) const;
			void Intersects(const BoundingBox& boundingBox, bool& result) const;
			bool Intersects(const BoundingFrustum& boundingFrustum) const;
			void Intersects(const BoundingFrustum& boundingFrustum, bool& result) const;
			bool Intersects(const BoundingSphere& boundingSphere) const;
			void Intersects(const BoundingSphere& boundingSphere, bool& result) const;
			PlaneIntersectionType Intersects(const Plane& plane) const;
			void Intersects(const Plane& plane, PlaneIntersectionType& result) const;
			bool Intersects(const Ray& ray, float& distance) const;
			void Intersects(const Ray& ray, float& distance, bool& result) const;

			void GetCorners(Vector3* corners) const;
			Vector3 GetCorner(int index) const;
			void GetCorner(int index, Vector3& result) const;
		};
	}
}