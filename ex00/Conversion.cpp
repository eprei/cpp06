#include "Conversion.hpp"
#include <ctype.h>
#include <stdlib.h>
#include <iomanip>
#include <limits.h>
#include <string>
#include <iostream>
#include <sstream>

Conversion::Conversion(void) : _vChar(' '), _vInt(0), _vFloat(0), _vDouble(0.0),
_sChar(STR_DEFAULT_VALUE), _sInt(STR_DEFAULT_VALUE), _sFloat(STR_DEFAULT_VALUE), _sDouble(STR_DEFAULT_VALUE)
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
		this->_sChar = rhs._sChar;
		this->_sInt = rhs._sInt;
		this->_sFloat = rhs._sFloat;
		this->_sDouble = rhs._sDouble;
	}
	return *this;
}

bool		Conversion::searchChar(std::string argv)
{
	if (argv.size() != 1 || isnumber(argv[0]))
		return false;
	execChar(argv);
	return true;
}

bool		Conversion::searchInt(std::string argv)
{
	for(unsigned int i = 0; i < argv.size(); i++)
	{
		if ((!isdigit(argv[i]) && i > 0) || (i == 0 && argv[0] != '+' && argv[0] != '-' && !isdigit(argv[i])))
			return false;
	}
	execInt(argv);
	return true;
}

bool		Conversion::searchFloat(std::string argv)
{
	if (argv[argv.size() - 1] == 'f'&& argv.find_first_of(".") == argv.find_last_of(".") && argv.find_first_of(".")
		!= static_cast<unsigned long>(-1) && argv.find_first_of(".") < argv.size() - 2 && argv.find_first_of(".") > 0)
	{
		execFloat(argv);
		return true;
	}
	return false;
}

bool		Conversion::searchDouble(std::string argv) //check ++ ---+-+-++
{
	int	checkDigits = 0;

	for (unsigned int i = 0; i < argv.size(); i++)
	{
		if (!isnumber(argv[i]) && argv[i] != '.' && i > 0)
			checkDigits += 1;
	}
	if (argv.find_first_of(".") == argv.find_last_of(".") && argv.find_first_of(".")
		!= static_cast<unsigned long>(-1) && checkDigits == 0)
	{
		execDouble(argv);
		return true;
	}
	return false;
}

bool		Conversion::checkNan(std::string argv)
{
	if (argv.compare("nan") == 0)
	{
		std::cout << "exec Nan" << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: nan" << std::endl;
		std::cout << std::setprecision(1);
		std::cout << std::fixed;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan"<< std::endl;
		return true;
	}
	return false;
}

bool		Conversion::checkNanf(std::string argv)
{
	if (argv.compare("nanf") == 0)
	{
		std::cout << "exec Nanf" << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: nan" << std::endl;
		std::cout << std::setprecision(1);
		std::cout << std::fixed;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan"<< std::endl;
		return true;
	}
	return false;
}

bool		Conversion::checkPlusInf(std::string argv)
{
	if (argv.compare("+inf") == 0 || argv.compare("inf") == 0)
	{
		std::cout << "exec +inf" << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: +inf" << std::endl;
		std::cout << std::setprecision(1);
		std::cout << std::fixed;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf"<< std::endl;
		return true;
	}
	return false;
}

bool		Conversion::checkPlusInff(std::string argv)
{
	if (argv.compare("+inff") == 0 || argv.compare("inff") == 0)
	{
		std::cout << "exec +inff" << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: +inf" << std::endl;
		std::cout << std::setprecision(1);
		std::cout << std::fixed;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf"<< std::endl;
		return true;
	}
	return false;
}

bool		Conversion::checkMoinsInf(std::string argv)
{
	if (argv.compare("-inf") == 0)
	{
		std::cout << "exec -inf" << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: -inf" << std::endl;
		std::cout << std::setprecision(1);
		std::cout << std::fixed;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf"<< std::endl;
		return true;
	}
	return false;
}

bool		Conversion::checkMoinsInff(std::string argv)
{
	if (argv.compare("-inff") == 0)
	{
		std::cout << "exec -inff" << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: -inf" << std::endl;
		std::cout << std::setprecision(1);
		std::cout << std::fixed;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf"<< std::endl;
		return true;
	}
	return false;
}

