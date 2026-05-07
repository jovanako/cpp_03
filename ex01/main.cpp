#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
	{
		std::cout << "--- TEST 1: Construction/Destruction Chaining ---" << std::endl;
		ScavTrap scav("Serena");
		// Watch output for:
		// 1. ClapTrap Constructor
		// 2. ScavTrap Constructor
	}
	// Watch output for:
	// 1. ScavTrap Destructor
	// 2. ClapTrap Destructor

	{
		std::cout << "\n--- TEST 2: ScavTrap Stats and Attack ---" << std::endl;
		ScavTrap serena("Serena");

		// ScavTrap starts with 50 energy
		// It should deal 20 damage
		serena.attack("a dangerous bandit");

		// Use takeDamage to see if it survives more than 10 HP
		serena.takeDamage(30); // Should have 70 HP left
		serena.beRepaired(20); // Should have 90 HP left
	}

	{
		std::cout << "\n--- TEST 3: Special Ability ---" << std::endl;
		ScavTrap guard("GuardBot");
		guard.guardGate(); // Should print the Gate keeper mode message
	}

	{
		std::cout << "\n--- TEST 4: Pointer Chaining ---" << std::endl;
		ClapTrap* poly = new ScavTrap("PolyBot");

		poly->attack("the void"); // Will call ClapTrap::attack unless you made it virtual

		delete poly; // MUST call both destructors because of 'virtual ~ClapTrap()'
	}

	{
		std::cout << "\n--- TEST 5: Derived Copying ---" << std::endl;
		ScavTrap original("Original");
		original.guardGate();

		ScavTrap copy(original);
		ScavTrap assigned("Temporary");
		assigned = original;
		// Expected values for ScavTrap: HP: 100, EP: 50, AD: 20
	}
}

