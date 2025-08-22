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
	
	// Binary search on groups of size 'length' within bounds [start, end)
	int left = start / length;
	int right = (end - 1) / length;
	int result = end;
	
	while (left <= right)
	{
		count++;
		int middle = left + (right - left) / 2;
		int idx = (middle + 1) * length - 1;
		
		// Check bounds within the search range
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
	// std::cout << "level: " << lvl << " step: " << step << std::endl;
	// prnt(arr, step, "arr", 1);
	mergeSort(arr, lvl + 1);
	std::cout << "level: " << lvl << " step: " << step << std::endl;
	mergeInsert(arr, step);
}

void	PmergeMe::mergeInsert(std::deque<int> &arr,size_t step){
	// create main chain and pend chain;
	std::deque<int> main;
	std::deque<int> pend;
	size_t i = 0;

	// insert b1 and a1 in main chain
	main.insert(main.end(), arr.begin() + i, arr.begin() + i + step);
	// insert other elements a's in main and b's in pend
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
	int counter = 0;
	// should implement jacobsthal here and search from begining to where the pair existe
	// for (i = 0; i < pend.size(); i += step / 2) {
	// 	counter += step / 2;// track the pair of pend element

	// 	// prnt(main, step, "main", 1);
	// 	// std::cout << "* " << pend[i + step / 2 - 1] << ", " << main[ i + step + counter - 1] << std::endl;
	// 	size_t idx = 0;
	// 	if (i + step / 2 + counter >= main.size())
	// 		idx = binarySearch(main, pend[i + step / 2 - 1], step / 2, 0, main.size());
	// 	else
	// 		idx = binarySearch(main, pend[i + step / 2 - 1], step / 2, 0, i + step / 2 + counter);
	// 	main.insert(main.begin() + idx, pend.begin() + i, pend.begin() + i + step / 2);
   	// }
	int j = 3;
	int curr_jacob_idx = (jacobsthal(j) - 2) * step / 2;// index
	int prev_jacob_idx = jacobsthal(j - 1) - 2;
	// std::cout << "curr "<< curr_jacob_idx << std::endl;
	// std::cout << "prev "<< prev_jacob_idx << std::endl;
	while (curr_jacob_idx < static_cast<int>(pend.size())){
		for(int left = curr_jacob_idx; left > prev_jacob_idx; left -= step / 2){
			// std::cout << "** back " << left << std::endl;
			std::cout << "* " << pend[left + step / 2 - 1] << ", " << main[ left + step / 2 + counter + step / 2 - 1] << std::endl;
			counter += step / 2;
			size_t idx = 0;
			if (left + step / 2 + counter >= main.size())
				idx = binarySearch(main, pend[left + step / 2 - 1], step / 2, 0, main.size());
			else
				idx = binarySearch(main, pend[left + step / 2 - 1], step / 2, 0, left + step / 2 + counter);
			main.insert(main.begin() + idx, pend.begin() + left, pend.begin() + left + step / 2);
		}
		prev_jacob_idx = curr_jacob_idx;
		curr_jacob_idx = (jacobsthal(++j) - 2) * step / 2;
		// std::cout << "curr "<< curr_jacob_idx << std::endl;
		// std::cout << "prev "<< prev_jacob_idx << std::endl;
	}
	for(int left = pend.size(); left > prev_jacob_idx; left -= step / 2){
			counter += step / 2;
			size_t idx = 0;
			if (left + step / 2 + counter >= main.size())
				idx = binarySearch(main, pend[left + step / 2 - 1], step / 2, 0, main.size());
			else
				idx = binarySearch(main, pend[left + step / 2 - 1], step / 2, 0, left + step / 2 + counter);
			main.insert(main.begin() + idx, pend.begin() + left, pend.begin() + left + step / 2);
	}

	// instead of looping over pend we must search for jacobsthal elements b3 pend[1] =, b5 pend[3], b11 pend[9]
	
	for (size_t j = ((arr.size() / (step / 2)) * (step / 2)) ; j < arr.size(); j++)
		main.push_back(arr[j]);

	// assign main to our original array
	// prnt(main, step, "=> main", 1);
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
	std::cout << Chain.back() << std::endl;// last element
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

    int prev2 = 0; // J(0)
    int prev1 = 1; // J(1)
    int current = 0;

    for (int i = 2; i <= n; ++i) {
        current = prev1 + 2 * prev2; // J(n) = J(n-1) + 2 * J(n-2)
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}
