#pragma once
#include "Common.h"
#include "Plane.h"
#include "Matrix4.h"

namespace CFH
{
	namespace Math
	{
		enum class ContainmentType;
		enum class PlaneIntersectionType;
		struct BoundingBox;
		struct BoundingSphere;
		struct Ray;

		struct DLL_API BoundingFrustum final
		{
		private:
			Matrix4 inverseViewProjection_;
			Matrix4 viewProjection_;
			Plane planes_[6];
			Vector3 corners_[6];

			void CalculateCorner(int index, Vector3& result) const;

		public:
			static const int Corners = 8;
			static const int Planes = 6;

			BoundingFrustum();
			BoundingFrustum(const Matrix4& value);
			~BoundingFrustum();

			bool operator==(const BoundingFrustum& boundingFrustum) const;
			bool operator!=(const BoundingFrustum& boundingFrustum) const;
			const BoundingFrustum& operator=(const BoundingFrustum& boundingFrustum);

			void SetViewProjection(const Matrix4& matrix);
			const Matrix4& GetViewProjection() const;
			void GetViewProjection(Matrix4& result) const;
			const Matrix4& GetInverseViewProjection() const;
			void GetInverseViewProjection(Matrix4& result) const;

			const Plane& GetTop() const;
			void GetTop(Plane& result) const;
			const Plane& GetBottom() const;
			void GetBottom(Plane& result) const;
			const Plane& GetFar() const;
			void GetFar(Plane& result) const;
			const Plane& GetNear() const;
			void GetNear(Plane& result) const;
			const Plane& GetRight() const;
			void GetRight(Plane& result) const;
			const Plane& GetLeft() const;
			void GetLeft(Plane& result) const;
			void GetCorners(Vector3* corners, int size) const;
			const Vector3& GetCorner(int index) const;
			void GetCorner(int index, Vector3& result) const;
			const Plane& GetPlane(int index) const;
			void GetPlane(int index, Plane& result) const;

			ContainmentType Contains(const Vector3& point) const;
			void Contains(const Vector3& point, ContainmentType& result) const;
			ContainmentType Contains(const BoundingBox& boundingBox) const;
			void Contains(const BoundingBox& boundingBox, ContainmentType& result) const;
			ContainmentType Contains(const BoundingFrustum& boundingFrustum) const;
			void Contains(const BoundingFrustum& boundingFrustum, ContainmentType& result) const;
			ContainmentType Contains(const BoundingSphere& boundingSphere) const;
			void Contains(const BoundingSphere& boundingSphere, ContainmentType& result) const;

			bool Intersects(const BoundingBox& box) const;
			void Intersects(const BoundingBox& box, bool& result) const;
			bool Intersects(const BoundingFrustum& frustum) const;
			void Intersects(const BoundingFrustum& frustum, bool& result) const;
			bool Intersects(const BoundingSphere& sphere) const;
			void Intersects(const BoundingSphere& sphere, bool& result) const;
			PlaneIntersectionType Intersects(const Plane& plane) const;
			void Intersects(const Plane& plane, PlaneIntersectionType& result) const;
			bool Intersects(const Ray& ray, float& distance) const;
			void Intersects(const Ray& ray, float& distance, bool& result) const;
		};
	}
}

