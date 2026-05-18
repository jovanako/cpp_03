*	The difference between applying the keyword 'virtual'
	to member functions and the destructor is because 
	member functions and destructors have different
	fundamental behaviors in an inheritance hierarchy.

(1)	The attack() function (method overriding)

	When you mark a function attack() as virtual, you are
	enabling POLYMORPHISM.

	*	The goal: you want the most 'specific' version of
		the behavior.
	
	*	The logic: if you have a ClapTrap* pointing to a 
		ScavTrap, and you call attack(), the virtual table
		(vtable) directs the program to ScavTrap::attack().
	
	*	Why only one? in C++, when a derived class overrides
		a virtual function, it replaces the base class
		implementation for that instance. You generally only
		want the robot to perform one attack animation/logic
		at a time.
	
(2)	The destructor (cleanup chaining)

	The destructor is a special case. Even when it is
	'virtual', it follows the rule of DESTRUCTION CHAINING.

	*	The goal: ensure every layer of the 'onion' is
		peeled back and cleaned up.
	
	*	The logic: when you delete a ScavTrap via a ClapTrap*,
		the virtual keyword ansures the program starts at the
		ScavTrap destructor
	
	*	The chain: once the ScavTrap destructor finishes, C++
		automatically calls the base ClapTrap destructor
		immediately after.
	
	*	Why both? a ScavTrap object contains a ClapTrap inside
		it. If you only called the ScavTrap destructor, the
		memory and attributes belonging to the ClapTrap part
		might not be cleaned up properly, leading to leaks.