(1)	Concept: Inheritance
	
	Inheritance allows ScavTrap to "inherit" all the attributes and
	functions of ClapTrap. This means a ScavTrap is a ClapTrap, but with
	different base stats and a new unique ability.

(2)	The ScavTrap Stats

	While ClapTrap was a fragile robot, ScavTrap is much tankier. You must
	initialize its attributes to these specific values:

	Attribute			ScavTrap Value			ClapTrap Value
	
	Name				Passed to constructor	Passed to constructor

	Hit Points			100						10

	Energy Points		50						10

	Attack Damage		20						0

(3) Constructor & Desctructor Chaining

	One of the most important technical requirements is showing the order
	of constructor and destruction:

	- Construction:	When you create a ScavTrap, the program must call the 
					ClapTrap constructor first, then the ScavTrap constructor.
	
	- Destruction:	When the object is destroyed, it happens in reverse -
					ScavTrap is destroyed first, then ClapTrap.
	
	- Requirement:	You must include log messages in both classes'
					constructors and destructors to prove this sequence
					occurs in your tests.

(4) Specialized Functions

	- attack():	Even though ClapTrap has an attack() function, ScavTrap must
				provide its own version because it needs to print a different
				message.
	
	- guardGate():	This is a brand new member function unique to ScavTrap.
					It simply displays a message informing the user that the
					robot is now in "Gate keeper mode".

(5) Implementation Strategy: Private to Protected

	In ex00, the ClaTrap.hpp had attributes under "private".

	- The Problem:	Derived classes (ScavTrap) cannot access "private"
					members of the parent.

	- The Solution:	You must change the ClapTrap attributes in ClapTrap.hpp
					to "protected". This keeps them hidden from the
					"outside world" but allows children classes like
					ScavTrap to use and modify them.

(6) Change ~ClapTrap() destructor to "virtual ~ClapTrap()"

	When you use inheritance, you might later try to delete a ScavTrap object
	using a ClapTrap* pointer. If the destructor isn't "virtual", the program
	will only call the ClapTrap destructor and skip the ScavTrap destructor,
	which can lead to memory issues or incomplete log messages. Since the
	subject requires specific destruction messages to show the chain, this
	ensures the ScavTrap destructor is always called first.

	Adding "virtual" to the ScavTrap destructor is a good habit. However,
	since the ClapTrap destructor is marked as "virtual" in its header, 
	ScavTrap's destructor is automatically virtual by inheritance, but
	explicitly writing it makes the code much more readable.

	*** Marking the attack() function of the ClapTrap class as "virtual" will
		allow the derived class's implementation to OVERRIDE it.

(7) Understanding the memory layout

	Because of "public ClapTrap", when you instantiate a ScavTrap, the memory
	allocated contains both the ClapTrap parts, and the ScavTrap additions.

**	When defining the constructor in .cpp, we explicitly call the parent
	constructor in the initialization list:

	example:

	ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
		this->_hitPoints = 100;
		this->_energyPoints = 50;
		this->attackDamage = 20;
		std::cout << "ScavTrap parametric constructor called" << std::endl;
	}

	how the constructor execution works:

	(1) Parent Initialization:
		ClapTrap(name) is called first. It initializes _hitPoints to 10,
		_energyPoints to 10, and _attackDamage to 0. It also prints its
		constructor message.

	(2) Derived Assignment:
		The code inside the ScavTrap curly braces {} then executes.
	
	(3) Updating values:
		Your code uses "this" to overwrite those initial 10/10/0 values
		with the ScavTrap specific values: 100, 50 and 20.
	
	(4) Final log:
		The ScavTrap constructor message is printed.

**	Access Requirements:
	For "this->_hitPoints" to work inside ScavTrap, the variables in 
	ClapTrap.hpp must be moved from "private" to "protected". Is they remain
	"private", the ScavTrap object "has" them, but the ScavTrap member
	functions aren't allowed to touch them directly.

**	Destruction order:
	Destruction happens in the exact reverse order: ScavTrap first, then
	ClapTrap.

