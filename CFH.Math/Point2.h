#pragma once
#include <initializer_list>

namespace CFH
{
	namespace Math
	{
		struct Point2 final
		{
		public:
			int X, Y;

			Point2();
			Point2(int x, int y);
			Point2(std::initializer_list<int> list);
			~Point2();

			const Point2& operator=(const Point2& point);
			bool operator==(const Point2& point);
			bool operator!=(const Point2& point);
		};
	}
}

