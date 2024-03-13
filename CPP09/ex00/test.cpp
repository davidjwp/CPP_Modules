#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

class Smallest{
private:
	unsigned int _target;
public:
	Smallest(int target): _target(target){}
	bool	operator()(unsigned int A, unsigned int B){return (A-_target) < (B-_target);}
};

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

	//va[0] = strtof("123.23", NULL, 10);
	//std::cout << va[0] << std::endl;

	std::vector<int> v;

	v.push_back(60);
	v.push_back(50);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);
	v.push_back(10);



	std::vector<int>::iterator i = std::min_element(v.begin(), v.end(), Smallest(25));

	std::cout << *i << std::endl;
	return 0;
}