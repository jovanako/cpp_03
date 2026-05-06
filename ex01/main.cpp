#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
	// basic functionality test
	{
		std::cout << "--- TEST 1: Basic actions ---" << std::endl;
		
		ClapTrap trappy("Trappy");

		trappy.attack("a training dummy");
		trappy.takeDamage(5);
		trappy.beRepaired(3);
	}

	// energy depletion test
	{
		std::cout << "\n--- TEST 2: Energy depletion ---" << std::endl;

		ClapTrap tiredBot("Exhausto");

		for (int i = 0; i < 10; i++) {
			tiredBot.attack("the air");
		}
		// 11th action: should print an error message instead of attacking
		tiredBot.attack("the air again");
		tiredBot.beRepaired(5); // Should also fail
	}

	// death/zero HP test
	{
		std::cout << "\n--- TEST 3: Death logic ---" << std::endl;
		
		ClapTrap ghost("Ghosty");

		ghost.takeDamage(10); // 0 HP
		ghost.attack("a target"); // should fail
		ghost.beRepaired(10); //should fail
	}

	// Over-damage (underflow) prevention
	{
		std::cout << "\n--- TEST 4: Massive damage ---" << std::endl;
		ClapTrap tank("Tanky");

		tank.takeDamage(50); // HP is only 10. Should result in 0, not 4,294,967,286
		tank.beRepaired(10); // should fail because it's at 0 HP
	}

	// orthodox canonical form test
	{
		std::cout << "\n--- TEST 5: Canonical form ---" << std::endl;
		ClapTrap original("Original");
		original.takeDamage(5); // HP is now 5

		ClapTrap copy(original); // should have the name "Original" and 5 HP
		ClapTrap assigned;
		assigned = original; // should also have 5 HP
	}
}