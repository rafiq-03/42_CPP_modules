#include "PmergeMe.hpp"

int PmergeMe::comparison_count = 0;

struct ComparisonCounter {
    bool operator()(int a, int b) {
        PmergeMe::comparison_count++;
        return a < b;
    }
};

PmergeMe::PmergeMe(void)
{
	if (DEBUG)
		std::cout << "PmergeMe Default constructor called" << std::endl;
}
PmergeMe::PmergeMe(int ac, char **av)
{
	if (DEBUG)
		std::cout << "PmergeMe parametrized constructor called" << std::endl;
	for (int i = 1; i < ac; i++)
	{
		int nb = atoi(av[i]);
		if (find(dequeChain.begin(), dequeChain.end(), nb) == dequeChain.end()){
			dequeChain.push_back(nb);
			vectorChain.push_back(nb);
		}
	}
}

PmergeMe::~PmergeMe(void)
{
	if (DEBUG)
		std::cout << "PmergeMe Destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& obj): dequeChain(obj.dequeChain), vectorChain(obj.vectorChain)
{
	if (DEBUG)
		std::cout << "PmergeMe Copy constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	if (DEBUG)
		std::cout << "PmergeMe Copy assignment operator called" << std::endl;
	if (this != &obj){
		dequeChain = obj.dequeChain;
		vectorChain = obj.vectorChain;
	}
	return (*this);
}


/* ---------------------------------------------------- */


void	PmergeMe::isSorted(std::deque<int> &Chain){
	for (size_t i = 1; i < Chain.size(); i++)
	{
		if (Chain[i] < Chain[i - 1])
			std::cout << "\033[33m" << Chain[i - 1] << " \033[0m";
		else
			std::cout << Chain[i - 1]<< " " ;
	}
	std::cout << Chain[Chain.size() - 1] << std::endl;
}

void	PmergeMe::insert(std::deque<int> &main, std::deque<int> &pend, std::vector<int> &pairs){
	if (!pend.empty()) {
		if (pairs[0] != -1) {
			std::deque<int>::iterator pair_pos = std::find(main.begin(), main.end(), pairs[0]);
			std::deque<int>::iterator idx = std::upper_bound(main.begin(), pair_pos, pend[0], ComparisonCounter());
			main.insert(idx, pend[0]);
		} else {
			std::deque<int>::iterator idx = std::upper_bound(main.begin(), main.end(), pend[0], ComparisonCounter());
			main.insert(idx, pend[0]);
		}
	}

	std::vector<bool> inserted(pend.size(), false);
	if (!pend.empty()) inserted[0] = true;

	int jacobsthal_idx = 1;
	size_t inserted_count = pend.empty() ? 0 : 1;

	while (inserted_count < pend.size()) {
		int jacobsthal_num = jacobsthal(jacobsthal_idx);
		
		int prev_jacobsthal = (jacobsthal_idx > 1) ? jacobsthal(jacobsthal_idx - 1) : 0;
		
		for (int i = std::min(jacobsthal_num, (int)pend.size() - 1); i > prev_jacobsthal && i < (int)pend.size(); i--) {
			if (!inserted[i]) {
				if (pairs[i] != -1) {
					std::deque<int>::iterator pair_pos = std::find(main.begin(), main.end(), pairs[i]);
					std::deque<int>::iterator idx = std::upper_bound(main.begin(), pair_pos, pend[i], ComparisonCounter());
					main.insert(idx, pend[i]);
				} else {
					std::deque<int>::iterator idx = std::upper_bound(main.begin(), main.end(), pend[i], ComparisonCounter());
					main.insert(idx, pend[i]);
				}
				inserted[i] = true;
				inserted_count++;
			}
		}
		jacobsthal_idx++;
	}
}

void	PmergeMe::mergeSort(std::deque<int> &arr){
	if (arr.size() < 2)
		return;
	bool is_odd = arr.size() % 2 == 1;
	std::deque<int> main;
	std::deque<int> pend;
	std::vector<int> pairs;

	for (size_t i = 0; i + 2 < arr.size(); i += 2)
	{
		int larger = std::max(arr[i], arr[i + 1]);
		int smaller = std::min(arr[i], arr[i + 1]);
		comparison_count++;
		main.push_back(larger);
		pend.push_back(smaller);
		pairs.push_back(larger);
	}
	if (!is_odd){
		int larger = std::max(arr[arr.size() - 2], arr[arr.size() - 1]);
		int smaller = std::min(arr[arr.size() - 2], arr[arr.size() - 1]);

		comparison_count++;
		main.push_back(larger);
		pend.push_back(smaller);
		pairs.push_back(larger);
	}
	else {
		pend.push_back(arr[arr.size() - 1]);
		pairs.push_back(-1);
	}
	
	mergeSort(main);
	insert(main, pend, pairs);
	arr = main;
}


void	PmergeMe::isSorted(std::vector<int> &Chain){
	for (size_t i = 1; i < Chain.size(); i++)
	{
		if (Chain[i] < Chain[i - 1])
			std::cout << "\033[33m" << Chain[i - 1] << " \033[0m";
		else
			std::cout << Chain[i - 1]<< " " ;
	}
	std::cout << Chain[Chain.size() - 1] << std::endl;
}

void	PmergeMe::insert(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &pairs){
	if (!pend.empty()) {
		if (pairs[0] != -1) {
			std::vector<int>::iterator pair_pos = std::find(main.begin(), main.end(), pairs[0]);
			std::vector<int>::iterator idx = std::upper_bound(main.begin(), pair_pos, pend[0], ComparisonCounter());
			main.insert(idx, pend[0]);
		} else {
			std::vector<int>::iterator idx = std::upper_bound(main.begin(), main.end(), pend[0], ComparisonCounter());
			main.insert(idx, pend[0]);
		}
	}

	std::vector<bool> inserted(pend.size(), false);
	if (!pend.empty()) inserted[0] = true;

	int jacobsthal_idx = 1;
	size_t inserted_count = pend.empty() ? 0 : 1;

	while (inserted_count < pend.size()) {
		int jacobsthal_num = jacobsthal(jacobsthal_idx);
		
		int prev_jacobsthal = (jacobsthal_idx > 1) ? jacobsthal(jacobsthal_idx - 1) : 0;
		
		for (int i = std::min(jacobsthal_num, (int)pend.size() - 1); i > prev_jacobsthal && i < (int)pend.size(); i--) {
			if (!inserted[i]) {
				if (pairs[i] != -1) {
					std::vector<int>::iterator pair_pos = std::find(main.begin(), main.end(), pairs[i]);
					std::vector<int>::iterator idx = std::upper_bound(main.begin(), pair_pos, pend[i], ComparisonCounter());
					main.insert(idx, pend[i]);
				} else {
					std::vector<int>::iterator idx = std::upper_bound(main.begin(), main.end(), pend[i], ComparisonCounter());
					main.insert(idx, pend[i]);
				}
				inserted[i] = true;
				inserted_count++;
			}
		}
		jacobsthal_idx++;
	}
}

void	PmergeMe::mergeSort(std::vector<int> &arr){
	if (arr.size() < 2)
		return;
	bool is_odd = arr.size() % 2 == 1;
	std::vector<int> main;
	std::vector<int> pend;
	std::vector<int> pairs;

	for (size_t i = 0; i + 2 < arr.size(); i += 2)
	{
		int larger = std::max(arr[i], arr[i + 1]);
		int smaller = std::min(arr[i], arr[i + 1]);
		comparison_count++;
		main.push_back(larger);
		pend.push_back(smaller);
		pairs.push_back(larger);
	}
	if (!is_odd){
		int larger = std::max(arr[arr.size() - 2], arr[arr.size() - 1]);
		int smaller = std::min(arr[arr.size() - 2], arr[arr.size() - 1]);

		comparison_count++;
		main.push_back(larger);
		pend.push_back(smaller);
		pairs.push_back(larger);
	}
	else {
		pend.push_back(arr[arr.size() - 1]);
		pairs.push_back(-1);
	}
	
	mergeSort(main);
	insert(main, pend, pairs);
	arr = main;
}

void	PmergeMe::fordJohnsonSort(){
	mergeSort(dequeChain);
	isSorted(dequeChain);
	mergeSort(vectorChain);
	// isSorted(dequeChain);
}

int		PmergeMe::jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev2 = 0;
    int prev1 = 1;
    int current = 0;

    for (int i = 2; i <= n; ++i) {
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}