void			Conversion::execChar(std::string argv)
{
	std::cout << "exec char" << std::endl;
	if (!isprint(argv[0]))
		_sChar = "Non displayable";
	else
		_vChar = argv[0];
	_vInt = static_cast<int>(_vChar);
	_vFloat = static_cast<float>(_vChar);
	_vDouble = static_cast<double>(_vChar);
	printResult();
}

void			Conversion::execInt(std::string argv)
{
	std::cout << "exec int" << std::endl;
	double	tmp;

	std::istringstream is(argv.substr(0, argv.length()));
	is >> tmp;
	if (INT_MIN > tmp || tmp > INT_MAX)
		_sInt = "impossible";
	else
		_vInt = tmp;
	if (!isprint(static_cast<int>(tmp)))
		_sChar = "Non displayable";
	else
		_vChar = static_cast<char>(tmp);
	_vFloat = static_cast<float>(tmp);
	_vDouble = static_cast<double>(tmp);
	printResult();
}

void			Conversion::execFloat(std::string argv)
{
	std::istringstream is(argv.substr(0, argv.length() - 1));
	std::cout << "exec float" << std::endl;

	is >> _vFloat;
	if (!isprint(static_cast<int>(_vFloat)))
		_sChar = "Non displayable";
	else
		_vChar = static_cast<char>(_vFloat);
	if (INT_MIN > static_cast<double>(_vFloat) || static_cast<double>(_vFloat) > INT_MAX)
		_sInt = "impossible";
	else
		_vInt = static_cast<int>(_vFloat);
	_vDouble = static_cast<double>(_vFloat);
	printResult();
}

void			Conversion::execDouble(std::string argv)
{
	std::cout << "exec double" << std::endl;
	std::istringstream is(argv.substr(0, argv.length()));
	is >> _vDouble;
	if (!isprint(static_cast<int>(_vDouble)))
		_sChar = "Non displayable";
	else
		_vChar = static_cast<char>(_vDouble);
	if (INT_MIN > (_vDouble) || (_vDouble) > INT_MAX)
		_sInt = "impossible";
	else
		_vInt = static_cast<int>(_vDouble);
	_vFloat = static_cast<float>(_vDouble);
	printResult();
}

bool		Conversion::checkArgv(std::string argv) // add ++ -- condition at the begining // isinf function
{
	int checkAlpha = 0;

	for (unsigned long i = 0; i < argv.size() - 1; i++)
		checkAlpha += isalpha(argv[i]);
	if ((checkAlpha != 0 && argv.size() > 1) || (isalpha(argv.size()) && argv[argv.size()] != 'f'))
	{
		std::cout << "exec impossible checkArgv" << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << std::setprecision(1);
		std::cout << std::fixed;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible"<< std::endl;
		return true;
	}
	else
		return false;
}

void		Conversion::printImposible(void) const
{
	std::cout << "exec impossible" << std::endl;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << std::setprecision(1);
	std::cout << std::fixed;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible"<< std::endl;
}

void		Conversion::startConversion(char* argv)
{
	bool (Conversion::*checkSpecialCases[7]) (std::string argv) = { &Conversion::checkNan , &Conversion::checkNanf , &Conversion::checkPlusInf , &Conversion::checkMoinsInf , &Conversion::checkPlusInff , &Conversion::checkMoinsInff , &Conversion::checkArgv };
	bool (Conversion::*search[4]) (std::string argv) = { &Conversion::searchChar , &Conversion::searchFloat , &Conversion::searchDouble , &Conversion::searchInt };

	for (int i = 0; i < 7; i++)
	{
		if ((this->*checkSpecialCases[i])(argv))
			return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if ((this->*search[i])(argv))
			return ;
	}
	printImposible();
}

void		Conversion::printResult( void ) const
{
	if (_sChar == STR_DEFAULT_VALUE)
		std::cout << "char: '" << _vChar << "'" << std::endl;
	else
		std::cout << "char: " << _sChar << std::endl;
	if (_sInt == STR_DEFAULT_VALUE)
		std::cout << "int: " << _vInt << std::endl;
	else
		std::cout << "int: " << _sInt << std::endl;
	std::cout << std::setprecision(1);
	std::cout << std::fixed;
	if (_sFloat == STR_DEFAULT_VALUE)
		std::cout << "float: " << _vFloat << "f" << std::endl;
	else
		std::cout << "float: " << _sFloat << std::endl;
	if (_sDouble == STR_DEFAULT_VALUE)
		std::cout << "double: " << _vDouble << std::endl;
	else
		std::cout << "double: " << _sDouble << std::endl;
}
