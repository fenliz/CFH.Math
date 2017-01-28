#pragma once
#include "Common.h"
#include "Vector3.h"

namespace CFH
{
	namespace Math
	{
		struct BoundingBox;
		struct Quaternion;
		struct BoundingFrustum;
		struct BoundingSphere;
		struct Vector4;
		struct Matrix4;

		enum class DLL_API PlaneIntersectionType
		{
			Back,
			Front,
			Intersecting
		};

		struct DLL_API Plane final
		{
		public:
			float D;
			Vector3 Normal;

			Plane();
			Plane(float a, float b, float c, float d);
			Plane(const Vector3& normal, float d);
			Plane(const Vector3& point1, const Vector3& point2, const Vector3& point3);
			Plane(const Vector4& value);
			~Plane();

			const Plane& operator=(const Plane& plane);

			static Plane CreateFromPoints(const Vector3& point1, const Vector3& point2, const Vector3& point3);
			static void CreateFromPoints(const Vector3& point1, const Vector3& point2, const Vector3& point3, Plane& result);

			float Dot(const Vector4& vector) const;
			void Dot(const Vector4& vector, float& result) const;
			float DotCoordinate(const Vector3& vector) const;
			void DotCoordinate(const Vector3& vector, float& result) const;
			float DotNormal(const Vector3& vector) const;
			void DotNormal(const Vector3& vector, float& result) const;

			void Normalize();
			static Plane Normalize(const Plane& plane);
			static void Normalize(const Plane& plane, Plane& result);

			float Distance(const Vector3& point) const;
			void Distance(const Vector3& point, float& result) const;
			Vector3 DistanceVector(const Vector3& point) const;
			void DistanceVector(const Vector3& point, Vector3& result) const;

			Vector3 GetLocation() const;
			void GetLocation(Vector3& result) const;

			static Vector3 Project(const Vector3& point, const Plane& plane);
			static void Project(const Vector3& point, const Plane& plane, Vector3& result);

			PlaneIntersectionType Intersects(const Vector3& point) const;
			void Intersects(const Vector3& point, PlaneIntersectionType& result) const;
			PlaneIntersectionType Intersects(const Vector3& point, float& distance) const;
			void Intersects(const Vector3& point, float& distance, PlaneIntersectionType& result) const;
			PlaneIntersectionType Intersects(const BoundingBox& boundingBox) const;
			void Intersects(const BoundingBox& boundingBox, PlaneIntersectionType& result) const;
			PlaneIntersectionType Intersects(const BoundingFrustum& boundingFrustum) const;
			void Intersects(const BoundingFrustum& boundingFrustum, PlaneIntersectionType& result) const;
			PlaneIntersectionType Intersects(const BoundingSphere& boundingSphere) const;
			void Intersects(const BoundingSphere& boundingSphere, PlaneIntersectionType& result) const;
		};
	}
}