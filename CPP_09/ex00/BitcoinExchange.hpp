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

		void	validate(std::string &line);
		void	validateDate(std::string date);
		float	validateValue(std::string value);

	public:
		BitcoinExchange(void);
		void exchange(std::string file);
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange&	operator=(const BitcoinExchange& obj);
		~BitcoinExchange();

};

#endif
