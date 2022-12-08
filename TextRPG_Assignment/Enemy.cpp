#include "Enemy.h"

Enemy::Enemy(std::string name, std::string desc, int str, int dex, int con, int iq, int wis, int cha, int hp, int ac, int gold, int exp, int level) :
	Character(name, str, dex, con, iq, wis, cha, hp, ac, gold, exp, level),
	m_Description(desc)
{}

void Enemy::SetEnemyDescription(std::string desc) {
	m_Description = desc;
}
