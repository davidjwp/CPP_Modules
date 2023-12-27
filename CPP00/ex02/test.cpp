#include <ctime>
#include <iomanip>
#include <iostream>

int	main(void)
{
	std::time_t	t;
	t = std::time(nullptr);
	std::tm *ptm = std::localtime(&t);
	std::cout << std::put_time() << std::endl;
}