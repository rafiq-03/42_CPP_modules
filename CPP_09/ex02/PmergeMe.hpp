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
		std::deque<int>		vectorChain;

	public:
		static int comparison_count;
		PmergeMe(void);
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe& obj);
		PmergeMe&	operator=(const PmergeMe& obj);
		~PmergeMe();
	
		int		jacobsthal(int nb);
		void	fordJohnsonSort();
	
		/* -- [ deque container : ] --*/

		void	insert(std::deque<int> &main, std::deque<int> &pend, std::vector<int> &pairs);
		void	isSorted(std::deque<int> &Chain);
		void	mergeSort(std::deque<int> &arr);
		
		/* -- [ vector container : ] --*/
		
		void	insert(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pairs);
		void	isSorted(std::vector<int> &Chain);
		void	mergeSort(std::vector<int> &arr);
};

#endif
