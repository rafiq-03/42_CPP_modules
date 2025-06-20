#include "RPN.hpp"

RPN::RPN(void)
{
	// std::cout << "RPN Default constructor called" << std::endl;
}

RPN::~RPN(void)
{
	// std::cout << "RPN Destructor called" << std::endl;
}

RPN::RPN(const RPN& obj)
{
	// std::cout << "RPN Copy constructor called" << std::endl;
	this->_data = obj._data;
}

RPN& RPN::operator=(const RPN& obj)
{
	// std::cout << "RPN Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_data = obj._data;
	return (*this);
}

float RPN::calculate(std::string input){
	for (std::string::iterator it = input.begin(); it != input.end(); it++){
		float first , second;
		if(*it == ' ')
			continue;
		if (isdigit(*it) && *(it + 1) == ' '){
			_data.push(*it - 48);
			continue;
		}
		else if (*it != '*' && *it != '-' && *it != '+' && *it != '/')
			throw std::runtime_error("Error");
		second = _data.top();
		_data.pop();
		if (_data.empty())
			throw std::runtime_error("Error");
		first = _data.top();
		if (_data.empty())
			throw std::runtime_error("Error");
		_data.pop();
		switch (*it)
		{
			case '*':
				_data.push(first * second);
				break;
			case '/':
				_data.push(first / second);
				break;
			case '+':
				_data.push(first + second);
				break;
			case '-':
				_data.push(first - second);
				break;
			default:
				throw std::logic_error("Error");
				break;
		}
	}
	return _data.top();
}
