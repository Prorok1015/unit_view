#include "Unit.h"
#include "SettingsUnit.h"

double angle(const Point<double>& p1, const Point<double>& p2)
{
	auto u = p1.x * p2.x + p1.y * p2.y;
	auto d1 = distance(p1);
	auto d2 = distance(p2);
	return (std::acos(u / (d1 * d2)) * 180.) / 3.14;
}

bool Unit::is_view(const Unit& u) const
{
	return this != &u && in_the_view(u);
}

bool Unit::operator==(const Unit& u) {
	return position == u.position;
}

bool Unit::in_the_view(const Unit& u) const
{
	auto vec = to_vector(position, u.position);
	auto dist = distance(vec);
	auto norm = normalize(vec);
	auto agl = angle(direction, norm);
	return agl < (SettingsUnit::rad() / 2) && dist <= SettingsUnit::dist();
}


