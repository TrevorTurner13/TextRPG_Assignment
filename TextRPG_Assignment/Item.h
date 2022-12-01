#pragma once

#include<iostream>
#include <string>
#include <vector>
#include <iomanip>

class Item {
public:
	Item(std::string name, std::string description, std::string rarity, double value);
protected:
	std::string m_Name;
	std::string m_Description;
	std::string m_Rarity;
	int m_Value;
};

class Weapon: public Item {
public:
	Weapon(std::string name, std::string description, std::string rarity, double value, int toHitBonus, int damage);
private:
	int m_ToHitBonus;
	int m_AttackDamage;
};

class Armor : public Item {
public:
	Armor(std::string name, std::string description, std::string rarity, double value, int acBonus, int strRequirement);
private:
	int m_AcBonus;
	int m_StrengthRequirement;
};

class HealingPotion : public Item {
public:
	HealingPotion(std::string name, std::string description, std::string rarity, double value, int heal);
private:
	int m_HpHealAmount;
};

class UseableItems : public Item {
public:
	UseableItems(std::string name, std::string description, std::string rarity, double value, std::string use);
private:
	std::string m_Use;
};