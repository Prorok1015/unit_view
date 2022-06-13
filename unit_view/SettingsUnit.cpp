#include "SettingsUnit.h"

SettingsUnit& SettingsUnit::instance()
{
	static SettingsUnit inst{ 135.5, 2 };
	return inst;
}