#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <iostream>

class Wrongcat
{
	private:

	public:
		Wrongcat(void); // Default constructor
		Wrongcat(const Wrongcat& obj); // Copy constructor
		Wrongcat&	operator=(const Wrongcat& obj); // Copy assigment operator
		~Wrongcat(); // Destructor

};

#endif
