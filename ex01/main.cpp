#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
	{
		std::cout << "--- TEST 1: Construction/Destruction Chaining ---" << std::endl;
		ScavTrap scav("Serena");
	}

	{
		std::cout << "\n--- TEST 2: ScavTrap Stats and Attack ---" << std::endl;
		ScavTrap serena("Serena");

		// ScavTrap starts with 50 energy
		// It should deal 20 damage
		serena.attack("a bad guy");

		serena.takeDamage(30); // Should have 70 HP left
		serena.beRepaired(20); // Should have 90 HP left
	}

	{
		std::cout << "\n--- TEST 3: Special Ability ---" << std::endl;
		ScavTrap guard("Guary");
		guard.guardGate(); // Should print the Gate keeper mode message
	}

	{
		std::cout << "\n--- TEST 4: Pointer Chaining ---" << std::endl;
		ClapTrap* poly = new ScavTrap("Poly");

		poly->attack("the enemy"); // Will call ClapTrap::attack unless you made it virtual

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

