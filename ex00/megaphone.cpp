#include <iostream>
#include <cctype>
#include <string>

const std::string LOUD_FEEDBACK = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

class UpperCase {
public:
	void	up(char c){
		std::isalpha(c) ? (islower(c) ? std::cout << (char)toupper(c) : std::cout << c) : std::cout << c;
	}
};

int	main(int ac, char **av)
{
	UpperCase	up;


	if (ac < 2)
		return (std::cout << LOUD_FEEDBACK << std::endl, 0);
	while (*(++av)){
		while (**av)
			up.up(*(*av)++);
		if ((**av) + 1)
			std::cout << ' ' ;
	}
	std::cout << std::endl;
	return 0;
}
//c++ -Werror -Wall -Wextra -std=c++98 -g3 megaphone.cpp -o mega