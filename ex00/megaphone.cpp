#include <iostream>

class upper {
	public:
	bool	alpha(char c){
		if ((c >=  65 && c <= 90) || (c >= 97 && c <= 122))
			return true;
		return false;
	}
	void	up(char c){
		alpha(c) ? (std::cout << c ? :) : return;
	}
};

int	main(int ac, char **av)
{
	upper	up;
	
	if (ac < 2)
		return 0;
	while (*av)
	{
		while (**av)
			up.up(**av++);
		*av++;
	}
	return 0;
}