/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:26:38 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 21:13:22 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat(void){
	std::cout << "Cat default constructor called" << std::endl;
	this->type = std::string("Cat");
	catBrain = new Brain();
}

Cat::Cat(Cat& cpy){
	std::cout << "Cat copy constructor called" << std::endl;
	catBrain = new Brain;
	*this = cpy;
}

Cat::Cat(const char* idea){
	std::string	i = std::string(idea);
	std::cout << "Cat idea constructor called" << std::endl;
	this->type = std::string("Cat");
	catBrain = new Brain(i);
}

Cat::~Cat(void){
	std::cout << "Cat destructor called" << std::endl;
	delete catBrain;
}

Cat&	Cat::operator=(Cat& a1){
	this->type = a1.type;
	return *this;
}

void	Cat::makeSound(void) const{
	std::cout << "Meow" << std::endl;
}

void	Cat::think(void) const{
	for (int i = 0; i < 100; i++)
		std::cout << catBrain->getIdea(i) << ' ';
	std::cout << std::endl;
}