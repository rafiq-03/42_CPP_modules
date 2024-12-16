#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <iostream>
#include "AMateria.hpp" // need to check it later maybe there is a loop include

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}// is this a definition or not
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
