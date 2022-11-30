#pragma once
#include <string>
#include <iostream>

enum characterAncestry { DWARF = 1, DRAGONBORN, ELF, GNOME, HALFING, HUMAN, ORC };
enum characterWarrior { BARD = 1, FIGHTER, MONK, PALADIN, ROGUE, WIZARD };

class Character {
public:
	Character(int str, int dex, int con, int iq, int wis, int cha, int hp);
	characterAncestry m_Ancestry;
	characterWarrior m_Warrior;

	void SetPlayerName(std::string name);
	void Attack(Character& character);
	void TakeDamage(int damage);
	void Heal();
	void CastSpell(Character& character);
	
	
	int RollDice(int numberOfDice, int numberOfSides);
	int GetModifier(int stat);

	void SetCharacterWarrior(int warrior);
	void SetCharacterAncestry(int ancestry);
	void SetStrength(int str);
	void SetDexterity(int dex);
	void SetConstitution(int con);
	void SetIntelligence(int iq);
	void SetWisdom(int wis);
	void SetCharisma(int cha);
	void SetHP(int hp);
	void SetMaxHP(int maxHP);
	void SetSpellAbility(int warrior);
	void SetSpellModifier(int warrior);

	std::string GetName() { return m_Name; }
	std::string GetSpellAbility(int warrior);
	std::string GetCharacterAncestry(int ancestry);
	std::string GetCharacterWarrior(int warrior);
	int GetStrength() { return m_Strength; }
	int GetDexterity() { return m_Dexterity; }
	int GetConstitution() { return m_Constitution; }
	int GetIntelligence() { return m_Intelligence; }
	int GetWisdom() { return m_Wisdom; }
	int GetCharisma() { return m_Charisma; }
	int GetHP() { return m_CurrentHP; }
	int GetMaxHP() { return m_MaxHP; }
	int GetSpellModifier(int warrior);
	

private:
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
	
};