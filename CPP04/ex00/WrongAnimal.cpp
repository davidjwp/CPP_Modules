/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:08:08 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/07 13:20:41 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal(void){
	std::cout << "default WrongAnimal constructor called" << std::endl;
	this->type = std::string("robotAnimal");
}

WrongAnimal::WrongAnimal(WrongAnimal& cpy){
	std::cout << "copy WrongAnimal constructor called" << std::endl;
	*this = cpy;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal& W1){
	this->type = W1.type;	
	return *this;
}

std::string	WrongAnimal::getType(void) const{
	return this->type;
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "i am a real animal not a robot" << std::endl;
}