/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:05:18 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/18 22:05:14 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

Base* generate(void){
	srand(time(NULL));
	int	num = rand() % 3 + 1;

	switch (num){
		case 1:
			return dynamic_cast<Base*>(new A);
		case 2:
			return dynamic_cast<Base*>(new B);
		case 3:
			return dynamic_cast<Base*>(new C);
	}
	return new Base;
}

void	identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer is a type: " << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer is a type: " << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer is a type: " << "C" << std::endl;
}

int	main(void)
{
	Base* obj = generate();
	identify(obj);
	return 0;
}