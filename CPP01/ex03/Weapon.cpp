/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:34:36 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 15:54:57 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon (void){}

Weapon::~Weapon (void){}

Weapon::Weapon (std::string t): type(t){} 

const	std::string	Weapon::getType(void) const{
	return this->type;
}

void	Weapon::setType(std::string val){
	this->type = val;
}
