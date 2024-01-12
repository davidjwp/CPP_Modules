/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:38:06 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 20:05:49 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Cure.hpp"
#include <string>
#include <iostream>

Cure::Cure(void): _type(std::string("cure")){
	//std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure& cpy): AMateria(cpy){
	//std::cout << "Cure copy constructor called" << std::endl;
	*this = cpy;
}

Cure::Cure(std::string const& type): _type(type){
	//std::cout << "Cure type constructor called" << std::endl;
}

Cure&	Cure::operator=(Cure& M1){
	this->_type = M1.getType();
	return *this;
}

Cure::~Cure(void){
	//std::cout << "Cure destructor called" << std::endl;
}

const std::string&	Cure::getType(void) const{
	return _type;
}

Cure*	Cure::clone(void) const{
	return new Cure;
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;	
}
