#pragma once
#include "Point2D.h"

template <Floating Type>
class Point3D : public Point2D<Type>
{
protected:
	Type _z;

public:

	Point3D() : Point2D<Type>(), _z(0) { }
	Point3D(Type x, Type y, Type z) : Point2D<Type>(x, y), _z(z) { }

	Point3D& operator=(const Point3D&) = default;

	Type getZ() const noexcept
	{
		return _z;
	}

	void setZ(Type z) noexcept
	{
		_z = z;
	}

	static Dim getDimensional() noexcept { return Dim::three; }
};


template <class Type>
double distance(const Point3D<Type>& point_left, const Point3D<Type>& point_right)
{
	return pow(pow(static_cast<double>(point_left.getX() - point_right.getX()), 2) + pow(static_cast<double>(point_left.getY() - point_right.getY()), 2) + pow(static_cast<double>(point_left.getZ() - point_right.getZ()), 2), 0.5);
}