#pragma once
#include <string>

enum characterAncestry { DWARF = 1, DRAGONBORN, ELF, GNOME, HALFING, HUMAN, ORC };
enum characterClass { BARD = 1, FIGHTER, MONK, ROGUE, PALADIN, WIZARD };

class Character {
public:
	std::string characterName;

	characterAncestry m_Ancestry;
	characterClass m_WarriorClass;
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;

	int strModifier;
	int dexModifier;
	int conModifier;
	int intModifier;
	int wisModifier;
	int chaModifier;

	int attack;
	int speed;
	int defense;
	int mana;
	int specialAtk;
	int diplomacy;
	int maxHp;
	int level;
	
};