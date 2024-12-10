#include "../include/Wrongdog.hpp"

Wrongdog::Wrongdog(void)
{
	std::cout << "Wrongdog Default constructor called" << std::endl;
}

Wrongdog::~Wrongdog(void)
{
	std::cout << "Wrongdog Destructor called" << std::endl;
}

Wrongdog::Wrongdog(const Wrongdog& obj)
{
	std::cout << "Wrongdog Copy constructor called" << std::endl;
}

Wrongdog& Wrongdog::operator=(const Wrongdog& obj)
{
	std::cout << "Wrongdog Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		// Add any assignment logic here
	}
	return (*this);
}
