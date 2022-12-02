#include "CharacterCreator.h"

Character::Character(int str, int dex, int con, int iq, int wis, int cha, int hp, int ac, int gold) :
	
	m_Strength(str),
	m_Dexterity(dex),
	m_Constitution(con),
	m_Intelligence(iq),
	m_Wisdom(wis),
	m_Charisma(cha),
	m_MaxHP(hp),
	m_CurrentHP(hp),
	m_ArmorClass(ac),
	m_Gold(gold)
{}

void Character::SetPlayerName(std::string name) {
	m_Name = name;
}

void Character::SetCharacterAncestry(int ancestry) {
	m_Ancestry == ancestry;
}

void Character::SetCharacterWarrior(int warrior) {
	m_Warrior == warrior;
}

void Character::SetSpellAbility(int warrior) {
	m_Warrior == warrior;
}

void Character::SetSpellModifier(int warrior) {
	m_Warrior == warrior;
}

void Character::SetStrength(int str) {
	m_Strength = str;
}

void Character::SetDexterity(int dex) {
	m_Dexterity = dex;
}

void Character::SetConstitution(int con) {
	m_Constitution = con;
}

void Character::SetIntelligence(int iq) {
	m_Intelligence = iq;
}

void Character::SetWisdom(int wis) {
	m_Wisdom = wis;
}

void Character::SetCharisma(int cha) {
	m_Charisma = cha;
}
void Character::SetHP(int hp) {
	m_CurrentHP = hp;
}

void Character::SetMaxHP(int hp) {
	m_MaxHP = hp;
}

void Character::SetArmorClass(int ac) {
	m_ArmorClass = ac;
}

void Character::SetCharacterGold(int gold) {
	m_Gold = gold;
}


int Character::GetModifier(int stat) {
	int modifier = 0;
	switch (stat) {
	case 3:
		modifier = -4;
		break;
	case 4:
	case 5:
		modifier = -3;
		break;
	case 6:
	case 7:
		modifier = -2;
		break;
	case 8:
	case 9:
		modifier = -1;
		break;
	case 10:
	case 11:
		break;
	case 12:
	case 13:
		modifier = 1;
		break;
	case 14:
	case 15:
		modifier = 2;
		break;
	case 16:
	case 17:
		modifier = 3;
		break;
	case 18:
	case 19:
		modifier = 4;
		break;
	case 20:
		modifier = 5;
		break;
	}
	return modifier;
}
std::string Character::GetCharacterAncestry(int ancestry) {
	m_Ancestry == ancestry;
	std::string m_pAncestry;
	switch (ancestry) {
	case DWARF:
		m_pAncestry = "Dwarf";
		break;
	case DRAGONBORN:
		m_pAncestry = "Dragonborn";
		break;
	case ELF:
		m_pAncestry = "Elf";
		break;
	case GNOME:
		m_pAncestry = "Gnome";
		break;
	case HALFING:
		m_pAncestry = "Halfling";
		break;
	case HUMAN:
		m_pAncestry = "Human";
		break;
	case ORC:
		m_pAncestry = "Orc";
		break;
	}
	return m_pAncestry;
}
std::string Character::GetCharacterWarrior(int warrior) {
	m_Warrior == warrior;
	std::string m_pWarrior;
	switch (warrior) {
	case BARD:
		m_pWarrior = "Bard";
		break;
	case FIGHTER:
		m_pWarrior = "Fighter";
		break;
	case MONK:
		m_pWarrior = "Monk";
		break;
	case PALADIN:
		m_pWarrior = "Paladin";
		break;
	case ROGUE:
		m_pWarrior = "Rogue";
		break;
	case WIZARD:
		m_pWarrior = "Wizard";
		break;
	}
	return m_pWarrior;
}
int Character::GetSpellModifier(int warrior) {
	int spellModifier = 0;
	switch (warrior) {
	case BARD:
		spellModifier = GetModifier(GetCharisma());
		break;
	case FIGHTER:
		spellModifier = GetModifier(GetWisdom());
		break;
	case MONK:
		spellModifier = GetModifier(GetWisdom());
		break;
	case PALADIN:
		spellModifier = GetModifier(GetCharisma());
		break;
	case ROGUE:
		spellModifier = GetModifier(GetIntelligence());
		break;
	case WIZARD:
		spellModifier = GetModifier(GetIntelligence());
		break;
	}
	return spellModifier;
}

std::string Character::GetSpellAbility(int warrior) {
	std::string spellAbility;
	switch (warrior) {
	case BARD:
		spellAbility = "Charisma";
		break;
	case FIGHTER:
		spellAbility = "Wisdom";
		break;
	case MONK:
		spellAbility = "Wisdom";
		break;
	case PALADIN:
		spellAbility = "Charisma";
		break;
	case ROGUE:
		spellAbility = "Intelligence";
		break;
	case WIZARD:
		spellAbility = "Intelligence";
		break;
	}
	return spellAbility;
}

int Character::RollDice(int numberOfDice, int numberOfSides) {
	int result = 0;
	for (int i = 0; i < numberOfDice; ++i) {
		result += rand() % numberOfSides + 1;
	}
	return result;
}

void Character::Attack(Character& character) {

}

void Character::TakeDamage(int damage) {

}

void Character::Heal() {

}

void Character::CastSpell(Character& character) {

}

