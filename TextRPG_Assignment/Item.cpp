#include "Item.h"

Item::Item(std::string name, std::string description, std::string rarity, int value) :
	m_Name(name),
	m_Description(description),
	m_Rarity(rarity),
	m_Value(value)
{}

Weapon::Weapon(std::string name, std::string description, std::string rarity, int value, int toHitBonus, int damage) :
	m_ToHitBonus(toHitBonus),
	m_AttackDamage(damage)
{}

Armor::Armor(std::string name, std::string description, std::string rarity, int value, int acBonus, int strRequirement) :
	m_AcBonus(acBonus),
	m_StrengthRequirement(strRequirement)
{}

HealingPotion::HealingPotion(std::string name, std::string description, std::string rarity, int value, int heal) :
	m_HpHealAmount(heal)
{}

UseableItems::UseableItems(std::string name, std::string description, std::string rarity, int value, std::string use) :
	m_Use(use)
{}