#include "Rectangle.h"
#include "Point2.h"

namespace CFH
{
	namespace Math
	{
		Rectangle::Rectangle() :
			X(0), Y(0), Width(0), Height(0)
		{
		}
		Rectangle::Rectangle(int x, int y, int width, int height) :
			X(x), Y(y), Width(width), Height(height)
		{
		}
		Rectangle::Rectangle(std::initializer_list<int> list)
		{
			auto it = list.begin();
			X = *(it++);
			Y = *(it++);
			Width = *(it++);
			Height = *(it++);
		}
		Rectangle::~Rectangle()
		{
		}

		const Rectangle& Rectangle::operator=(const Rectangle& rectangle)
		{
			this->X = rectangle.X;
			this->Y = rectangle.Y;
			this->Width = rectangle.Width;
			this->Height = rectangle.Height;
			return *this;
		}
		bool Rectangle::operator==(const Rectangle& rectangle)
		{
			return this->X == rectangle.X &&
				this->Y == rectangle.Y &&
				this->Width == rectangle.Width &&
				this->Height == rectangle.Height;
		}
		bool Rectangle::operator!=(const Rectangle& rectangle)
		{
			return this->X != rectangle.X ||
				this->Y != rectangle.Y ||
				this->Width != rectangle.Width ||
				this->Height != rectangle.Height;
		}

		int Rectangle::GetTop() const
		{
			return Y;
		}
		void Rectangle::GetTop(int& result) const
		{
			result = Y;
		}
		int Rectangle::GetBottom() const
		{
			return Y + Height;
		}
		void Rectangle::GetBottom(int& result) const
		{
			result = Y + Height;
		}
		int Rectangle::GetLeft() const
		{
			return X;
		}
		void Rectangle::GetLeft(int& result) const
		{
			result = X;
		}
		int Rectangle::GetRight() const
		{
			return X + Width;
		}
		void Rectangle::GetRight(int& result) const
		{
			result = X + Width;
		}

		Point2 Rectangle::GetCenter() const
		{
			return Point2(X + (Width / 2), Y + (Height / 2));
		}
		void Rectangle::GetCenter(Point2& result) const
		{
			result.X = X + (Width / 2);
			result.Y = Y + (Height / 2);
		}
		Point2 Rectangle::GetLocation() const
		{
			return Point2(X, Y);
		}
		void Rectangle::GetLocation(Point2& result) const
		{
			result.X = X;
			result.Y = Y;
		}

		bool Rectangle::Contains(int x, int y) const
		{
			bool result;
			Contains(x, y, result);
			return result;
		}
		void Rectangle::Contains(int x, int y, bool& result) const
		{
			if (x >= GetLeft() && X <= GetRight() &&
				y >= GetTop() && y <= GetBottom())
				result = true;
			else
				result = false;
		}
		bool Rectangle::Contains(const Point2& point) const
		{
			bool result;
			Contains(point.X, point.Y, result);
			return result;
		}
		void Rectangle::Contains(const Point2& point, bool& result) const
		{
			Contains(point.X, point.Y, result);
		}
		bool Rectangle::Contains(const Rectangle& rectangle) const
		{
			bool result;
			Contains(rectangle, result);
			return result;
		}
		void Rectangle::Contains(const Rectangle& rectangle, bool& result) const
		{
			if (rectangle.GetLeft() >= GetLeft() && rectangle.GetRight() <= GetRight() &&
				rectangle.GetTop() >= GetTop() && rectangle.GetBottom() <= GetBottom())
				result = true;
			else
				result = false;
		}

		bool Rectangle::Intersects(const Rectangle& rectangle) const
		{
			bool result;
			Intersects(rectangle, result);
			return result;
		}
		void Rectangle::Intersects(const Rectangle& rectangle, bool& result) const
		{
			result = false;
			if (rectangle.GetLeft() < GetRight() || rectangle.GetRight() > GetLeft())
			{
				if (rectangle.GetTop() < GetBottom() && rectangle.GetTop() > GetTop())
					result = true;
				else if (rectangle.GetBottom() < GetBottom() && rectangle.GetBottom() > GetTop())
					result = true;
			}
		}

		void Rectangle::Inflate(int horizontal, int vertical)
		{
			X -= horizontal / 2;
			Y -= vertical / 2;
			Width += horizontal;
			Height += vertical;
		}

		void Rectangle::Offset(int x, int y)
		{
			X += x;
			Y += y;
		}
		void Rectangle::Offset(const Point2& point)
		{
			X += point.X;
			Y += point.Y;
		}
	}
}

