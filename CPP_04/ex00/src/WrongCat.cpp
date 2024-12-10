#include "../include/Wrongcat.hpp"

Wrongcat::Wrongcat(void)
{
	std::cout << "Wrongcat Default constructor called" << std::endl;
}

Wrongcat::~Wrongcat(void)
{
	std::cout << "Wrongcat Destructor called" << std::endl;
}

Wrongcat::Wrongcat(const Wrongcat& obj)
{
	std::cout << "Wrongcat Copy constructor called" << std::endl;
}

Wrongcat& Wrongcat::operator=(const Wrongcat& obj)
{
	std::cout << "Wrongcat Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		// Add any assignment logic here
	}
	return (*this);
}
