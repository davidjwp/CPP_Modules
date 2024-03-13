#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

int main(void){

	std::ifstream op;
	std::string ok;
	op.open("txt");
	
	while (op){
		std::getline(op, ok);
		std::cout << ok << "\n";
	}
	op.close();

	std::vector<float> va(1);

	//va[0] = atof("123.23");

	va[0] = strtof("123.23", NULL, 10);
	std::cout << va[0] << std::endl;
	return 0;
}