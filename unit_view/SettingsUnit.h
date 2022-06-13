#pragma once

class SettingsUnit
{
	double radius;
	size_t distance;
public:
	static SettingsUnit& instance();
	static double rad() {
		return instance().radius;
	}
	static size_t dist() {
		return instance().distance;
	}
private:
	SettingsUnit(double r, size_t d) :radius(r), distance(d) {};
};