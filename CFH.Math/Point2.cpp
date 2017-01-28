#include "Point2.h"

namespace CFH
{
	namespace Math
	{
		Point2::Point2() :
			X(0), Y(0)
		{
		}
		Point2::Point2(int x, int y) :
			X(x), Y(y)
		{
		}
		Point2::Point2(std::initializer_list<int> list)
		{
			auto it = list.begin();
			X = *(it++);
			Y = *(it++);
		}
		Point2::~Point2()
		{
		}

		const Point2& Point2::operator=(const Point2& point)
		{
			this->X = point.X;
			this->Y = point.Y;
			return *this;
		}
		bool Point2::operator==(const Point2& point)
		{
			return this->X == point.X &&
				this->Y == point.Y;
		}
		bool Point2::operator!=(const Point2& point)
		{
			return this->X != point.X ||
				this->Y != point.Y;
		}
	}
}

