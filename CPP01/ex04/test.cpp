#include <iostream>
#include <fstream>
#include <string>

int	main(void)
{
	std::ifstream	file("file");
	std::ofstream	file2("file2");
	std::string		s1;

	while (std::getline(file, s1)){
		if (!file.eof())
			s1 += '\n';
		file2 << s1;
	}
	return 0;
}