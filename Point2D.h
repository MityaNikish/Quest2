#pragma once
#include "Point1D.h"

template <Floating Type>
class Point2D : public Point1D<Type>
{
protected:
	Type _y;

public:

	Point2D() : Point1D<Type>(), _y(0) { }
	Point2D(Type x, Type y) : Point1D<Type>(x), _y(y) { }

	Point2D& operator=(const Point2D&) = default;

	Type getY() const noexcept
	{
		return _y;
	}

	void setY(Type y) noexcept
	{
		_y = y;
	}

	static Dim getDimensional() noexcept { return Dim::two; }
};


template <class Type>
double distance(const Point2D<Type>& point_left, const Point2D<Type>& point_right)
{
	return pow(pow(static_cast<double>(point_left.getX() - point_right.getX()), 2) + pow(static_cast<double>(point_left.getY() - point_right.getY()), 2), 0.5);
}