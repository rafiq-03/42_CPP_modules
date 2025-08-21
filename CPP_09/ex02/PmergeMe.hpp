#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <deque>
# include <vector>
#include <algorithm>
#include <cmath>

#define DEBUG 0

class PmergeMe
{
	private:
		std::deque<int>		dequeChain;
	public:
		PmergeMe(void);
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe& obj);
		PmergeMe&	operator=(const PmergeMe& obj); 
		~PmergeMe();
		int		jacobsthal(int nb);
		void	swapPairs(std::deque<int> &chain, size_t step, std::deque<int>::iterator bgn);
		void	fordJohnsonSort(std::deque<int> &Chain, std::deque<int>::iterator bgn);
		void	mergeSort(std::deque<int> &arr, size_t lvl);
		void	insertion(std::deque<int> &chain, size_t step, size_t ref, int nb);
};
int pow(int nb, int pow);
#endif
