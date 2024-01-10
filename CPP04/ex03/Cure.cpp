/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:38:06 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/10 21:11:41 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include <string>

Cure::Cure(void){}

Cure::Cure(Cure& cpy){
	*this = cpy;
}

Cure::Cure(std::string const& type): _type(type){}

Cure&	Cure::operator=(Cure& M1){
	this->_type = M1.getType();
}

const std::string&	Cure::getType(void) const{
	return _type;
}

Cure*	Cure::clone(void) const{
	Cure*	clone = new Cure;

	clone->_type = this->_type;
	return clone;
}