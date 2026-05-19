#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap() {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Parametric Constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & other) : ClapTrap(other) {
	std::cout << "ScavTrap Copy Constructor called for " << _name << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & other) {
	std::cout << "ScavTrap Copy Assignment Operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called for " << _name << std::endl;
}

void ScavTrap::attack(const std::string & target) {
	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << _name
				  << " is dead and cannot attack!" << std::endl;
		return;
	}

	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << _name 
				  << " has no energy left to attack!" << std::endl;
		return;
	}
	
	this->_energyPoints--;

	std::cout << "ScavTrap " << _name << " attacks " << target
			  << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << _name
				  << " is dead and cannot guard gate!" << std::endl;
		return;
	}

	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << _name 
				  << " has no energy left to guard gate!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}