#include <exception>
#include <iostream>
#include <string>

class E{
private:
	E();

public:
	class EX: public std::exception{
	std::string _file;
	public:
	virtual ~EX() throw(){};
		EX(std::string ok): _file(ok + "message"){}
		const char* what() const throw(){return _file.c_str();};
	};

};

int	main(void){
	try {throw E::EX("FILE");}
	catch (std::exception &E){
		std::cout << E.what() << std::endl;
	}
}