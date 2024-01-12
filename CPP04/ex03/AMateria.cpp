/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:41:03 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 20:06:05 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void){
	//std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(AMateria& cpy){
	//std::cout << "AMateria copy constructor called" << std::endl;
	*this = cpy;
}

AMateria::AMateria(std::string const & type): _type(type){
	//std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::~AMateria(void){
	//std::cout << "AMateria default destructor called" << std::endl;
}

AMateria&	AMateria::operator=(AMateria& M1){
	(void)M1;
	return *this;
}

std::string const & AMateria::getType(void) const{
	return _type;
}

void	AMateria::use(ICharacter& target){
	std::cout << "AMateria use target " << std::endl;
	(void)target;
}