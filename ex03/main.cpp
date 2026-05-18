#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
    std::cout << "--- Creating DiamondTrap ---" << std::endl;
    DiamondTrap dt("Sparky");

    std::cout << "\n--- Identity Test ---" << std::endl;
    dt.whoAmI(); // Should print Sparky and Sparky_clap_name

	std::cout << "\n--- Deep Copy Test ---" << std::endl;
	DiamondTrap original("Original");
	DiamondTrap clone("Clone");

	clone = original;
	clone.whoAmI(); // Should correctly transition to Original and Original_clap_name

    std::cout << "\n--- Capability Tests ---" << std::endl;
    dt.attack("the bad guy"); // Should use ScavTrap's attack style
    dt.guardGate();          // Inherited from ScavTrap
    dt.highFivesGuys();      // Inherited from FragTrap (fix typo to 'highFivesGuys' if needed)

    std::cout << "\n--- Destructors ---" << std::endl;
    return 0;
}

