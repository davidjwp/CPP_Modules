#include <iostream>
#include <algorithm>
#include <vector>


int	main(void)
{
	std::vector<int> vec(5);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it;
	std::cout << std::endl;

	vec.pop_back();
	vec.push_back(6);
	vec.pop_back();
	vec.push_back(6);
	vec.pop_back();
	vec.push_back(6);
	vec.pop_back();
	vec.push_back(6);

	//vec.push(6);
	//vec.addNumber(3);
	//vec.addNumber(17);
	//vec.addNumber(9);
	//vec.addNumber(11);
	//std::vector<int> vec({1, 3, 8, 5, 6, 7, -23});

	//std::cout << *std::min_element(vec.begin(), vec.end()) << std::endl;

	//std::vector<int> _no({});
	//std::cout << *std::min_element(_no.begin(), _no.end());
	return 0;
}