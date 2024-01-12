/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:59:42 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 20:54:43 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat(void){
	std::cout << "default WrongCat constructor called" << std::endl;
	this->type = std::string("robotCat");
}

WrongCat::WrongCat(WrongCat& cpy){
	std::cout << "copy WrongCat constructor called" << std::endl;
	*this = cpy;
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat& w1){
	this->type = w1.type;
	return *this;
}

void	WrongCat::makeSound(void) const{
	std::cout << "i am real cat not roboot" << std::endl;
}