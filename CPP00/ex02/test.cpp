#include <iostream>
#include <ctime>
#include <iomanip>

int	main(void){
	time_t		raw;
	struct	tm	*local;
	char	ptr[42];

	time(&raw);
	local = localtime(&raw);
	strftime(ptr, 42, "[%Y%m%e_%H%M%S] ", local);
	std::cout << ptr << std::endl;
	return 0;
}

//[19920104_091532]
//[20231228_124034]