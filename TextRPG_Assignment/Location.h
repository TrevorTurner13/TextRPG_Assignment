#pragma once


#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Enemy.h"

class Location {
public: 
	Location(std::string name, std::string shortDescription, std::string longDescription);
	void DisplayLocation();
	void DisplayExits();
	void DisplayInteractables();
	void DisplayItems();
public:
	std::string m_Name;
	std::string m_ShortDescription;
	std::string m_LongDescription;

	// list of exits
	std::vector<Location*> m_Exits;

	// list of interactable items
	std::vector<Interactables*> m_Interactables;

	// list of items that you can pick up
	std::vector<Item*> m_Items;
	// list of monsters/enemies
	std::vector<Enemy*> m_Enemies;
	// list of npcs

};