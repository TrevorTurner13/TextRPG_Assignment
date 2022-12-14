#include "Enemy.h"

Enemy::Enemy(std::string name, std::string desc, int str, int dex, int con, int iq, int wis, int cha, int hp, int ac, int gold, int exp, int level, int toHitBonus, int damage, bool enemyDead) :
	Character(name, str, dex, con, iq, wis, cha, hp, ac, gold, exp, level),
	m_Description(desc),
	m_ToHitBonus(toHitBonus),
	m_Damage(damage),
	m_EnemyDead(enemyDead)
{}

void Enemy::SetEnemyDescription(std::string desc) {
	m_Description = desc;
}

void Enemy::SetEnemyToHitBonus(int toHitBonus) {
	m_ToHitBonus = toHitBonus;
}

void Enemy::SetEnemyDamage(int damage) {
	m_Damage = damage;
}
void Enemy::SetEnemyDead(bool enemyDead) {
	m_EnemyDead = enemyDead;
}

EnemyStrong::EnemyStrong(std::string name, std::string desc, int str, int dex, int con, int iq, int wis, int cha, int hp, int ac, int gold, int exp, int level, int toHitBonus, int damage1, int damage2, bool enemyDead) :
	Enemy(name, desc, str, dex, con, iq, wis, cha, hp, ac, gold, exp, level, toHitBonus, damage1, enemyDead),
	/*m_Description(desc),
	m_ToHitBonus(toHitBonus),
	m_Damage1(damage1),*/
	m_Damage2(damage2)
	/*m_EnemyDead(enemyDead)*/
{}

//void EnemyStrong::SetEnemyDescription(std::string desc) {
//	m_Description = desc;
//}
//
//void EnemyStrong::SetEnemyToHitBonus(int toHitBonus) {
//	m_ToHitBonus = toHitBonus;
//}
//
//void EnemyStrong::SetEnemyDamage1(int damage1) {
//	m_Damage1 = damage1;
//}
void EnemyStrong::SetEnemyDamage2(int damage2) {
	m_Damage2 = damage2;
}
//void EnemyStrong::SetEnemyDead(bool enemyDead) {
//	m_EnemyDead = enemyDead;
//}

Boss::Boss(std::string name, std::string desc, int str, int dex, int con, int iq, int wis, int cha, int hp, int ac, int gold, int exp, int level, int toHitBonus, int damage1, int damage2, int damage3, bool enemyDead) :
	EnemyStrong(name, desc, str, dex, con, iq, wis, cha, hp, ac, gold, exp, level, toHitBonus, damage1, damage2, enemyDead),
	/*m_Description(desc),
	m_ToHitBonus(toHitBonus),
	m_Damage1(damage1),
	m_Damage2(damage2),
	*/m_Damage3(damage3)
	/*m_EnemyDead(enemyDead)*/
{}

//void Boss::SetBossDescription(std::string desc) {
//	m_Description = desc;
//}
//
//void Boss::SetBossToHitBonus(int toHitBonus) {
//	m_ToHitBonus = toHitBonus;
//}
//
//void Boss::SetBossDamage1(int damage1) {
//	m_Damage1 = damage1;
//}
//void Boss::SetBossDamage2(int damage2) {
//	m_Damage2 = damage2;
//}
void Boss::SetBossDamage3(int damage3) {
	m_Damage3 = damage3;
}
//void Boss::SetEnemyDead(bool enemyDead) {
//	m_EnemyDead = enemyDead;
//}

void Enemy::Attack(Character& player, Enemy& enemy) {
	// make attack roll
	int attack = RollDice(1, 20);
	std::cout << enemy.GetName() << " attacks " << player.GetName() << "!" << std::endl;
	// add modifiers	
	std::cout << "Roll (" << attack << ") + " << enemy.GetEnemyToHitBonus() << std::endl;
	attack += enemy.GetEnemyToHitBonus();
	// compare to ac
	if (attack >= player.GetArmorClass()) {
		std::cout << " hits!" << std::endl;
		// roll damage
		std::cout << player.GetName() << " takes " << enemy.GetEnemyDamage() << " DAMAGE!!";
		player.TakeDamage(enemy.GetEnemyDamage());
	}
	else {
		std::cout << enemy.GetName() << " misses!" << std::endl;
	}
}

