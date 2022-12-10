#pragma once

#include "CharacterCreator.h"

class Enemy: public Character {
public:
	Enemy(std::string name, std::string desc, int str, int dex, int con, int iq, int wis, int cha, int hp, int ac, int gold, int exp, int level, int toHitBonus, int damage);
	
	void SetEnemyDescription(std::string desc);
	void SetEnemyToHitBonus(int toHitBonus);
	void SetEnemyDamage(int damage);
	void Attack(Character&, Enemy&);

	std::string GetEnemyDescription() { return m_Description; }
	int GetEnemyToHitBonus() { return m_ToHitBonus; }
	int GetEnemyDamage() { return m_Damage; }

private:
	std::string m_Description;
	int m_ToHitBonus;
	int m_Damage;
};

class EnemyStrong : public Character{
public:
	EnemyStrong(std::string name, std::string desc, int str, int dex, int con, int iq, int wis, int cha, int hp, int ac, int gold, int exp, int level, int toHitBonus, int damage1, int damage2);
	
	void SetEnemyDescription(std::string desc);
	void SetEnemyToHitBonus(int toHitBonus);
	void SetEnemyDamage1(int damage1);
	void SetEnemyDamage2(int damage2);
	void Attack(Character&, EnemyStrong&);

	std::string GetEnemyDescription() { return m_Description; }
	int GetEnemyToHitBonus() { return m_ToHitBonus; }
	int GetEnemyDamage1() { return m_Damage1; }
	int GetEnemyDamage2() { return m_Damage2; }

private:
	std::string m_Description;
	int m_ToHitBonus;
	int m_Damage1;
	int m_Damage2;
};

class Boss : public Character {
public:
	Boss(std::string name, std::string desc, int str, int dex, int con, int iq, int wis, int cha, int hp, int ac, int gold, int exp, int level, int toHitBonus, int damage1, int damage2, int damage3);

	void SetBossDescription(std::string desc);
	void SetBossToHitBonus(int toHitBonus);
	void SetBossDamage1(int damage1);
	void SetBossDamage2(int damage2);
	void SetBossDamage3(int damage3);
	void Attack(Character&, Boss&);

	std::string GetBossDescription() { return m_Description; }
	int GetBossToHitBonus() { return m_ToHitBonus; }
	int GetBossDamage1() { return m_Damage1; }
	int GetBossDamage2() { return m_Damage2; }
	int GetBossDamage3() { return m_Damage3; }

private:
	std::string m_Description;
	int m_ToHitBonus;
	int m_Damage1;
	int m_Damage2;
	int m_Damage3;
};