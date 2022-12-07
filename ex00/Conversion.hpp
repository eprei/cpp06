#ifndef CONVERSION_HPP
# define CONVERSION_HPP
# include <iostream>

# define STR_DEFAULT_VALUE "default string"

class Conversion
{
	public:

		Conversion( void );
		Conversion( Conversion const & src );
		~Conversion( void );

		Conversion &	operator=( Conversion const & rhs );

		void			startConversion(char* argv);

		bool			checkArgv(std::string argv);

		bool			checkNan(std::string argv);
		bool			checkNanf(std::string argv);
		bool			checkPlusInf(std::string argv);
		void			handlePlusInf(std::string argv);
		bool			checkMoinsInf(std::string argv);
		void			handleMoinsInf(std::string argv);
		bool			checkPlusInff(std::string argv);
		void			handlePlusInff(std::string argv);
		bool			checkMoinsInff(std::string argv);
		void			handleMoinsInff(std::string argv);

		bool			searchChar(std::string argv);
		void			execChar(std::string argv);
		bool			searchFloat(std::string argv);
		void			execFloat(std::string argv);
		bool			searchDouble(std::string argv);
		void			execDouble(std::string argv);
		bool			searchInt(std::string argv);
		void			execInt(std::string argv);

		void			printResult( void ) const;
		void			printImposible(void) const;

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
