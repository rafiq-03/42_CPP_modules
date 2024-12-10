#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
	private:

	public:
		WrongAnimal(void); // Default constructor
		WrongAnimal(const WrongAnimal& obj); // Copy constructor
		WrongAnimal&	operator=(const WrongAnimal& obj); // Copy assigment operator
		~WrongAnimal(); // Destructor

};

#endif
