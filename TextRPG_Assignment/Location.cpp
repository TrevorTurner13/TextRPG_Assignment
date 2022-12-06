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
	std::cout << "[0] Back\n";
	for (std::vector<Location*>::const_iterator iter = m_Exits.begin();
		iter != m_Exits.end(); ++iter) {
		std::cout << "[" << iter - m_Exits.begin() + 1 << "] " << (*iter)->m_Name << std::endl;
	}
}

void Location::DisplayInteractables() {
	std::cout << "What would you like to interact with?\n";
	std::cout << "[0] Back\n";
	for (std::vector<Interactables*>::const_iterator iter = m_Interactables.begin();
		iter != m_Interactables.end(); ++iter) {
		std::cout << "[" << iter - m_Interactables.begin() + 1 << "] " << (*iter)->GetInteractableName() << std::endl;
	}
}

void Location::DisplayItems() {
	std::cout << "You find\n";
	for (std::vector<Item*>::const_iterator iter = m_Items.begin();
		iter != m_Items.end(); ++iter) {
		std::cout << "[" << iter - m_Items.begin() + 1 << "] " << (*iter)->GetItemName() << std::endl;
	}
}