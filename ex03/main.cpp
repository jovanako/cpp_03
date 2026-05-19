#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
    std::cout << "--- Creating DiamondTrap ---" << std::endl;
    DiamondTrap diamond("Shiny");

    std::cout << "\n--- Identity Test ---" << std::endl;
    diamond.whoAmI(); // Should print Shiny and Shiny_clap_name

	std::cout << "\n--- Deep Copy Test ---" << std::endl;
	DiamondTrap original("Original");
	DiamondTrap clone("Clone");

	clone = original;
	clone.whoAmI(); // Should print Original and Original_clap_name

    std::cout << "\n--- Capability Tests ---" << std::endl;
    diamond.attack("the bad guy"); // Should use ScavTrap's attack style
    diamond.guardGate();          // Inherited from ScavTrap
    diamond.highFivesGuys();      // Inherited from FragTrap

    std::cout << "\n--- Destructors ---" << std::endl;
    return 0;
}

