#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() :
	ClapTrap("Unknown_clap_name"),
	ScavTrap(),
	FragTrap()
{
	this->_name = "Unknown";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;

	ClapTrap::_name = "Unknown_clap_name";

	std::cout << "DiamondTrap Default Constructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;

	ClapTrap::_name = name + "_clap_name";

	std::cout << "DiamondTrap Parametric Constructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap & other) :
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other)
{
	*this = other;

	std::cout << "DiamondTrap Copy Constructor called for " << this->_name << std::endl;
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap & other) {
	std::cout << "DiamondTrap Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called for " << this->_name << std::endl;
}

void DiamondTrap::attack(const std::string & target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "Hello, I am DiamondTrap: "
			  << this->_name
			  << " and my ClapTrap name is: "
			  << ClapTrap::_name
			  << std::endl;
}