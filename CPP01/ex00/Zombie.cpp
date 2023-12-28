/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:51:28 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/28 23:22:33 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void){}

Zombie::Zombie(std::string n): name(n){}

Zombie::~Zombie(void){}

void	Zombie::announce(void){
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
