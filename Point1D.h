#pragma once
#include <type_traits>

enum class Dim
{
	one, two, three
};

template <class Type>
concept Floating = std::is_floating_point_v<Type>;


template <Floating Type>
class Point1D
{
protected:
	Type _x;

public:
	using value_type = Type;

	Point1D() : _x(0) { }
	Point1D(Type x) : _x(x) { }

	Point1D& operator=(const Point1D&) = default;

	Type getX() const noexcept
	{
		return _x;
	}

	void setX(Type x) noexcept
	{
		_x = x;
	}

	static Dim getDimensional() noexcept { return Dim::one; }
};


template <class Type>
double distance(const Point1D<Type>& point_left, const Point1D<Type>& point_right)
{
	return abs(static_cast<double>(point_left.getX() - point_right.getX()));
}