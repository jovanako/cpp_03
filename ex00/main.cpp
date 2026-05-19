#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
	{
		std::cout << "--- TEST 1: Basic actions ---" << std::endl;
		
		ClapTrap bubble("Bubble");

		bubble.attack("a bobbly head");
		bubble.takeDamage(5);
		bubble.beRepaired(3);
	}

	{
		std::cout << "\n--- TEST 2: Energy depletion ---" << std::endl;

		ClapTrap tiredBob("TiredBob");

		for (int i = 0; i < 10; i++) {
			tiredBob.attack("the evil robot");
		}
		// 11th action: should print an error message instead of attacking
		tiredBob.attack("the evil robot again");
		tiredBob.beRepaired(5); // Should also fail
	}

	{
		std::cout << "\n--- TEST 3: Death logic ---" << std::endl;
		
		ClapTrap deadBob("Ghastly");

		deadBob.takeDamage(10); // 0 HP
		deadBob.attack("an enemy"); // should fail
		deadBob.beRepaired(10); //should fail
	}

	{
		std::cout << "\n--- TEST 4: Massive damage ---" << std::endl;
		ClapTrap punchBob("Punchy");

		punchBob.takeDamage(50); // HP is only 10. Should result in 0, not 4,294,967,286
		punchBob.beRepaired(10); // should fail because it's at 0 HP
	}

	{
		std::cout << "\n--- TEST 5: Canonical form ---" << std::endl;
		ClapTrap original("Original");
		original.takeDamage(5); // HP is now 5

		ClapTrap copy(original); // should have the name "Original" and 5 HP
		ClapTrap assigned;
		assigned = original; // HP shoudl also be 5
	}
}