/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:51:28 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 13:25:44 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void){}

Zombie::Zombie(std::string n): name(n){}
	
Zombie::~Zombie(void){}

Zombie *zombieHorde(int N, std::string name){
	Zombie	*Horde = new Zombie[N]{name};
	return Horde;
}