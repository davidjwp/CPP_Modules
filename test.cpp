#include <iostream>

class	base{

protected:
	int	val;

public:
	base(void);
	base(base& cpy);
	base(int val);
	~base(void);

	base&	operator=(base& b1);
};

class	derived: public base{

public:
	derived(void);
	derived(derived& cpy);
	derived(int val);
	~derived(void);

	derived&	operator=(derived& b1);
};

base::base(void){
	this->val = 0;
}

base::base(int v): val(v){}

base::~base(void){}

base::base(base& cpy){
	*this = cpy;
}

base&	base::operator=(base& b1){
	this->val = b1.val;
	return *this;
}

derived::derived(void){
	this->val = 0;
}

derived::derived(int v): val(v){}

derived::~derived(void){}

derived::derived(derived& cpy){
	*this = cpy;
}

derived&	derived::operator=(derived& b1){
	this->val = b1.val;
	return *this;
}

int	main(void){
	return 0;
}