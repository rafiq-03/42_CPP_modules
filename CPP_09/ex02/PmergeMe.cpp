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
	std::cout << "\n"<<std::endl;
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

void	PmergeMe::swapPairs(std::deque<int> &chain, size_t step, std::deque<int>::iterator bgn){
	for (std::deque<int>::iterator it = bgn; it < bgn + step; it++)
	{
		int tmp = *it;
		*it = *(it + step);
		*(it + step) = tmp;
	}
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

// void	PmergeMe::insertion(std::deque<int> &chain, size_t step, size_t ref, int nb){
// 	// size_t begin = 0;
// 	// size_t end = ref;
// 	// size_t middle = (end - begin) / 2;

// 	std::lower_bound(chain.begin(), chain.begin() + ref, nb);	
// 	// implement binary search
// 	// try to insert a range of element from pend to this position

// }


void	PmergeMe::mergeSort(std::deque<int> &arr, size_t begin, size_t lvl){
	size_t step = pow(2, lvl);
	if (step > arr.size()){
		return;
	}
	std::deque<int> pend;
	// std::cout << "level : " << lvl  << " step = " << step << std::endl;
	for (size_t i = 0; i < arr.size(); i += step)
	{
		// here we should check the biggest pair and swap it
		if (i + step > arr.size()){
			std::cout << "\nleft elemnts : [ ";
			for (size_t j = i; j < arr.size(); j++)
				std::cout << arr[j]  << " ";
			std::cout << "]" << std::endl;
			break;
		}
		// std::cout << " * [ ";
		// for (size_t j = i; j < i + step; j++){
		// 	if (j == i + step / 2)
		// 		std::cout << "| ";
		// 	std::cout << (j < arr.size() ? arr[j] : -1 ) << " ";
		// }
		// std::cout << "] " ;




		if (arr[i + step / 2 - 1] > arr[i + step -1])
			swapPairs(arr, step / 2, arr.begin() + i);
		// std::cout << "[";
		// earase form arr and push it in specific order
		

		for (size_t j = i; j < i + step; j++){
			if (j == i + step / 2)
				std::cout << ".";
			std::cout << (j < arr.size() ? arr[j] : -1 ) << " ";
		}
		std::cout << "| " ;
	}
	std::cout << std::endl;
	mergeSort(arr, begin, lvl + 1);
	// how to check if we can't make another pair ?
	// how remove a specific element (pair) from a place and insert it in another place?
	// pend chain
	// main chain
	// how to keep track pairs based on level?
	// what is the base condition for this methode?
}

void	PmergeMe::fordJohnsonSort(std::deque<int> &Chain, std::deque<int>::iterator bgn){
	// make pairs;
	// swap the biggest ones with smallest ones [small, big];
	// make recursion until you can't make pairs;
	// let unpaired number alone
	// make main chain like [s1, b1, b2, ..... bn ] and pend chain what is left for smalls [s2, s3, ..... sn]
	// now we have every sn < bn so we should insert every sn from pend chain in [s1, b1, .... bn]. don't forget to use order based on jacobsthal order
	static size_t level = 1;
	mergeSort(Chain, 0, level);
	(void)bgn;
}
