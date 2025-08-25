#include "RPN.hpp"

RPN::RPN(void){}

RPN::~RPN(void){}

RPN::RPN(const RPN& obj)
{
	this->_data = obj._data;
}

RPN& RPN::operator=(const RPN& obj)
{
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
		if (_data.size() < 2)
			throw std::runtime_error("Error");
		second = _data.top(); _data.pop();
		first = _data.top(); _data.pop();
		switch (*it)
		{
			case '*':
				_data.push(first * second);
				break;
			case '/':
				if (second == 0)
					throw std::runtime_error("Error");
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
	if (_data.size() != 1)
    	throw std::runtime_error("Error");
	return _data.top();
}