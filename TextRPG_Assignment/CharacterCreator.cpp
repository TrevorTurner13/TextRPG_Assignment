#include "CharacterCreator.h"

Character::Character(std::string name, int str, int dex, int con, int iq, int wis, int cha, int hp, int ac, double gold, int exp, int level) :
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

void Character::SetCharacterGold(double gold) {
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
void Character::SetEquippedWeapon(Weapon* weapon) {
	m_EquippedWeapon = NULL;
	m_EquippedWeapon = weapon;
}
void Character::SetEquippedArmour(Armour* armour) {
	m_EquippedArmour = NULL;
	m_EquippedArmour = armour;
}
void Character::SetEquippedShield(Shield* shield) {
	m_EquippedShield = NULL;
	m_EquippedShield = shield;
}
void Character::SetEquippedSpellWeapon(SpellWeapon* spellWeapon) {
	m_EquippedSpellWeapon = NULL;
	m_EquippedSpellWeapon = spellWeapon;
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


std::vector<Item*> Character::GetInventory(std::vector<Item*> items, std::vector<Weapon*> weapons, std::vector<Armour*> armours, std::vector<SpellWeapon*> spellWeapons) {
	return m_Inventory;
}

void Character::DisplayInventory() {
	std::cout << std::endl << "Inventory" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << std::left << std::setw(50) << "Item Name" << std::left << std::setw(12) << "Rarity";
	std::cout << std::right << std::setw(12) << "Value\n\n";
	std::vector<Weapon*>::iterator weaponIter;
	for (weaponIter = m_Weapons.begin(); weaponIter < m_Weapons.end(); ++weaponIter) {
		std::cout << std::left << std::setw(50) << (*weaponIter)->GetItemName() << std::left << std::setw(12) << (*weaponIter)->GetItemRarity();
		std::cout << std::right << std::setw(12) << (*weaponIter)->GetItemValue() << std::endl << std::endl;
	}
	std::vector<Armour*>::iterator armourIter;
	for (armourIter = m_Armours.begin(); armourIter < m_Armours.end(); ++armourIter) {
		std::cout << std::left << std::setw(50) << (*armourIter)->GetItemName() << std::left << std::setw(12) << (*armourIter)->GetItemRarity();
		std::cout << std::right << std::setw(12) << (*armourIter)->GetItemValue() << std::endl << std::endl;
	}
	std::vector<Shield*>::iterator shieldIter;
	for (shieldIter = m_Shields.begin(); shieldIter < m_Shields.end(); ++shieldIter) {
		std::cout << std::left << std::setw(50) << (*shieldIter)->GetItemName() << std::left << std::setw(12) << (*shieldIter)->GetItemRarity();
		std::cout << std::right << std::setw(12) << (*shieldIter)->GetItemValue() << std::endl << std::endl;

	}
	std::vector<SpellWeapon*> ::iterator spellIter;
	for (spellIter = m_SpellWeapons.begin(); spellIter < m_SpellWeapons.end(); ++spellIter) {
		std::cout << std::left << std::setw(50) << (*spellIter)->GetItemName() << std::left << std::setw(12) << (*spellIter)->GetItemRarity();
		std::cout << std::right << std::setw(12) << (*spellIter)->GetItemValue() << std::endl << std::endl;
	}
	std::vector<Healing*>::iterator healingIter;
	for (healingIter = m_Healing.begin(); healingIter < m_Healing.end(); ++healingIter) {
		std::cout << std::left << std::setw(50) << (*healingIter)->GetItemName() << std::left << std::setw(12) << (*healingIter)->GetItemRarity();
		std::cout << std::right << std::setw(12) << (*healingIter)->GetItemValue() << std::endl << std::endl;
	}
	std::vector<Item*>::iterator itemIter;
	for (itemIter = m_Items.begin(); itemIter < m_Items.end(); ++itemIter) {
		std::cout << std::left << std::setw(50) << (*itemIter)->GetItemName() << std::left << std::setw(12) << (*itemIter)->GetItemRarity();
		std::cout << std::right << std::setw(12) << (*itemIter)->GetItemValue() << std::endl << std::endl;
	}
}

void Character::DisplayHealingItems() {
	std::cout << std::endl << std::endl << "The following healing items are available: " << std::endl;
	std::cout << std::endl << "[0] Back";
	std::vector<Healing*>::iterator iter;
	for (iter = m_Healing.begin(); iter < m_Healing.end(); ++iter) {
		std::cout << "[" << iter - m_Healing.begin() + 1 << "]" << (*iter)->GetItemName() << std::endl;
		std::cout << "Heals " << (*iter)->GetHpHealAmount() << " HP" << std::endl;
		std::cout << (*iter)->GetItemDescription() << std::endl;
	}
}

void Character::DisplayWeapons() {
	std::cout << "\nThe following weapons are available: " << std::endl;
	std::vector<Weapon*>::iterator iter;
	for (iter = m_Weapons.begin(); iter < m_Weapons.end(); ++iter) {
		std::cout << "[" << iter - m_Weapons.begin() + 1 << "] " << (*iter)->GetItemName() << std::endl;
		std::cout << (*iter)->GetItemDescription() << std::endl;
	}
}
void Character::DisplayEquippedWeapon() {
		std::cout << "\nYou have the following weapon equipped: " << std::endl;
		std::cout << GetEquippedWeapon()->GetItemName() << std::endl << std::endl;
		std::cout << GetEquippedWeapon()->GetItemDescription() << std::endl;
}

void Character::DisplayArmour() {
	std::cout << "\nThe following Armour are available: " << std::endl;
	std::vector<Armour*>::iterator iter;
	for (iter = m_Armours.begin(); iter < m_Armours.end(); ++iter) {
		std::cout << "\n[" << iter - m_Armours.begin() + 1 << "] " << (*iter)->GetItemName() << std::endl;
		std::cout << (*iter)->GetItemDescription() << std::endl;
	}
}
void Character::DisplayEquippedArmour() {
		std::cout << "\nYou have the following armour equipped: " << std::endl;
		std::cout << GetEquippedArmour()->GetItemName() << std::endl << std::endl;
		std::cout << GetEquippedArmour()->GetItemDescription() << std::endl;
}

void Character::DisplayShields() {
	std::cout << "\nThe following Shields are available: " << std::endl;
	std::vector<Shield*>::iterator iter;
	for (iter = m_Shields.begin(); iter < m_Shields.end(); ++iter) {
		std::cout << "\n[" << iter - m_Shields.begin() + 1 << "] " << (*iter)->GetItemName() << std::endl;
		std::cout << (*iter)->GetItemDescription() << std::endl;
	}
}
void Character::DisplayEquippedShield() {
		std::cout << "\nYou have the following shield equipped: " << std::endl;
		std::cout << GetEquippedShield()->GetItemName() << std::endl << std::endl;
		std::cout << GetEquippedShield()->GetItemDescription() << std::endl;
}

void Character::DisplaySpellWeapons() {
	std::cout << "\nThe following spell weapons are available: " << std::endl;
	std::vector<SpellWeapon*>::iterator iter;
	for (iter = m_SpellWeapons.begin(); iter < m_SpellWeapons.end(); ++iter) {
		std::cout << "[" << iter - m_SpellWeapons.begin() + 1 << "] " << (*iter)->GetItemName() << std::endl;
		std::cout << (*iter)->GetItemDescription() << std::endl;
	}
}
void Character::DisplayEquippedSpellWeapon() {
		std::cout << "\nYou have the following spell weapon equipped: " << std::endl;
		std::cout << GetEquippedSpellWeapon()->GetItemName() << std::endl << std::endl;
		std::cout << GetEquippedSpellWeapon()->GetItemDescription() << std::endl;
}

int Character::RollDice(int numberOfDice, int numberOfSides) {
	int result = 0;
	for (int i = 0; i < numberOfDice; ++i) {
		result += rand() % numberOfSides + 1;
	}
	return result;
}

void Character::Attack(Character& enemy, Weapon* weapon) {
	// make attack roll
	int attack = RollDice(1, 20);
	std::cout << m_Name << " attacks " << enemy.GetName() << "!" << std::endl;
	// add modifiers
	attack += weapon->GetToHitBonus();
	std::cout << "Roll (" << attack << ") + " << weapon->GetToHitBonus() << std::endl;
	// compare to ac
	if (attack >= enemy.GetArmorClass()) {
		std::cout << " hits!" << std::endl;
		// roll damage
		std::cout << enemy.m_Name << " takes " << weapon->GetDamage() << " DAMAGE!!";
		enemy.TakeDamage(weapon->GetDamage());
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

void Character::LevelUp() {
	static const int requiredEXP[] = {
		0, 500, 1500, 3000, 6000, 12000, 24000, 48000, 96000
	};
	while (m_EXP >= requiredEXP[m_Level]) {
		++m_Level;
		m_MaxHP = m_MaxHP + 10 + GetModifier(m_Constitution);
		m_CurrentHP = m_MaxHP;
		++m_Strength;
		++m_Dexterity;
		++m_Constitution;
		++m_Intelligence;
		++m_Wisdom;
		++m_Charisma;
	}
}
