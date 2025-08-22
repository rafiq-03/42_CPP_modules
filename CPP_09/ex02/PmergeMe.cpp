#include "PmergeMe.hpp"
int PmergeMe::count = 0;

void prnt(std::deque<int> arr, size_t step, std::string name, int flag){
	std::cout << name << " : ";
	for (size_t i = 0; i < arr.size(); i++){
		if ((i + 1) % (step / 2) == 0 && flag && step != 2){
			std::cout << "\033[34m" << arr[i] <<"\033[0m | ";
		}else{
			std::cout << arr[i] << " " ;
		}
	}
	std::cout << "\n" <<std::endl;
}

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
	fordJohnsonSort(dequeChain);
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
	count++;
	for (std::deque<int>::iterator it = bgn; it < bgn + step; it++)
	{
		int tmp = *it;
		*it = *(it + step);
		*(it + step) = tmp;
	}
	static_cast<void>(chain);
}

int pow(int nb, int pow){
	int res = 1;
	if (!pow)
		return 1;
	while (pow--)
		res *= nb;
	return res;
}

int PmergeMe::binarySearch(std::deque<int> &chain, int nb, size_t length, int start, int end)
{
	if (start >= end || chain.size() == 0)
		return start;
	int left = start / length;
	int right = (end - 1) / length;
	int result = end;
	
	while (left <= right)
	{
		count++;
		int middle = left + (right - left) / 2;
		int idx = (middle + 1) * length - 1;
		if (idx >= end)
			idx = end - 1;
		if (idx < start)
			idx = start;
		
		if (chain[idx] >= nb)
		{
			result = middle * length;
			if (result < start)
				result = start;
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	return result;
}

void	PmergeMe::mergeSort(std::deque<int> &arr,size_t lvl){
	size_t step = pow(2, lvl);
	if (step >= arr.size())
		return;
	for (size_t i = 0; i < arr.size(); i += step)
	{
		if (i + step > arr.size())
			break;
		if (arr[i + step / 2 - 1] > arr[i + step -1])
			swapPairs(arr, step / 2, arr.begin() + i);
	}
	mergeSort(arr, lvl + 1);
	std::cout << "level: " << lvl << " step: " << step << std::endl;
	mergeInsert(arr, step);
}

void	PmergeMe::mergeInsert(std::deque<int> &arr,size_t step){
	std::deque<int> main;
	std::deque<int> pend;
	size_t i = 0;

	main.insert(main.end(), arr.begin() + i, arr.begin() + i + step);
	for (i = step; i < arr.size(); i += step){
		if (i + step / 2 <= arr.size())
			pend.insert(pend.end(), arr.begin() + i, arr.begin() + i + step / 2);
		if (i + step <= arr.size())
			main.insert(main.end(), arr.begin() + i + step / 2, arr.begin() + i + step);
		else
			break;
	}
	prnt(arr, step, "arr", 1);
	prnt(main, step, "main", 1);
	prnt(pend, step, "pend", 1);
	int num_pairs = pend.size() / (step / 2);
	std::vector<bool> inserted(num_pairs, false);
	int total_inserted = 0;
	
	int j = 2;
	int prev_jacob = 0;
	
	while (prev_jacob < num_pairs) {
		int curr_jacob = jacobsthal(j);
		if (curr_jacob > num_pairs)
			curr_jacob = num_pairs;	
		for (int pair_idx = curr_jacob - 1; pair_idx >= prev_jacob; pair_idx--) {
			if (pair_idx >= num_pairs || inserted[pair_idx]) continue;
			int pend_pos = pair_idx * (step / 2);
			int search_limit = (pair_idx + 1) * step + total_inserted * (step / 2);
			if (search_limit > static_cast<int>(main.size())) 
				search_limit = main.size();
			size_t insert_idx = binarySearch(main, pend[pend_pos + step / 2 - 1], step / 2, 0, search_limit);
			main.insert(main.begin() + insert_idx, pend.begin() + pend_pos, pend.begin() + pend_pos + step / 2);
			inserted[pair_idx] = true;
			total_inserted++;
		}
		prev_jacob = curr_jacob;
		j++;
	}	
	for (size_t j = ((arr.size() / (step / 2)) * (step / 2)) ; j < arr.size(); j++)
		main.push_back(arr[j]);
	arr = main;
}

void	PmergeMe::isSorted(std::deque<int> &Chain){
	for (size_t i = 1; i < Chain.size(); i++)
	{
		if (Chain[i] < Chain[i - 1])
			std::cout << "\033[33m" << Chain[i - 1] << " \033[0m";
		else
			std::cout << Chain[i - 1]<< " " ;
	}
	std::cout << Chain.back() << std::endl;
}


void	PmergeMe::fordJohnsonSort(std::deque<int> &Chain){
	static size_t level = 1;
	std::cout << "size : " << Chain.size() << std::endl;
	mergeSort(Chain,level);
	isSorted(Chain);
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
