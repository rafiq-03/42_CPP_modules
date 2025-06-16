#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <iostream>
# include <fstream>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;


		void validate(std::string &line);
		void	validateDate(std::string date);
		float	validateValue(std::string value);


	public:
		BitcoinExchange(void); // Default constructor
		void exchange(std::string file);// exchange
		BitcoinExchange(const BitcoinExchange& obj); // Copy constructor
		BitcoinExchange&	operator=(const BitcoinExchange& obj); // Copy assigment operator
		~BitcoinExchange(); // Destructor

};

#endif