void EnemyStrong::Attack(Character& player, EnemyStrong& enemy) {
	// make attack roll
	int attack1 = RollDice(1, 20);
	int attack2 = RollDice(1, 20);
	std::cout << enemy.GetName() << " attacks " << player.GetName() << "!" << std::endl;
	// add modifiers
	std::cout << "Roll (" << attack1 << ") + " << enemy.GetEnemyToHitBonus() << std::endl;
	attack1 += enemy.GetEnemyToHitBonus();
	// compare to ac
	if (attack1 >= player.GetArmorClass()) {
		std::cout << " hits!" << std::endl;
		// roll damage
		std::cout << player.GetName() << " takes " << enemy.GetEnemyDamage() << " DAMAGE!!";
		player.TakeDamage(enemy.GetEnemyDamage());
	}
	else {
		std::cout << enemy.GetName() << " misses!" << std::endl;
	}
	// make attack roll 2
	std::cout << enemy.GetName() << " attacks " << player.GetName() << "!" << std::endl;
	// add modifiers
	std::cout << "Roll (" << attack2 << ") + " << enemy.GetEnemyToHitBonus() << std::endl;
	attack2 += enemy.GetEnemyToHitBonus();
	// compare to ac
	if (attack2 >= player.GetArmorClass()) {
		std::cout << " hits!" << std::endl;
		// roll damage
		std::cout << player.GetName() << " takes " << enemy.GetEnemyDamage2() << " DAMAGE!!";
		player.TakeDamage(enemy.GetEnemyDamage2());
	}
	else {
		std::cout << enemy.GetName() << " misses!" << std::endl;
	}
}

void Boss::Attack(Character& player, Boss& enemy) {
	// make attack roll
	int attack1 = RollDice(1, 20);
	int attack2 = RollDice(1, 20); 
	int attack3 = RollDice(1, 20);
	std::cout << enemy.GetName() << " attacks " << player.GetName() << "!" << std::endl;
	// add modifiers
	std::cout << "Roll (" << attack1 << ") + " << enemy.GetEnemyToHitBonus() << std::endl;
	attack1 += enemy.GetEnemyToHitBonus();
	// compare to ac
	if (attack1 >= player.GetArmorClass()) {
		std::cout << " hits!" << std::endl;
		// roll damage
		std::cout << player.GetName() << " takes " << enemy.GetEnemyDamage() << " DAMAGE!!";
		player.TakeDamage(enemy.GetEnemyDamage());
	}
	else {
		std::cout << enemy.GetName() << " misses!" << std::endl;
	}
	// make attack roll2
	std::cout << enemy.GetName() << " attacks " << player.GetName() << "!" << std::endl;
	// add modifiers
	std::cout << "Roll (" << attack2 << ") + " << enemy.GetEnemyToHitBonus() << std::endl;
	attack2 += enemy.GetEnemyToHitBonus();
	// compare to ac
	if (attack2 >= player.GetArmorClass()) {
		std::cout << " hits!" << std::endl;
		// roll damage
		std::cout << player.GetName() << " takes " << enemy.GetEnemyDamage2() << " DAMAGE!!";
		player.TakeDamage(enemy.GetEnemyDamage2());
	}
	else {
		std::cout << enemy.GetName() << " misses!" << std::endl;
	}
	// make attack roll 3
	std::cout << enemy.GetName() << " attacks " << player.GetName() << "!" << std::endl;
	// add modifiers
	std::cout << "Roll (" << attack3 << ") + " << enemy.GetEnemyToHitBonus() << std::endl;
	attack3 += enemy.GetEnemyToHitBonus();
	// compare to ac
	if (attack3 >= player.GetArmorClass()) {
		std::cout << " hits!" << std::endl;
		// roll damage
		std::cout << player.GetName() << " takes " << enemy.GetBossDamage3() << " DAMAGE!!";
		player.TakeDamage(enemy.GetBossDamage3());
	}
	else {
		std::cout << enemy.GetName() << " misses!" << std::endl;
	}
}