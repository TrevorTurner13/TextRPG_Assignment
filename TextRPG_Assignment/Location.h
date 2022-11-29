#pragma once


#include <iostream>
#include <string>
#include <vector>

class Location {
public: 
	Location(std::string name, std::string shortDescription, std::string longDescription);
	void Display();
public:
	std::string m_Name;
	std::string m_ShortDescription;
	std::string m_LongDescription;

	// list of exits
	std::vector<Location*> m_Exits;

	// list of interactable items



};