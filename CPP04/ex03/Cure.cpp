/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:38:06 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 19:33:21 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Cure.hpp"
#include <string>
#include <iostream>

Cure::Cure(void): _type(std::string("cure")){}

Cure::Cure(Cure& cpy): AMateria(cpy){
	*this = cpy;
}

Cure::Cure(std::string const& type): _type(type){}

Cure&	Cure::operator=(Cure& M1){
	this->_type = M1.getType();
	return *this;
}

Cure::~Cure(void){}

const std::string&	Cure::getType(void) const{
	return _type;
}

Cure*	Cure::clone(void) const{
	return new Cure;
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;	
}
