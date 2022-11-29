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
}