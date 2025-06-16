#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	// std::cout << "BitcoinExchange Default constructor called" << std::endl;

	std::ifstream csv("data.csv");
	if (!csv.is_open())
		throw std::runtime_error("Error: could not open file");
	std::string line;
	std::getline(csv, line);// skip first line;
	while (std::getline(csv, line)){
		size_t pos = line.find(",");
		if (pos == line.npos)
			throw std::runtime_error("Error: bad input");
		std::string key(line.substr(0, pos));
		line.erase(0, pos + 1);
		float value = std::strtod(line.c_str(), NULL);
		_data[key] = value;
	}
}

bool	isNumber(std::string &nbr){
	for (size_t i = 0; i < nbr.size(); i++){
		if (!isdigit(nbr[i]) && nbr[i] != ' ' && nbr[i] != '+' && nbr[i] != '-')
			return false;
	}
	return true;
}

void	BitcoinExchange::validateDate(std::string date){

	size_t pos = date.find("-");
	int value[3];//store date values
	int i = 0;
	std::string val;
	while (pos != date.npos){

		val = date.substr(0, pos);
		if(!isNumber(val))
			throw std::runtime_error("Error: bad input => " + date);
		value[i++] = std::strtod(val.c_str(), NULL);
		date.erase(0, pos + 1);
		pos = date.find("-");
	}
	value[i++] = std::strtod(date.c_str(), NULL);
	if (value[0] < 2009 || value[1] < 1 || value[1] > 12 || value[2] < 1 || value[2] > 31)
		throw std::runtime_error("Error: bad input => ");
}

float	BitcoinExchange::validateValue(std::string value){
	std::string rest;
	
	if(!isNumber(value))
		throw std::runtime_error("Error: bad input => " + value);
	float ret = std::strtod(value.c_str(), NULL);
	if (ret > 1000)
		throw std::runtime_error("Error: too large a number.");
	else if (ret < 0)
		throw std::runtime_error("Error: not a positive number.");
	return ret;
}

void BitcoinExchange::validate(std::string &line){
	try
	{
		size_t pos = line.find("|");

		if (pos == line.npos)
			throw std::runtime_error("Error: bad input => " + line);
		std::string key(line.substr(0, pos));
		line.erase(0, pos + 1);
		validateDate(key);
		float value = validateValue(line);
		// get thes key from map and make multiplication of value and 
		std::cout << key << " => " << value  << " = " << value * _data[key] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void BitcoinExchange::exchange(std::string file){
	std::ifstream input(file);
	if (!input.is_open())
		throw std::runtime_error("Error: could not open file");
	std::string line;
	std::getline(input, line);// skip first line;
	while (std::getline(input, line))
		validate(line);
}


BitcoinExchange::~BitcoinExchange(void)
{
	// std::cout << "BitcoinExchange Destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj):_data(obj._data)
{
	std::cout << "BitcoinExchange Copy constructor called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	// std::cout << "BitcoinExchange Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		_data = obj._data;
	}
	return (*this);
}
