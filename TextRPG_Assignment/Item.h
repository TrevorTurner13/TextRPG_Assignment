#pragma once

#include<iostream>
#include <string>
#include <vector>
#include <iomanip>

class Item {
public:
	Item(std::string name, std::string description, std::string rarity, double value);
	void SetItemName(std::string name);
	void SetItemDescription(std::string description);
	void SetItemRarity(std::string rarity);
	void SetItemValue(double value);

	std::string GetItemName() { return m_Name; }
	std::string GetItemDescription() { return m_Description; }
	std::string GetItemRarity() { return m_Rarity; }
	double GetItemValue() { return m_Value; }
private:
	std::string m_Name;
	std::string m_Description;
	std::string m_Rarity;
	double m_Value;
};

class Weapon: public Item {
public:
	Weapon(std::string name, std::string description, std::string rarity, double value, int toHitBonus, int damage);
	void SetToHitBonus(int toHitBonus);
	void SetDamage(int damage);

	int GetToHitBonus() { return m_ToHitBonus; }
	int GetDamage() { return m_AttackDamage; }
private:
	int m_ToHitBonus;
	int m_AttackDamage;
};

class SpellWeapon : public Weapon {
public:
	SpellWeapon(std::string name, std::string description, std::string rarity, double value, int toHitBonus, int damage);
};

class Armour : public Item {
public:
	Armour(std::string name, std::string description, std::string rarity, double value, int acBonus, int strRequirement);
	void SetACBonus(int acBonus);
	void SetStrenghtRequirement(int strRequirement);

	int GetACBonus() { return m_AcBonus; }
	int GetStrengthRequirement() { return m_StrengthRequirement; }
private:
	int m_AcBonus;
	int m_StrengthRequirement;
};
class Shield : public Item {
public:
	Shield(std::string name, std::string description, std::string rarity, double value, int acBonus, int strRequirement);
	void SetACBonus(int acBonus);
	void SetStrenghtRequirement(int strRequirement);

	int GetACBonus() { return m_AcBonus; }
	int GetStrengthRequirement() { return m_StrengthRequirement; }
private:
	int m_AcBonus;
	int m_StrengthRequirement;
};

class Healing : public Item {
public:
	Healing(std::string name, std::string description, std::string rarity, double value, int heal);
	void SetHpHealAmout(int heal);

	int GetHpHealAmount() { return m_HpHealAmount; }
private:
	int m_HpHealAmount;
};

class UseableItems : public Item {
public:
	UseableItems(std::string name, std::string description, std::string rarity, double value, std::string use);
private:
	std::string m_Use;
};

class Interactables {
public:
	Interactables(std::string name, std::string description, std::string interaction, bool empty);
	void SetInteractableName(std::string name);
	void SetInteractableDescription(std::string description);
	void SetInteractableInteraction(std::string interaction);
	void SetContainerEmpty(bool empty);

	bool GetContainerEmpty() { return m_Empty; }
	std::string GetInteractableName() { return m_Name; }
	std::string GetInteractableDescription() { return m_Description; }
	std::string GetInteractableInteraction() { return m_Interaction; }
private:
	std::string m_Name;
	std::string m_Description;
	std::string m_Interaction;
	bool m_Empty;
};