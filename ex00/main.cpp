#include "Conversion.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char **argv)
{
	Conversion conv;

	if (argc != 2)
		std::cout << "invalid number of arguments" << std::endl;
	else
		conv.startConversion(argv[1]);
	return 0;
}
