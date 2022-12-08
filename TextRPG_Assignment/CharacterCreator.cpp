#include "CharacterCreator.h"

Character::Character(std::string name, int str, int dex, int con, int iq, int wis, int cha, int hp, int ac, int gold, int exp, int level) :
	m_Name(name),
	m_Strength(str),
	m_Dexterity(dex),
	m_Constitution(con),
	m_Intelligence(iq),
	m_Wisdom(wis),
	m_Charisma(cha),
	m_MaxHP(hp),
	m_CurrentHP(hp),
	m_ArmorClass(ac),
	m_Gold(gold),
	m_EXP(exp),
	m_Level(level)
{}

void Character::SetPlayerName(std::string name) {
	m_Name = name;
}

void Character::SetCharacterAncestry(characterAncestry ancestry) {
	m_Ancestry = ancestry;
}

void Character::SetCharacterWarrior(characterWarrior warrior) {
	m_Warrior = warrior;
}

void Character::SetSpellAbility(characterWarrior warrior) {
	m_Warrior = warrior;
}

void Character::SetSpellModifier(characterWarrior warrior) {
	m_Warrior = warrior;
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
void Character::SetCharacterEXP(int exp) {
	m_EXP = exp;
}
void Character::SetCharacterLevel(int level) {
	m_Level = level;
}
void Character::SetInventory(std::vector<Item*> inventory) {
	m_Inventory = inventory;
}
void Character::SetItems(std::vector<Item*> items) {
	m_Items = items;
}
void Character::SetWeapons(std::vector<Weapon*> weapons) {
	m_Weapons = weapons;
}
void Character::SetArmours(std::vector<Armour*> armours) {
	m_Armours = armours;
}
void Character::SetSpellWeapons(std::vector<SpellWeapon*> spellWeapons) {
	m_SpellWeapons = spellWeapons;
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
std::string Character::GetCharacterAncestry(characterAncestry ancestry) {
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
std::string Character::GetCharacterWarrior(characterWarrior warrior) {
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
int Character::GetSpellModifier(characterWarrior warrior) {
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

std::string Character::GetSpellAbility(characterWarrior warrior) {
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

int Character::GetCharacterLevel(int exp) {
	if (exp == 0 && exp > 1000) {
		SetCharacterLevel(1);
	}
	if (exp == 1000 && exp < 2000) {
		SetCharacterLevel(2);
		SetStrength(GetStrength() + 1);
		SetDexterity(GetDexterity() + 1);
		SetConstitution(GetConstitution() + 1);
		SetIntelligence(GetIntelligence() + 1);
		SetWisdom(GetWisdom() + 1);
		SetCharisma(GetCharisma() + 1);
		SetMaxHP(GetMaxHP() + 10 + GetModifier(GetConstitution()));
	}
	if (exp == 2000 && exp < 5000) {
		SetCharacterLevel(3);
		SetStrength(GetStrength() + 1);
		SetDexterity(GetDexterity() + 1);
		SetConstitution(GetConstitution() + 1);
		SetIntelligence(GetIntelligence() + 1);
		SetWisdom(GetWisdom() + 1);
		SetCharisma(GetCharisma() + 1);
		SetMaxHP(GetMaxHP() + 10 + GetModifier(GetConstitution()));
	}
	if (exp == 5000 && exp < 10000) {
		SetCharacterLevel(4);
		SetStrength(GetStrength() + 1);
		SetDexterity(GetDexterity() + 1);
		SetConstitution(GetConstitution() + 1);
		SetIntelligence(GetIntelligence() + 1);
		SetWisdom(GetWisdom() + 1);
		SetCharisma(GetCharisma() + 1);
		SetMaxHP(GetMaxHP() + 10 + GetModifier(GetConstitution()));
	}
	if (exp == 10000 && exp < 20000) {
		SetCharacterLevel(5);
		SetStrength(GetStrength() + 1);
		SetDexterity(GetDexterity() + 1);
		SetConstitution(GetConstitution() + 1);
		SetIntelligence(GetIntelligence() + 1);
		SetWisdom(GetWisdom() + 1);
		SetCharisma(GetCharisma() + 1);
		SetMaxHP(GetMaxHP() + 10 + GetModifier(GetConstitution()));
	}
	if (exp > 20000) {
		SetCharacterLevel(6);
		SetStrength(GetStrength() + 1);
		SetDexterity(GetDexterity() + 1);
		SetConstitution(GetConstitution() + 1);
		SetIntelligence(GetIntelligence() + 1);
		SetWisdom(GetWisdom() + 1);
		SetCharisma(GetCharisma() + 1);
		SetMaxHP(GetMaxHP() + 10 + GetModifier(GetConstitution()));
	}
	return m_Level;
}

void Character::Weapons(Weapon weapon) {
	m_Weapons.push_back(&weapon);
}
void Character::Armours(Armour armour) {
	m_Armours.push_back(&armour);
}
void Character::Items(Item item) {
	m_Items.push_back(&item);
}

void Character::SpellWeapons(SpellWeapon spellWeapon) {
	m_SpellWeapons.push_back(&spellWeapon);
}

std::vector<Item*> Character::GetInventory(std::vector<Item*> items, std::vector<Weapon*> weapons, std::vector<SpellWeapon*> spellWeapons) {
	return m_Inventory;
}

void Character::DisplayInventory(std::vector<Item*> inventory) {
	std::cout << std::endl << "Inventory" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << std::left << std::setw(30) << "Item Name" << std::left << std::setw(12) << "Rarity";
	std::cout << std::right << std::setw(12) << "Value\n\n";
	std::vector<Item*>::iterator iter;
	for (iter = inventory.begin(); iter < inventory.end(); ++iter) {
		std::cout << std::left << std::setw(30) << (*iter)->GetItemName() << std::left << std::setw(12) << (*iter)->GetItemRarity();
		std::cout << std::right << std::setw(12) << (*iter)->GetItemValue() << "\n\nDescription: " << (*iter)->GetItemDescription() << std::endl << std::endl;
	}
}

void Character::DisplayWeapons(std::vector<Weapon*> weapons) {
	std::cout << "You have the following weapons: " << std::endl;
	std::vector<Weapon*>::iterator iter;
	for (iter = weapons.begin(); iter < weapons.end(); ++iter) {
		std::cout << "[" << iter - weapons.begin() + 1 << "] " << (*iter)->GetItemName();
	}
}

void Character::EquipItems() {

}

int Character::RollDice(int numberOfDice, int numberOfSides) {
	int result = 0;
	for (int i = 0; i < numberOfDice; ++i) {
		result += rand() % numberOfSides + 1;
	}
	return result;
}

void Character::Attack(Character& enemy, Weapon& weapon) {
	// make attack roll
	int attack = RollDice(1, 20);
	std::cout << m_Name << " attacks " << enemy.GetName() << "!" << std::endl;
	// add modifiers
	attack += weapon.GetToHitBonus();
	std::cout << "Roll (" << attack << ") + " << weapon.GetToHitBonus() << std::endl;
	// compare to ac
	if (attack >= enemy.GetArmorClass()) {
		std::cout << " hits!" << std::endl;
		// roll damage
		std::cout << enemy.m_Name << " takes " << weapon.GetDamage() << " DAMAGE!!";
	}
	else {
		std::cout << m_Name << " misses!" << std::endl;
	}
	
}

void Character::TakeDamage(int damage) {
	m_CurrentHP -= damage;
}

void Character::Heal(int heal) {
	std::cout << m_Name << " uses their magic to heal themselves!";
	m_CurrentHP += heal;
}

void Character::LevelUp(int exp) {

}
