/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:51:28 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 15:12:57 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void){}

Zombie::~Zombie(void){
	std::cout << this->name << ": destroyed" << std::endl;
}
	
void	Zombie::giveName(std::string n){
	this->name = n;
}

void	Zombie::announce(void) const{
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}