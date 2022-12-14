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

SpellWeapon::SpellWeapon(std::string name, std::string description, std::string rarity, double value, int toHitBonus, int damage, int castingRequirement) :
	Weapon(name, description, rarity, value, toHitBonus, damage),
	m_CastingRequirement(castingRequirement)
{}

Armour::Armour(std::string name, std::string description, std::string rarity, double value, int acBonus, int strRequirement) :
	Item(name, description, rarity, value),
	m_AcBonus(acBonus),
	m_StrengthRequirement(strRequirement)
{}

Shield::Shield(std::string name, std::string description, std::string rarity, double value, int acBonus, int strRequirement) :
	Armour(name, description, rarity, value, acBonus, strRequirement)
	//m_AcBonus(acBonus),
	//m_StrengthRequirement(strRequirement)
{}

Healing::Healing(std::string name, std::string description, std::string rarity, double value, int heal) :
	Item(name, description, rarity, value),
	m_HpHealAmount(heal)
{}

UseableItems::UseableItems(std::string name, std::string description, std::string rarity, double value, std::string use) :
	Item(name, description, rarity, value),
	m_Use(use)
{}

Interactables::Interactables(std::string name, std::string description, std::string interaction, bool empty) :
	m_Name(name),
	m_Description(description),
	m_Interaction(interaction),
	m_Empty(empty)
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
void Interactables::SetContainerEmpty(bool empty) {
	m_Empty = empty;
}
void Weapon::SetToHitBonus(int toHitBonus) {
	m_ToHitBonus = toHitBonus;
}
void Weapon::SetDamage(int damage) {
	m_AttackDamage = damage;
}
void Armour::SetACBonus(int acBonus) {
	m_AcBonus = acBonus;
}
void Armour::SetStrenghtRequirement(int strRequirement) {
	m_StrengthRequirement = strRequirement;
}
//void Shield::SetACBonus(int acBonus) {
//	m_AcBonus = acBonus;
//}
//void Shield::SetStrenghtRequirement(int strRequirement) {
//	m_StrengthRequirement = strRequirement;
//}
void Healing::SetHpHealAmout(int heal) {
	m_HpHealAmount = heal;
}
void SpellWeapon::SetCastingRequirement(int castingRequirement) {
	m_CastingRequirement = castingRequirement;
}

