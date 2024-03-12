#include <stack>
#include <iostream>
#include <deque>

int	main(void)
{
	std::deque<int> d;

	std::deque<int>::iterator it = d.begin();
	std::stack<int> s;

	d.push_back(2);

	std::cout << *it << std::endl;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);

	for (unsigned int i = 0; i < s.size(); i++)
		std::cout << s.top() - i << " ";
	std::cout << std::endl;
}