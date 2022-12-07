#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

enum characterAncestry { DWARF = 1, DRAGONBORN, ELF, GNOME, HALFING, HUMAN, ORC };
enum characterWarrior { BARD = 1, FIGHTER, MONK, PALADIN, ROGUE, WIZARD };

class Character {
public:
	Character(int str, int dex, int con, int iq, int wis, int cha, int hp, int ac, int gold, int exp, int level);
	characterAncestry m_Ancestry;
	characterWarrior m_Warrior;
	
	void SetPlayerName(std::string name);
	void Attack(Character& enemy);
	void TakeDamage(int damage);
	void Heal(int heal);
	void LevelUp(int exp);

	int RollDice(int numberOfDice, int numberOfSides);
	int GetModifier(int stat);

	void SetCharacterWarrior(characterWarrior warrior);
	void SetCharacterAncestry(characterAncestry ancestry);
	void SetStrength(int str);
	void SetDexterity(int dex);
	void SetConstitution(int con);
	void SetIntelligence(int iq);
	void SetWisdom(int wis);
	void SetCharisma(int cha);
	void SetHP(int hp);
	void SetMaxHP(int maxHP);
	void SetSpellAbility(characterWarrior warrior);
	void SetSpellModifier(characterWarrior warrior);
	void SetArmorClass(int dex);
	void SetCharacterGold(int gold);
	void SetCharacterLevel(int level);
	void SetCharacterEXP(int exp);
	
	std::string GetName() { return m_Name; }
	std::string GetSpellAbility(characterWarrior warrior);
	std::string GetCharacterAncestry(characterAncestry ancestry);
	std::string GetCharacterWarrior(characterWarrior warrior);
	int GetStrength() { return m_Strength; }
	int GetDexterity() { return m_Dexterity; }
	int GetConstitution() { return m_Constitution; }
	int GetIntelligence() { return m_Intelligence; }
	int GetWisdom() { return m_Wisdom; }
	int GetCharisma() { return m_Charisma; }
	int GetHP() { return m_CurrentHP; }
	int GetMaxHP() { return m_MaxHP; }
	int GetSpellModifier(characterWarrior warrior);
	int GetArmorClass() { return m_ArmorClass; }
	int GetCharacterGold() { return m_Gold; }	
	int GetCharacterEXP() { return m_EXP; }
	int GetCharacterLevel(int exp);

private:
	std::vector<std::string> m_Objectives;
	std::string m_Name;
	std::string m_SpellAbility;
	int m_Strength;
	int m_Dexterity;
	int m_Constitution;
	int m_Intelligence;
	int m_Wisdom;
	int m_Charisma;
	int m_CurrentHP;
	int m_MaxHP;
	int m_SpellModifier;
	int m_ArmorClass;
	int m_Gold;
	int m_EXP;
	int m_Level;
	
};