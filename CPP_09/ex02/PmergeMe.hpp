#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <deque>
# include <vector>

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
		void	swapPairs(std::deque<int> &chain, size_t lvl, std::deque<int>::iterator bgn);
		void	fordJohnsonSort(std::deque<int> &Chain, std::deque<int>::iterator bgn);
};
int pow(int nb, int pow);
#endif
