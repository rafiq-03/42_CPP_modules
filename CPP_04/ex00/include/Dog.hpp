#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>

class Dog
{
	private:

	public:
		Dog(void); // Default constructor
		Dog(const Dog& obj); // Copy constructor
		Dog&	operator=(const Dog& obj); // Copy assigment operator
		~Dog(); // Destructor

};

#endif
