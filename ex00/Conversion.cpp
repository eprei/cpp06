#include "Conversion.hpp"
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip>

Conversion::Conversion(void) : _vChar(' '), _vInt(0), _vFloat(0), _vDouble(0.0), _sInt(" "), _sFloat(" "), _sDouble(" ")
{
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Conversion::~Conversion(void)
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Conversion::Conversion( Conversion const & src )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Conversion &	Conversion::operator=( Conversion const & rhs )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_vChar = rhs._vChar;
		this->_vInt = rhs._vInt;
		this->_vFloat = rhs._vFloat;
		this->_vDouble = rhs._vDouble;
	}
	return *this;
}

bool		Conversion::searchChar(std::string argv)
{
	if (argv.size() > 1)
		_sChar = "Non displayable";
	if (argv.size() == 1 && isprint(argv[0]))
		return true;
	else
		return false;
}

bool		Conversion::searchInt(std::string argv)
{
	(void) argv;
	if (0)
		return true;
	else
		return false;
}

bool		Conversion::searchFloat(std::string argv)
{
	if (argv[argv.size() - 1] == 'f') // add other conditions need a point . and no letters and + o - at the begening
		return true;
	else
		return false;
}

bool		Conversion::searchDouble(std::string argv)
{
	(void) argv;
	if (argv.find_first_of(".") == argv.find_last_of(".") && argv.find_first_of(".")
		!= static_cast<unsigned long>(-1) && (argv[argv.size() - 1] != 'f'))
		return true;
	else
		return false;
}

bool		Conversion::searchNan(std::string argv)
{
	if (argv.compare("nan") == 0)
		return true;
	else
		return false;
}

void			Conversion::execChar(std::string argv)
{
	std::cout << "exec char" << std::endl;
	_vChar = argv[0];
	_vInt = static_cast<int>(_vChar);
	_vFloat = static_cast<float>(_vChar);
	_vDouble = static_cast<double>(_vChar); // has to print the .0 at the end
	printResult();
}

void			Conversion::execInt(std::string argv)
{
	(void) argv;
	std::cout << "exec int" << std::endl;
	printResult();
}

void			Conversion::execFloat(std::string argv)
{
	std::cout << "exec float" << std::endl;
	std::string str =  argv.substr(0, argv.length());
	_vFloat  = atof(str.c_str());
	printResult();
}

void			Conversion::execDouble(std::string argv)
{
	std::cout << "exec double" << std::endl;
	std::string str =  argv.substr(0, argv.length());
	_vDouble  = atof(str.c_str());
	_vChar = static_cast<char>(_vDouble);
	_vInt = static_cast<int>(_vDouble);
	_vFloat = static_cast<float>(_vDouble);
	printResult();
}

void			Conversion::execNan(std::string argv)
{
	(void)argv;
	std::cout << "exec Nan" << std::endl;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan"<< std::endl;
}

void		Conversion::startConversion(char* argv)
{
	bool (Conversion::*search[5]) (std::string argv) = { &Conversion::searchChar , &Conversion::searchInt, &Conversion::searchFloat , &Conversion::searchDouble , &Conversion::searchNan};
	void (Conversion::*execute[5]) (std::string argv) = { &Conversion::execChar , &Conversion::execInt , &Conversion::execFloat , &Conversion::execDouble , &Conversion::execNan };

	for (int i = 0; i < 5; i++)
	{
		if ((this->*search[i])(argv))
			(this->*execute[i])(argv);
	}
}

void		Conversion::printResult( void ) const
{
	std::cout << "char: " << _vChar << std::endl;
	std::cout << "int: " << _vInt << std::endl;
	std::cout << "float: " << _vFloat << "f" << std::endl;
	std::cout << "double: " << _vDouble << std::endl;
}
