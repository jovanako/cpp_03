#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
	{
		std::cout << "--- TEST 1: FragTrap Chaining ---" << std::endl;
		FragTrap frag("Fragward");
	}

	{
		std::cout << "\n--- TEST 2: FragTrap Stats ---" << std::endl;
		FragTrap frag("Boxer");

		frag.attack("a punching bag"); // Should show 30 damage
		frag.takeDamage(50); // Should have 50/100 HP left
		frag.beRepaired(20); // Should have 70/100 HP left
	}

	{
		std::cout << "\n--- TEST 3: High Fives ---" << std::endl;
		FragTrap frag("Friendy");
		frag.highFivesGuys();
	}

	{
		std::cout << "\n--- TEST 4: FragTrap Copying ---" << std::endl;
		FragTrap original("Original");
		FragTrap copy(original);

		copy.takeDamage(99);
		original.highFivesGuys();
	}

	{
		std::cout << "\n--- TEST 5: The Robot Army ---" << std::endl;
		ClapTrap clap("ClapBot");
		ScavTrap scav("ScavBot");
		FragTrap frag("FragBot");

		clap.attack("Enemy One"); // 0 damage
		scav.attack("Enemy Two"); // 20 damage
		frag.attack("Enemy Three"); // 30 damage
	}
}

