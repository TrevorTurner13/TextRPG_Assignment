#pragma once

#include <iostream>
#include <string>

struct modifiers {
	int strMod;
	int dexMod;
	int conMod;
	int intMod;
	int wisMod;
	int chaMod;
	int hpMaxMod;

	int attackMod;
	int speedMod;
	int defenseMod;
	int manaMod;
	int specialAtkMod;
	int diplomacyMod;
};

class Item {
	std::string m_Name;
	std::string m_Description;
	std::string m_Rarity;
	int damage;
	int defense;
};