#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_Inventory[4];
	public:
		MateriaSource(void); // Default constructor
		MateriaSource(const MateriaSource& obj); // Copy constructor
		MateriaSource&	operator=(const MateriaSource& obj); // Copy assigment operator
		// these are from IMateriaSource
		// ~MateriaSource() {}
		~MateriaSource(); // Destructor
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
