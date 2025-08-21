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
	public:
		std::deque<int>		dequeChain;
		PmergeMe(void);
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe& obj);
		PmergeMe&	operator=(const PmergeMe& obj); 
		~PmergeMe();
		int		jacobsthal(int nb);
		static int count;
		void	swapPairs(std::deque<int> &chain, size_t step, std::deque<int>::iterator bgn);
		void	fordJohnsonSort(std::deque<int> &Chain);
		void	mergeSort(std::deque<int> &arr, size_t lvl);
		void	mergeInsert(std::deque<int> &arr,size_t step);
		int  	binarySearch(std::deque<int> &chain, int nb , size_t length, int start, int end);
		void	isSorted(std::deque<int> &Chain);
};
int pow(int nb, int pow);
#endif
