#ifndef CONVERSION_HPP
# define CONVERSION_HPP
#include <iostream>

class Conversion
{
	public:

		Conversion( void );
		Conversion( Conversion const & src );
		~Conversion( void );

		Conversion &	operator=( Conversion const & rhs );

		void			startConversion(char* argv);
		bool			searchChar(std::string argv);
		bool			searchInt(std::string argv);
		bool			searchFloat(std::string argv);
		bool			searchDouble(std::string argv);
		bool			searchNan(std::string argv);
		void			execChar(std::string argv);
		void			execInt(std::string argv);
		void			execFloat(std::string argv);
		void			execDouble(std::string argv);
		void			execNan(std::string argv);
		void			printResult( void ) const;

	private:

		char		_vChar;
		int			_vInt;
		float		_vFloat;
		double		_vDouble;
		std::string	_sChar;
		std::string	_sInt;
		std::string	_sFloat;
		std::string	_sDouble;
};

#endif
