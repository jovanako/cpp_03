#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap() {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Parametric Constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap & other) : ClapTrap(other) {
	std::cout << "FragTrap Copy Constructor called for " << _name << std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap & other) {
	std::cout << "FragTrap Copy Assignment Operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called for " << _name << std::endl;
}

void FragTrap::attack(const std::string & target) {
	if (this->_hitPoints == 0) {
		std::cout << "FragTrap " << _name
				  << " is dead and cannot attack!" << std::endl;
		return;
	}

	if (this->_energyPoints == 0) {
		std::cout << "FragTrap " << _name
				  << " has no energy left to attack!" << std::endl;
		return;
	}

	this->_energyPoints--;

	std::cout << "FragTrap " << _name << " attacks " << target
			  << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name
			  << " wants to celebrate with a high five!" << std::endl;
}