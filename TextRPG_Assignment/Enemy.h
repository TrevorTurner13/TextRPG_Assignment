#pragma once

#include <iostream>
#include <string>
#include "CharacterCreator.h"

class Enemy: public Character {
public:
	Enemy(std::string name, std::string desc, int str, int dex, int con, int iq, int wis, int cha, int hp, int ac);

};

