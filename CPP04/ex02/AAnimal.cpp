/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:19:47 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 20:57:07 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>
#include <string>

AAnimal::AAnimal(void){
	std::cout << "AAnimal default constructor called" << std::endl;
	this->type = std::string("AAnimal");
}

AAnimal::AAnimal(AAnimal& cpy){
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = cpy;
}

AAnimal::~AAnimal(void){
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal&	AAnimal::operator=(AAnimal& a1){
	this->type = a1.type;
	return *this;
}

void	AAnimal::makeSound(void) const{
	std::cout << "i am AAnimal" << std::endl;
}

std::string	AAnimal::getType(void) const{
	return this->type;
}

void	AAnimal::think(void) const{}