#include <iostream>

int main(int ac, char **av)
{
	int i;
	int	k;
	
	i = 0;
	k = 1;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (k < ac)
	{
		while (av[k][i])
			std::cout << (char)toupper(av[k][i++]);
		k++;
	}
	std::cout << std::endl;
	return (0);
}
