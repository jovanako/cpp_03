#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// ScavTrap inherits from ClapTrap
class ScavTrap : public ClapTrap {
	public:
		// Orthodox Canonical Form
		ScavTrap();										// Default constructor
		
		ScavTrap(std::string name);						// Parametric constructor
		
		ScavTrap(const ScavTrap & other);				// Copy constructor
		
		ScavTrap & operator=(const ScavTrap & other);	// Copy assignment operator
		
		virtual ~ScavTrap();							// Destructor

		// Overriding the base class attack
		void attack(const std::string & target);
		
		// ScavTrap's unique ability
		void guardGate();
};

#endif