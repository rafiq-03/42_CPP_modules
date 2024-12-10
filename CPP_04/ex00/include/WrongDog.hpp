#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP
# include <iostream>

class Wrongdog
{
	private:

	public:
		Wrongdog(void); // Default constructor
		Wrongdog(const Wrongdog& obj); // Copy constructor
		Wrongdog&	operator=(const Wrongdog& obj); // Copy assigment operator
		~Wrongdog(); // Destructor

};

#endif
