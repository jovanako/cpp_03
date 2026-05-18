Introducing MULTIPLE INHERITANCE and the infamous
DIAMOND PROBLEM. You are tasked with creating a
DiamondTrap class that is a hybrid of both ScavTrap and
FragTrap.

**	THE DIAMOND PROBLEM

	The diamond problem is a classic ambiguity in object-oriented
	programming that occurs when a class inherits from two separate
	classes, both of which share a common parent class. The 
	inheritance diagram creates a diamond shape, causing ambiguity
	over which parent class's properties or methods should be 
	inherited.
	
	THE CORE PROBLEM:

	Imagine a base class A. Classes B and C both inherit from A.
	If a fourth class D inherits from both B and C, the inheritance
	chain looks like this:

	(1)	METHOD AMBIGUITY: If A defines a method, and both B and C
		override it in different ways, the compiler gets comfused.
		When you call that method on an instance of D, it cannot
		determine whether to use B's version or C's version.
	
	(2)	DATA REDUNDANCY: D is created with two separate copies of
		the original A class (once via B and once via C), leading to
		wasted memory and potential conflicts in state tracking.

	To solve this, C++ uses VIRTUAL INHERITANCE:

	ScavTrap: class ScavTrap : virtual public ClapTrap {};
	FragTrap: class FragTrap : virtual public ClapTrap {};

	This instructs the compiler to share a single instance of
	ClapTrap inside DiamondTrap, effectively removing ambiguity and
	redundancy.

**	THE NAME ISSUE

	VARIABLE SHADOWING

	Variable Shadowing occurs when a variable declared within a specific
	scope (like a derived class or local block) has the same name as a
	variable declared in an outer scope (like a base class or a global
	scope).

	When this happens, the 'inner' variable shadows or hides the 'outer' one. If you reference that variable name, the compiler will default to the version closest to the current scope.

	-	THE BASE: ClapTrap has a protected attribute named '_name'
	-	THE DERIVED: DiamondTrap also has a private attribute named '_name'
	-	THE CONFLICT: when you are inside a DiamondTrap member function
		and type '_name', the compiler assumes you mean
		'DiamondTrap::_name', not the one inherited from ClapTrap.
	
	This concept allows us to recognize that two variables with the same
	name coexist in the same object.
	Using the scope resolution operator, we can "reach through" the shadow.

	*	Difference between SHADOWING and OVERRIDING:
		-	Overriding applies to virtual functions - the base version is
			replaced by the derived version for that object.
		-	Shadowing applies to data members (variables). Both variables
			exist in memory simultaneously; one just makes the other one 
			harder to see.

	In the default constructor declaration, we write:

	DiamondTrap::DiamondTrap() : 
    ClapTrap("default_clap_name"), 
    ScavTrap(), 
    FragTrap() 
	{
    	this->_name = "default";
    	this->_hitPoints = 100;    // From FragTrap
	    this->_energyPoints = 50;   // From ScavTrap
    	this->_attackDamage = 30;   // From FragTrap
    	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	}

	The DiamondTrap is required to have two distinct names stored in two
	different places.

	The DiamondTrap has a private attribute '_name', while it also 
	inherits the '_name' attribute from the ClapTrap base class. The
	subject specifically requires them to be different to prove you
	can manage variable shadowing and multiple inheritance.