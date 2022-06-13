#pragma once
#include <cmath>

template<typename T>
struct Point
{
	T x, y;
};

template<typename T> Point<double> operator * (const Point<T>& p1, double n)
{
	return { p1.x * n, p1.y * n };
}

template<typename T>
Point<double> normalize(const Point<T>& p)
{
	double inv_length = 1.0 / std::sqrt(p.x * p.x + p.y * p.y);
	return  p * inv_length;
}

template<typename T>
Point<T> to_vector(const Point<T>& start, const Point<T>& end)
{
	return { end.x - start.x, end.y - start.y };
}

template<typename T>
double distance(const Point<T>& p)
{
	return std::sqrt(p.x * p.x + p.y * p.y);
}

template<typename T>
bool operator== (const Point<T>& p1, const Point<T> p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}