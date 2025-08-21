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
}

int pow(int nb, int pow){
	int res = 1;
	if (!pow)
		return 1;
	while (pow--)
		res *= nb;
	return res;
}

void    PmergeMe::insertion(std::deque<int> &chain, size_t step, size_t ref, int nb){
   // Step-aligned binary search for Ford-Johnson algorithm
   size_t left = 0;
   size_t right = ref;
  
   // If step is 1, chain is fully sorted - use regular binary search
   if (step <= 1) {
       while (left < right) {
           size_t middle = left + (right - left) / 2;
           if (chain[middle] > nb) {
               right = middle;
           } else {
               left = middle + 1;
           }
       }
   } else {
       // Step-aligned binary search: only compare with representative elements
       while (left < right) {
           size_t middle_pos = left + (right - left) / 2;
          
           // Align middle to step boundaries (representative positions)
           size_t aligned_pos = ((middle_pos / step) * step) + (step - 1);
           if (aligned_pos >= chain.size()) {
               aligned_pos = chain.size() - 1;
           }
          
           if (chain[aligned_pos] > nb) {
               right = middle_pos;
           } else {
               left = middle_pos + 1;
           }
       }
      
       // Adjust final position to step boundary
       left = ((left / step) * step) + (step - 1);
       if (left >= chain.size()) {
           left = chain.size();
       }
   }
  
   // Insert the element at the found position
   chain.insert(chain.begin() + left, nb);
}


void	PmergeMe::mergeSort(std::deque<int> &arr,size_t lvl){
	size_t step = pow(2, lvl);
	if (step > arr.size()){
		return;
	}
	// std::cout << "level : " << lvl  << " step = " << step << std::endl << "          ";
	for (size_t i = 0; i < arr.size(); i += step)// loop over array and swap bigger with smaller numbers
	{
		if (i + step > arr.size()){
			// std::cout << "\nleft elemnts : [ ";
			// for (size_t j = i; j < arr.size(); j++)
			// 	std::cout << arr[j]  << " ";
			// std::cout << "]" << std::endl;
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

		// for (size_t j = i; j < i + step; j++){
		// 	if (j == i + step / 2)
		// 		std::cout << ". ";
		// 	std::cout << (j < arr.size() ? arr[j] : -1 ) << " ";
		// }
		// std::cout << "| " ;
	}
	std::cout << std::endl;

	mergeSort(arr, lvl + 1);


	// create main chain and pend chain;

	std::deque<int> main;
	std::deque<int> pend;
	size_t i = 0;

	// insert b1 and a1 in main chain
	main.insert(pend.end(), arr.begin() + i, arr.begin() + i + step);
	
	// std::cout << "befor : i = " << i << std::endl;
	for (i = step; i < arr.size(); i += step){
		if (i + step / 2 <= arr.size())
			pend.insert(pend.end(), arr.begin() + i, arr.begin() + i + step / 2);
		if (i + step <= arr.size())
			main.insert(main.end(), arr.begin() + i + step / 2, arr.begin() + i + step);
		else
			break;
	}
	std::cout << "\n\nlevel : " << lvl  << " step = " << step << std::endl;
	std::cout << "arr  : " ;
	for (size_t i = 0; i < arr.size(); i++){
		if (i  % (step / 2) == 0)
			std::cout << "| "; 
		std::cout << arr[i] << " " ;
	}
	std::cout << "| \n" ;
	std::cout << "Main : " ;
	for (size_t i = 0; i < main.size(); i++){
		if (i  % (step / 2) == 0)
			std::cout << "| ";
		std::cout << main[i] << " " ;
	}
	std::cout << "| \n" ;
	std::cout << "Pend : " ;
	for (size_t i = 0; i < pend.size(); i++){
		if (i  % (step / 2) == 0)
			std::cout << "| ";
		std::cout << pend[i] << " " ;
	}
	std::cout << "| \n" ;

	// insert all elements from pend to main
	// for (size_t i = 0; i < pend.size(); i += step) {
    //    insertion(main, step / 2, main.size(), pend[i + step - 1]);
   	// }

	// std::cout << "after : i = " << i << std::endl;
	for (size_t j = i; j < arr.size(); j++){
		// std::cout << "left : " << arr[j] << std::endl;
		main.push_back(arr[j]);
	}


	std::cout << "\nafter insertion:" << std::endl;
	std::cout << "Main : " ;
	for (size_t i = 0; i < main.size(); i++){
		if (i  % (step / 2) == 0)
			std::cout << "| ";
		std::cout << main[i] << " " ;
	}

	// arr = main;
}


	// how to check if we can't make another pair ?
	// how remove a specific element (pair) from a place and insert it in another place?
	// pend chain
	// main chain
	// how to keep track pairs based on level?
	// what is the base condition for this methode?
void	PmergeMe::fordJohnsonSort(std::deque<int> &Chain, std::deque<int>::iterator bgn){
	static size_t level = 1;
	std::cout << "size : " << Chain.size() << std::endl;
	mergeSort(Chain,level);
	std::cout << "after : [ ";
	for (size_t i = 0; i < Chain.size(); i++) {
       std::cout << Chain[i] << " " ;
	}
	std::cout << " ] \n";
	(void)bgn;
}


int		PmergeMe::jacobsthal(int nb){
	return round((pow(2, nb + 1) + pow(-1, nb)) / 3); 
}
