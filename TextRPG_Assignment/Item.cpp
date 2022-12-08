#include "Item.h"

Item::Item(std::string name, std::string description, std::string rarity, double value) :
	m_Name(name),
	m_Description(description),
	m_Rarity(rarity),
	m_Value(value)
{}

Weapon::Weapon(std::string name, std::string description, std::string rarity, double value, int toHitBonus, int damage) :
	Item(name, description, rarity, value),
	m_ToHitBonus(toHitBonus),
	m_AttackDamage(damage)
{}

SpellWeapon::SpellWeapon(std::string name, std::string description, std::string rarity, double value, int toHitBonus, int damage) :
	Weapon(name, description, rarity, value, toHitBonus, damage)
{}

Armour::Armour(std::string name, std::string description, std::string rarity, double value, int acBonus, int strRequirement) :
	Item(name, description, rarity, value),
	m_AcBonus(acBonus),
	m_StrengthRequirement(strRequirement)
{}

HealingPotion::HealingPotion(std::string name, std::string description, std::string rarity, double value, int heal) :
	Item(name, description, rarity, value),
	m_HpHealAmount(heal)
{}

UseableItems::UseableItems(std::string name, std::string description, std::string rarity, double value, std::string use) :
	Item(name, description, rarity, value),
	m_Use(use)
{}

Interactables::Interactables(std::string name, std::string description, std::string interaction) :
	m_Name(name),
	m_Description(description),
	m_Interaction(interaction)
{}

void Item::SetItemName(std::string name) {
	m_Name = name;
}
void Item::SetItemDescription(std::string description) {
	m_Description = description;
}
void Item::SetItemRarity(std::string rarity) {
	m_Rarity = rarity;
}
void Item::SetItemValue(double value) {
	m_Value = value;
}
void Interactables::SetInteractableName(std::string name) {
	m_Name = name;
}
void Interactables::SetInteractableInteraction(std::string interaction) {
	m_Interaction = interaction;
}
void Interactables::SetInteractableDescription(std::string description) {
	m_Description = description;
}
void Weapon::SetToHitBonus(int toHitBonus) {
	m_ToHitBonus = toHitBonus;
}
void Weapon::SetDamage(int damage) {
	m_AttackDamage = damage;
}

