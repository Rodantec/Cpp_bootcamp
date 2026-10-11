#include <iostream>

int	main(int ac, char **av)
{
	int i = 1;
	int	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j]) {
			std::cout << (char)std::toupper(av[i][j]); j++;	}
		i++; 
	}
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}