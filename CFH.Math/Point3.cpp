#include "Point3.h"
#include "Point2.h"

namespace CFH
{
	namespace Math
	{
		Point3::Point3() :
			X(0), Y(0), Z(0)
		{
		}
		Point3::Point3(const Point2& point, int z) :
			X(point.X), Y(point.Y), Z(z)
		{
		}
		Point3::Point3(int x, int y, int z) :
			X(x), Y(y), Z(z)
		{
		}
		Point3::Point3(std::initializer_list<int> list)
		{
			auto it = list.begin();
			X = *(it++);
			Y = *(it++);
			Z = *(it++);
		}
		Point3::~Point3()
		{
		}

		const Point3& Point3::operator=(const Point3& point)
		{
			this->X = point.X;
			this->Y = point.Y;
			this->Z = point.Z;
			return *this;
		}
		bool Point3::operator==(const Point3& point)
		{
			return this->X == point.X &&
				this->Y == point.Y &&
				this->Z == point.Z;
		}
		bool Point3::operator!=(const Point3& point)
		{
			return this->X != point.X ||
				this->Y != point.Y ||
				this->Z != point.Z;
		}
	}
}
