#include <iterator>
#include <list>

typedef long int lint;

std::list<lint> lst;

int	main(void)
{

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	
	std::list<lint>::iterator p = lst.begin();
	std::distance(lst.begin(), p);
}