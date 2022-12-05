#include "Location.h"

Location::Location(std::string name, std::string shortDescription, std::string longDescription) :
	m_Name(name),
	m_ShortDescription(shortDescription),
	m_LongDescription(longDescription)
{}

void Location::DisplayLocation() {
	std::cout << std::endl << m_Name << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << m_LongDescription << std::endl;
	std::cout << "\nThe following exits are availabel:\n";
	for (std::vector<Location*>::const_iterator iter = m_Exits.begin();
		iter != m_Exits.end(); ++iter) {
		std::cout << "[" << m_Exits.begin() - iter << "]" << (*iter)->m_Name << std::endl;
	}
}

void Location::DisplayExits() {
	std::cout << "\nThe following exits are available:\n";
	for (std::vector<Location*>::const_iterator iter = m_Exits.begin();
		iter != m_Exits.end(); ++iter) {
		std::cout << "[" << m_Exits.begin() - iter << "] " << (*iter)->m_Name << std::endl;
	}
}

void Location::DisplayInteractableItems() {
	std::cout << "What would you like to interact with?\n";
	for (std::vector<Item*>::const_iterator iter = m_Items.begin();
		iter != m_Items.end(); ++iter) {
		std::cout << "[" << m_Items.begin() - iter << "] " << (*iter)->GetItemName() << std::endl;
	}
}