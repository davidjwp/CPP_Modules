/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:51:28 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 14:57:56 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void){}

Zombie::Zombie(std::string n): name(n){}

Zombie::~Zombie(void){
	std::cout << this->name << ": destroyed" << std::endl;
}

void	Zombie::announce(void){
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
