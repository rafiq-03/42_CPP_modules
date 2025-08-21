#include "PmergeMe.hpp"
int PmergeMe::count = 0; 
PmergeMe::PmergeMe(void)
{
	// if (DEBUG)
		//std::cout << "PmergeMe Default constructor called" << std::endl;
}
PmergeMe::PmergeMe(int ac, char **av)
{
	// if (DEBUG)
		//std::cout << "PmergeMe parametrized constructor called" << std::endl;
	//std::cout << "before:  ";
	for (int i = 1; i < ac; i++)
	{
		int nb = atoi(av[i]);
		if (find(dequeChain.begin(), dequeChain.end(), nb) == dequeChain.end()){
			dequeChain.push_back(nb);
		}
	}
	//std::cout << std::endl;
	for (size_t i = 0; i < dequeChain.size(); i++)
	{
		//std::cout << dequeChain[i] << " " ;
	}
	//std::cout << "\n"<<std::endl;
	fordJohnsonSort(dequeChain, dequeChain.begin());
}

PmergeMe::~PmergeMe(void)
{
	// if (DEBUG)
		//std::cout << "PmergeMe Destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
	// if (DEBUG)
		//std::cout << "PmergeMe Copy constructor called" << std::endl;
	(void)obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	if (DEBUG)
		//std::cout << "PmergeMe Copy assignment operator called" << std::endl;
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

void    PmergeMe::insertion(std::deque<int> &chain, size_t step, size_t ref, int nb){
   // Step-aligned binary search for Ford-Johnson algorithm
   int left = 0;
   int right = ref;
   int f = 0, index = 0;
	while (left < right) 
	{
		
		int middle = (right + left) / 2;
		if (chain[middle] > nb) 
		{
			f = 0;
			right = middle - 1;
		}
		else 
		{
			f = 1;
			left = middle + 1;
		}
	}
	index = left;
	if (f == 1)
	{
		if (chain[right] < nb) 
			index++;
	}
   // Insert the element at the found position
   chain.insert(chain.begin() + index, nb);
}

int PmergeMe::chkek(std::deque<int> &chain, int nb, size_t length )
{
	for (size_t i = 0; i < chain.size(); i++)
	{
		//std::cout << chain[i] << " ";
	}
	//std::cout << std::endl;
	
	if (chain.size() == 0)
		return 0;
	if (chain.size() <= length)
	{
		count++;
		if (chain[chain.size() - 1] > nb) 
			return 0;
		return chain.size();
	}
	int left = 0;
   	int right = ((chain.size()) / length) - 1;
   	int f = 0, index = 0;
	int middle ;
	// //std::cout << chain.size() << std::endl;
	while (left <= right) 
	{
		count++;
		middle = (right + left) / 2;
		int idx = ((middle + 1) * length) - 1;
		// //std::cout <<length << " " <<  chain.size()  << " [ "  << left << "  " << right  << " ]"<<  " " << middle << " "  << nb << std::endl;
		if (nb < chain[idx]) 
		{
			f = 0;
			right = middle - 1;
		}
		else 
		{
			f = 1;
			left = middle + 1;
		}
	}
	index = left;
	count++;
	if (f == 1)
	{
		right = ((right + 1) * length) - 1;
		
		if (chain[right] < nb) 
		{
			if (chain.size() % length == 0)
				index ++;
			else
				return chain.size();
		}
	}
	else
	{
		if (chain[index] < nb) 
			return (index + 1) * length;
	}

   // Insert the element at the found position
   return index * length;
}

void	PmergeMe::mergeSort(std::deque<int> &arr,size_t lvl){
	size_t step = pow(2, lvl);
	if (step >= arr.size()){
		return;
	}
	// //std::cout << "level : " << lvl  << " step = " << step << std::endl << "          ";
	for (size_t i = 0; i < arr.size(); i += step)// loop over array and swap bigger with smaller numbers
	{
		if (i + step > arr.size()){
			// //std::cout << "\nleft elemnts : [ ";
			// for (size_t j = i; j < arr.size(); j++)
			// 	//std::cout << arr[j]  << " ";
			// //std::cout << "]" << std::endl;
			break;
		}
		// //std::cout << " * [ ";
		// for (size_t j = i; j < i + step; j++){
		// 	if (j == i + step / 2)
		// 		//std::cout << "| ";
		// 	//std::cout << (j < arr.size() ? arr[j] : -1 ) << " ";
		// }
		// //std::cout << "] " ;

		if (arr[i + step / 2 - 1] > arr[i + step -1])
			swapPairs(arr, step / 2, arr.begin() + i);

		// for (size_t j = i; j < i + step; j++){
		// 	if (j == i + step / 2)
		// 		//std::cout << ". ";
		// 	//std::cout << (j < arr.size() ? arr[j] : -1 ) << " ";
		// }
		// //std::cout << "| " ;
	}
	//std::cout << std::endl;

	mergeSort(arr, lvl + 1);


	// create main chain and pend chain;

	std::deque<int> main;
	std::deque<int> pend;
	size_t i = 0;

	// insert b1 and a1 in main chain
	main.insert(main.end(), arr.begin() + i, arr.begin() + i + step);
	
	// //std::cout << "*****0******* "<< std::endl;
	// //std::cout << "befor : i = " << i << std::endl;
	for (i = step; i < arr.size(); i += step){
		if (i + step / 2 <= arr.size())
			pend.insert(pend.end(), arr.begin() + i, arr.begin() + i + step / 2);
		if (i + step <= arr.size())
			main.insert(main.end(), arr.begin() + i + step / 2, arr.begin() + i + step);
		else
			break;
	}
	//std::cout << "\n\nlevel : " << lvl  << " step = " << step << std::endl;
	//std::cout << "arr  : " ;
	// //std::cout << "*****1******* "<< std::endl;
	for (size_t i = 0; i < arr.size(); i++){
		// if (i  % (step / 2) == 0)
			//std::cout << "| "; 
		//std::cout << arr[i] << " " ;
	}
	//std::cout << "| \n" ;
	//std::cout << "Main : " ;
	// //std::cout << "*****2******* "<< std::endl;
	for (size_t i = 0; i < main.size(); i++){
		// if (i  % (step / 2) == 0)
			//std::cout << "| ";
		//std::cout << main[i] << " " ;
	}
	//std::cout << "| \n" ;
	//std::cout << "Pend : " ;
	// //std::cout << "*****3******* "<< std::endl;
	for (size_t i = 0; i < pend.size(); i++){
		// if (i  % (step / 2) == 0)
			//std::cout << "| ";
		//std::cout << pend[i] << " " ;
	}
	// //std::cout << "*****4******* "<< std::endl;
	//std::cout << "| \n" ;
	// insert all elements from pend to main
		// //std::cout << "pend size : " << pend.size() << std::endl;
		// //std::cout << "*****5******* "<< std::endl;
	for (i = 0; i < pend.size(); i += step / 2) {
			// //std::cout << "i = " << i << std::endl;
			// //std::cout << "nb = " << pend[i + step / 2 - 1] << std::endl;
		size_t idx = chkek(main, pend[i + step / 2 - 1], step / 2);
		// std ::cout << "idx === " << idx << "   Trying to insert " << pend[i + step / 2 - 1] << std::endl;
		main.insert(main.begin() + idx, pend.begin() + i, pend.begin() + i + step / 2);
   	}
	// //std::cout << "*****6******* "<< std::endl;
	// //std::cout << "after : i = " << i << std::endl;
	// left elements
	for (size_t j = ((arr.size() / (step / 2)) * (step / 2)) ; j < arr.size(); j++){
		// //std::cout << "left : " << arr[j] << std::endl;
		main.push_back(arr[j]);
	}

	//std::cout << "after insertion:" << std::endl;
	//std::cout << "Main : " ;
	for (size_t i = 0; i < main.size(); i++){
		// if (i  % (step / 2) == 0)
			//std::cout << "| ";
		//std::cout << main[i] << " " ;
	}
	//std::cout << "" << std::endl;
	arr = main;
}


	// how to check if we can't make another pair ?
	// how remove a specific element (pair) from a place and insert it in another place?
	// pend chain
	// main chain
	// how to keep track pairs based on level?
	// what is the base condition for this methode?
void	PmergeMe::fordJohnsonSort(std::deque<int> &Chain, std::deque<int>::iterator bgn){
	static size_t level = 1;
	//std::cout << "size : " << Chain.size() << std::endl;
	mergeSort(Chain,level);
	// //std::cout << "\n\nafter : [ ";
	// for (size_t i = 0; i < Chain.size(); i++) {
    //    //std::cout << Chain[i] << " " ;
	// }
	// //std::cout << " ] \n";
	// (void)bgn;
}


int		PmergeMe::jacobsthal(int nb){
	return round((pow(2, nb + 1) + pow(-1, nb)) / 3); 
}
