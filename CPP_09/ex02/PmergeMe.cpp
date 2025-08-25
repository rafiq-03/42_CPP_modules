#include "PmergeMe.hpp"

int PmergeMe::comparison_count = 0;

struct ComparisonCounter {
    bool operator()(int a, int b) {
        PmergeMe::comparison_count++;
        return a < b;
    }
};

PmergeMe::PmergeMe(void){}
PmergeMe::PmergeMe(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		if (!isNumber(av[i]))
			continue;
		int nb = atoi(av[i]);
		if (find(dequeChain.begin(), dequeChain.end(), nb) == dequeChain.end()){
			dequeChain.push_back(nb);
			vectorChain.push_back(nb);
		}
	}
}

PmergeMe::~PmergeMe(void){}

PmergeMe::PmergeMe(const PmergeMe& obj): vectorChain(obj.vectorChain), dequeChain(obj.dequeChain){}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	if (this != &obj){
		dequeChain = obj.dequeChain;
		vectorChain = obj.vectorChain;
	}
	return (*this);
}

/* ---------------------------------------------------- */

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


void	PmergeMe::Print(std::vector<int> &Chain, std::string state){
	std::cout << state << ":\t";
	for (size_t i = 0; i < Chain.size(); i++)
		std::cout << Chain[i] << " ";
	std::cout << std::endl;
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

	Print(vectorChain, "Before");
	Print(vectorChain, "After");
	clock_t t0 = std::clock();
	mergeSort(vectorChain);
	clock_t t1 = std::clock();
	mergeSort(dequeChain);
	clock_t t2 = std::clock();
	double first = double(t1 - t0) / CLOCKS_PER_SEC * 1e6;
	double second = double(t2 - t1) / CLOCKS_PER_SEC * 1e6;
	std::cout << "Time to process a range of 5 elements with std::vector : " << first << " µs" << std::endl;
	std::cout << "Time to process a range of 5 elements with std::deque : " << second << " µs" << std::endl;

	auto start = std::chrono::high_resolution_clock::now();
	mergeSort(vectorChain);
	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Time: " << duration << " µs\n";
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

bool isNumber(std::string s){
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!isdigit(s[i]))
			return false;
	}
	return true;
}