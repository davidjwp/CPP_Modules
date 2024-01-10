/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:25:52 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/10 20:09:35 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog(void){
	std::cout << "Dog default constructor called" << std::endl;
	this->type = std::string("Dog");
	dogBrain = new Brain();
}

Dog::Dog(Dog& cpy){
	std::cout << "Dog copy constructor called" << std::endl;
	*this = cpy;
}

Dog::~Dog(void){
	std::cout << "Dog destructor called" << std::endl;
	delete dogBrain;
}

Dog&	Dog::operator=(Dog& a1){
	this->type = a1.type;
	return *this;
}

void	Dog::makeSound(void) const{
	std::cout << "Woof" << std::endl;
}

void	Dog::think(void) const{
	for (int i = 0; i< 100; i++)
		std::cout << dogBrain->getIdea(i) << ' ';
	std::cout << std::endl;
}
