#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	if (DEBUG)
		std::cout << "PmergeMe Default constructor called" << std::endl;
}
PmergeMe::PmergeMe(int ac, char **av)
{
	if (DEBUG)
		std::cout << "PmergeMe parametrized constructor called" << std::endl;
	std::cout << "before:  ";
	for (int i = 1; i < ac; i++)
	{
		int nb = atoi(av[i]);
		if (find(dequeChain.begin(), dequeChain.end(), nb) == dequeChain.end()){
			dequeChain.push_back(nb);
		}
	}
	std::cout << std::endl;
	for (size_t i = 0; i < dequeChain.size(); i++)
	{
		std::cout << dequeChain[i] << " " ;
	}
	std::cout << "\n\n\n"<<std::endl;
	fordJohnsonSort(dequeChain, dequeChain.begin());
}

PmergeMe::~PmergeMe(void)
{
	if (DEBUG)
		std::cout << "PmergeMe Destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
	if (DEBUG)
		std::cout << "PmergeMe Copy constructor called" << std::endl;
	(void)obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	if (DEBUG)
		std::cout << "PmergeMe Copy assignment operator called" << std::endl;
	if (this != &obj){
	}
	return (*this);
}

void	PmergeMe::swapPairs(std::deque<int> &chain, size_t lvl, std::deque<int>::iterator bgn){
	for (std::deque<int>::iterator it = bgn; it < bgn + lvl; it++)
	{
		int tmp = *it;
		*it = *(it + lvl);
		*(it + lvl) = tmp;
		// std::cout << "b : " << *it << std::endl;
		// std::cout << "a : " << *(it + lvl) << std::endl;
	}
	std::cout << "swaped" << std::endl;
	static_cast<void>(chain);
	static_cast<void>(bgn);
}

int pow(int nb, int pow){
	int res = 1;
	if (!pow)
		return 1;
	while (pow--)
		res *= nb;
	return res;
}

void	PmergeMe::fordJohnsonSort(std::deque<int> &Chain, std::deque<int>::iterator bgn){
	// make pairs;
	// swap the biggest ones with smallest ones [small, big];
	// make recursion until you can't make pairs;
	// let unpaired number alone
	// make main chain like [s1, b1, b2, ..... bn ] and pend chain what is left for smalls [s2, s3, ..... sn]
	// now we have every sn < bn so we should insert every sn from pend chain in [s1, b1, .... bn]. don't forget to use order based on jacobsthal order
	static size_t level = 1;
	level *= 2;
	(void)Chain;
	(void)bgn;
}
