/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:52:04 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 17:11:33 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(void){}

HumanB::~HumanB(void){}

void	HumanB::attack(void) const{
	std::cout << this->name << "attacks with their" << this->w->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon wp){
	this->w = wp;
}