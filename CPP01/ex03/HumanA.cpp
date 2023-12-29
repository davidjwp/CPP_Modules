/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:46:58 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 18:03:24 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

//default Weapon for the default constructor which shouldn't be used
Weapon	Wdef;

HumanA::HumanA(void): w1(Wdef){}

HumanA::HumanA(std::string n, Weapon &wp): name(n), w1(wp){}

HumanA::~HumanA(void){}

void	HumanA::attack(void) const{
	std::cout << this->name << " attacks with their " << this->w1.getType() << std::endl;
}