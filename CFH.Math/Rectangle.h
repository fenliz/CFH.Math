#pragma once
#include <initializer_list>

namespace CFH
{
	namespace Math
	{
		struct Point2;

		struct Rectangle final
		{
		public:
			int X, Y, Width, Height;

			Rectangle();
			Rectangle(int x, int y, int width, int height);
			Rectangle(std::initializer_list<int> list);
			~Rectangle();

			const Rectangle& operator=(const Rectangle& rectangle);
			bool operator==(const Rectangle& rectangle);
			bool operator!=(const Rectangle& rectangle);

			int GetTop() const;
			void GetTop(int& result) const;
			int GetBottom() const;
			void GetBottom(int& result) const;
			int GetLeft() const;
			void GetLeft(int& result) const;
			int GetRight() const;
			void GetRight(int& result) const;

			Point2 GetCenter() const;
			void GetCenter(Point2& result) const;
			Point2 GetLocation() const;
			void GetLocation(Point2& result) const;
			
			bool Contains(int x, int y) const;
			void Contains(int x, int y, bool& result) const;
			bool Contains(const Point2& point) const;
			void Contains(const Point2& point, bool& result) const;
			bool Contains(const Rectangle& rectangle) const;
			void Contains(const Rectangle& rectangle, bool& result) const;

			bool Intersects(const Rectangle& rectangle) const;
			void Intersects(const Rectangle& rectangle, bool& result) const;

			void Inflate(int horizontal, int vertical);

			void Offset(int x, int y);
			void Offset(const Point2& point);
		};
	}
}

