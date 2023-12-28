/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:51:28 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/28 17:42:50 by djacobs          ###   ########.fr       */
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
