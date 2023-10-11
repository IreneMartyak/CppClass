#include <iostream>

//operator and methods ovverride
//virtual

class Character
{
	const char* name = "__None";
	int health = -1;
	int mana = -1;
protected:
	Character(const char* n, int h, int m):name{n},health{h},mana{m}
	{

	};
public:
	const char* getName(){ return name;}
	int getHealth(){return health;}
	virtual void atack() = 0;
};

class Warior : public Character
{
public:
	Warior():Character("Generic_Warior_Name", 40, 0)
	{
		std::cout << "Warior created: " << std::endl;
	}
	Warior(const char* n):Character(n, 40, 0)
	{
		std::cout << "Warior named: " << getName()  << " was created " << std::endl;
	}
	Warior(const char* n, int h, int m):Character(n, h, m)
	{
		std::cout << "Custom Warior was created" << std::endl;
	}
	
	//void swingSword(){}
	void atack(){std::cout << "Swing Sword" << std::endl;}
	
};

class Mage : public Character
{
public:
	Mage(const char* n):Character(n, 100, 50)
	{
		std::cout << "Mage created" <<  std::endl;
	}
	//void castSpell(){}
	void atack(){std::cout << "Cast Spell" << std::endl;}
	void warCry(){std::cout << "You shall NOT PASS !!" << std::endl;}

};

int main()
{
	Mage player1("Gendalf");
	Warior player2;


	//Warior player3("Gimly");
	//Warior player4("Aragorn", 50, 10);

	//std::cout << player3.getHealth() << std::endl;
	//std::cout << player4.getHealth() << std::endl;

	player1.atack();
	player2.atack();

	return 0;
}