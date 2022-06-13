#pragma once
#include "Point.h"

struct Unit
{
	Point<int> position;
	Point<double> direction;
	bool is_view(const Unit& u) const;
	bool operator == (const Unit& u);
private:
	bool in_the_view(const Unit& u) const;
};

