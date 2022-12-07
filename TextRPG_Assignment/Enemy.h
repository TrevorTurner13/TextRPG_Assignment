#pragma once

#include "CharacterCreator.h"

class Enemy: public Character {
public:
	Enemy(std::string name, std::string desc, int str, int dex, int con, int iq, int wis, int cha, int hp, int ac, int gold, int exp, int level);
private:
	std::string m_Description;
	std::string m_Name;
};

