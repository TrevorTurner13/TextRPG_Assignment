#include "Enemy.h"

Enemy::Enemy(std::string name, std::string desc, int str, int dex, int con, int iq, int wis, int cha, int hp, int ac, int gold) :
	Character(str, dex, con, iq, wis, cha, hp, ac, gold),
	m_Name(name),
	m_Description(desc)
{}