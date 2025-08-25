#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <deque>
# include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <ctime>

#define DEBUG 0

class PmergeMe
{
	private:
		std::vector<int>	vectorChain;
		std::deque<int>		dequeChain;

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
		void	mergeSort(std::deque<int> &arr);
		
		/* -- [ vector container : ] --*/
		
		void	insert(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pairs);
		void	Print(std::vector<int> &Chain, std::string state);
		void	mergeSort(std::vector<int> &arr);
};
bool isNumber(std::string s);

#endif
