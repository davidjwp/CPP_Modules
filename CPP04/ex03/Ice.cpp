/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:20:32 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 20:09:05 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include <string>
#include <iostream>

Ice::Ice(void): _type(std::string("ice")){
	//std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice& cpy): AMateria(cpy){
	//std::cout << "Ice copy constructor called" << std::endl;
	*this = cpy;
}

Ice::Ice(std::string const& type): _type(type){
	//std::cout << "Ice type constructor called" << std::endl;
}

Ice&	Ice::operator=(Ice& M1){
	this->_type = M1.getType();
	return *this;
}

Ice::~Ice(void){
	//std::cout << "Ice destructor called" << std::endl;
}

const std::string&	Ice::getType(void) const{
	return _type;
}

Ice*	Ice::clone(void) const{
	return new Ice;
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;	
}
