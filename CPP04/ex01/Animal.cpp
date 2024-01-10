/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:19:47 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/10 19:42:56 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal(void){
	std::cout << "Animal default constructor called" << std::endl;
	this->type = std::string("Animal");
}

Animal::Animal(Animal& cpy){
	std::cout << "Animal copy constructor called" << std::endl;
	*this = cpy;
}

Animal::~Animal(void){
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator=(Animal& a1){
	this->type = a1.type;
	return *this;
}

void	Animal::makeSound(void) const{
	std::cout << "i am animal" << std::endl;
}

std::string	Animal::getType(void) const{
	return this->type;
}

void	Animal::think(void) const{}