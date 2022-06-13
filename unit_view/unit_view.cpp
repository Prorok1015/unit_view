#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <random>

#include "Point.h"
#include "Unit.h"
#include "SettingsUnit.h"

struct hasher
{
	size_t operator() (const Unit& u) const
	{
		return size_t(u.position.x + u.position.y);
	}
};

bool operator == (const Unit& u1, const Unit& u2)
{
	return u1.position == u2.position;
}

std::ostream& operator<<(std::ostream& os, const Unit& c)
{
	os << "position (" << c.position.x << ", " << c.position.y << "), direction (" << c.direction.x << ", " << c.direction.y << ")";
	return os;
}

std::unordered_set<Unit, hasher> generate(size_t count = 10)
{
	std::unordered_set<Unit, hasher> result;

	size_t num = 0;
	while (num++ < count) {
		Point<int> pos{ int(rand() % (count/2)), int(rand() % (count/2)) };
		Point<double> dir = normalize(pos);
		result.insert({ pos, dir });
	}
	return result;
}

int main()
{
/*std::vector<Unit> units = {{{1,1}, {0.,1.}} ,
								{{1,2}, {1.,0.}},
								{{-5,-1}, {0.707,0.707}},
								{{3,2}, {-0.707,-0.3}}, 
								{{-5,0}, {-0.707,-0.3}},
								{{-6,-1}, {-0.5,0.5}}, 
								{{-6,-2}, {0.707,0.707}}, 
								{{-4,-2}, {0.3,-0.707}}, };

*/

	auto units = generate(1000);
	std::unordered_map<Unit, size_t, hasher> seeses;
	std::cout << "Sector " << SettingsUnit::rad() << " grad, Distance " << SettingsUnit::dist() << " u.e." << std::endl;
	size_t i = 0;
	for (auto& u : units) {
		std::cout << "Unit "<< ++i << ": " << u << std::endl;
	}

	for (const auto& center : units)
	{
		for (const auto& unit : units)
			if (center.is_view(unit))
				++seeses[center];
	}

	i = 0;
	for (auto& u : units) {
		std::cout << "Unit " << ++i << ": sees " << seeses[u] << std::endl;
	}

	std::system("pause");
}