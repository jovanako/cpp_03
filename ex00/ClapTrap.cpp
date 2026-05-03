/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 11:16:28 by jkovacev          #+#    #+#             */
/*   Updated: 2026/05/03 13:27:56 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap parametric constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & other)
	:   _name(other._name),
		_hitPoints(other._hitPoints),
		_energyPoints(other._energyPoints),
		_attackDamage(other._attackDamage) {
	std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called for name " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << _name
				  << " is dead and cannot attack!" << std::endl;
		return;
	}
	
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
		return;
	}

	this->_energyPoints--;
	
	std::cout << "ClapTrap " << _name << " attacks " << target 
			  << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already down!" << std::endl;
		return;
	}
	
	if (amount >= this->_hitPoints) {
		this->_hitPoints = 0;
	} else {
		this->_hitPoints -= amount;
	}

	std::cout << "ClapTrap " << _name << " takes " << amount
			  << " points of damage! Remaining HP: " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << _name
				  << " cannot repair itself because it is out of hit points!" << std::endl;
		return;
	}
	
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy left to be repaired!"
				  << std::endl;
		return;
	}

	this->_energyPoints--;
	
	this->_hitPoints += amount;

	std::cout << "ClapTrap " << _name << " regained " << amount
			  << " amount of hit points. Remaining HP: "
			  << this->_hitPoints << std::endl;
}