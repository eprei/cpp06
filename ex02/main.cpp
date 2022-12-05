#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base*	generate(void)
{
	Base*		basePtr = NULL;
	Base*		array[3] = { new A , new B, new C};
	std::string	str[3] = { "A" , "B", "C" };
	int			randNum;
	static int	addSeed = 1;

	srand (time(NULL) + addSeed);
	randNum = rand() % 3;
	for (int i = 0; i < 3; i++)
	{
		if (randNum == i)
		{
			basePtr = array[i];
			std::cout << "An instance of class " << str[i] << " has been created" << std::endl;
		}
		else
			delete array[i];
	}
	addSeed += rand();
	return (basePtr);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "the object is of type Class A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "the object is of type Class B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "the object is of type Class C" << std::endl;
	else
		std::cout << "the object does not belong to any of the existing classes" << std::endl;
	return ;
}

void	identify(Base& p)
{
	try
	{
		A&	alfa = dynamic_cast<A&>(p);
		(void) alfa;
		std::cout << "the object is of type Class A" << std::endl;
	}
	catch (const std::exception& e){}
	try
	{
		B& beta = dynamic_cast<B&>(p);
		(void) beta;
		std::cout << "the object is of type Class B" << std::endl;
	}
	catch (const std::exception& e){}
	try
	{
		C& gamma = dynamic_cast<C&>(p);
		(void) gamma;
		std::cout << "the object is of type Class C" << std::endl;
	}
	catch (const std::exception& e){}
	return ;
}

int main(void)
{
	Base *randomBase;

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "________\tRound " << i + 1 << "\t\t________" << std::endl;

		std::cout << std::endl;
		randomBase	= generate();
		Base& basRef = *randomBase;
		std::cout << std::endl << "Identify by pointer: ";
		identify(randomBase);
		std::cout << std::endl;

		std::cout << "Identify by reference: ";
		identify(basRef);
		std::cout << std::endl;

		delete randomBase;
	}

	return 0;
}
