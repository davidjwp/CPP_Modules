#include <iostream>
#include <fstream>

int main(void){

std::ofstream op;
op.open("txt");

while (!op.eof())
	std::cout << op << std::endl;

	op.close();
	return 0;
}