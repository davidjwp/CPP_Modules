/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:26:38 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/07 12:39:24 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat(void){
	std::cout << "Cat default constructor called" << std::endl;
	this->type = std::string("Cat");
}

Cat::Cat(Cat& cpy){
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cpy;
}

Cat::~Cat(void){
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(Cat& a1){
	this->type = a1.type;
	return *this;
}

void	Cat::makeSound(void) const{
	std::cout << "Meow" << std::endl;
}
