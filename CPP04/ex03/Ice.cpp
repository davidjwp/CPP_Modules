/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:20:32 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/10 22:48:46 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include <string>
#include <iostream>

Ice::Ice(void): _type(std::string("ice")){}

Ice::Ice(Ice& cpy){
	*this = cpy;
}

Ice::Ice(std::string const& type): _type(type){}

Ice&	Ice::operator=(Ice& M1){
	this->_type = M1.getType();
	return *this;
}

const std::string&	Ice::getType(void) const{
	return _type;
}

Ice*	Ice::clone(void) const{
	return new Ice;
}

void use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;	
}
