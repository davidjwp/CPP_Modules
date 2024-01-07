/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:24:47 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/07 15:40:53 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <string>

static char	*myItoa(int n, char buf[4]);

Brain::Brain(void){
	std::cout << "default Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = std::string("idea ") + myItoa(i, (char[4]){0, 0, 0, 0});
}

Brain::Brain(Brain& cpy){
	std::cout << "copy Brain constructor called" << std::endl;
	*this = cpy;
}

Brain::~Brain(void){
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(Brain& b1){
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b1.ideas[i];
	return *this;
}

static char*	myItoa(int n, char buf[4]){
	int		i = 0;

	while (n){
		buf[i] = n % 10;
		n /= 10;
		i++;
	}
	return (buf);
}