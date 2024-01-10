/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:20:32 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/10 21:21:55 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include <string>

Ice::Ice(void){}

Ice::Ice(Ice& cpy){
	*this = cpy;
}

Ice::Ice(std::string const& type): _type(type){}

Ice&	Ice::operator=(Ice& M1){
	this->_type = M1.getType();
}

const std::string&	Ice::getType(void) const{
	return _type;
}

Ice*	Ice::clone(void) const{
	Ice*	clone = new Ice;

	clone->_type = this->_type;
	return clone;
}