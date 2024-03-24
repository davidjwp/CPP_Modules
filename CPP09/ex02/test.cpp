#include <vector>
#include <iostream>
#include <iterator>

int	main(void)
{
	std::vector<int> vec = {1, 23, 45};

	vec.emplace(vec.begin() + 1, 32);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return 0;
}