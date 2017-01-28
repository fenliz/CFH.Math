#pragma once
#include <initializer_list>

namespace CFH
{
	namespace Math
	{
		struct Point2;

		struct Point3 final
		{
		public:
			int X, Y, Z;
			
			Point3();
			Point3(const Point2& point, int z);
			Point3(int x, int y, int z);
			Point3(std::initializer_list<int> list);
			~Point3();

			const Point3& operator=(const Point3& point);
			bool operator==(const Point3& point);
			bool operator!=(const Point3& point);
		};
	}
}

