#include <iostream>
#include <cctype>

#define EM_MEGA "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

class upper {
	public:
	void	up(char c){
		isalpha(c) ? (islower(c) ? std::cout << (char)toupper(c) : std::cout << c) : std::cout << c;
	}
};

int	main(int ac, char **av)
{
	upper	up;

	if (ac < 2)
		return (std::cout << EM_MEGA << std::endl, 0);
	while (*(++av))
	{
		while (**av)
			up.up(*(*av)++);
		if ((**av) + 1)
			std::cout << ' ' ;
	}
	std::cout << std::endl;
	return 0;
}
//c++ -Werror -Wall -Wextra -std=c++98 -g3 megaphone.cpp -o mega