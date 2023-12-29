/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:46:58 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 16:00:11 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(void){}

HumanA::HumanA(std::string n, Weapon w): name(n){
	this->w.setType(w.getType());
}

HumanA::~HumanA(void){}

void	HumanA::attack(void) const{
	std::cout << this->name << "attacks with their" << this->w.getType() << std::endl;
}