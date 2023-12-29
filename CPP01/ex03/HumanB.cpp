/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:52:04 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 18:21:26 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(void){}

HumanB::HumanB(std::string n): name(n){}

HumanB::~HumanB(void){}

void	HumanB::attack(void) const{
	std::cout << this->name << " attacks with their " << this->w2->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& wp){
	this->w2 = &wp;
}