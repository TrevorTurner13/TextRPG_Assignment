#include "Location.h"

Location::Location(std::string name, std::string shortDescription, std::string longDescription) :
	m_Name(name),
	m_ShortDescription(shortDescription),
	m_LongDescription(longDescription)
{}

void Location::Display() {
	std::cout << m_Name << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << m_ShortDescription << std::endl;
	std::cout << "\nThe following exits are availabel:\n";
	for (std::vector<Location*>::const_iterator iter = m_Exits.begin();
		iter != m_Exits.end(); ++iter) {
		std::cout << (*iter)->m_Name << std::endl;
	}
}
