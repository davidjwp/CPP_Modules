#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	std::string	file = av[1];
	if (file.empty()){
		std::cout << "string is empty" << std::endl;
		return 0;
	}
	std::cout << "string isn't empty" << std::endl;
	return 0;
}