/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:14:57 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/10 14:47:46 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void){
	ClapTrap	george("George", 4);
	ClapTrap	john("John", 6);

	george.attack(john.getName());
	john.takeDamage(george.getAd());
	john.beRepaired(10);
	john.attack(george.getName());
	john.attack(george.getName());
	george.takeDamage(john.getAd());
	george.takeDamage(john.getAd());
	george.attack(john.getName());
	john.takeDamage(george.getAd());
	john.attack("other ClapTrap");
	john.beRepaired(12);
	
	return 0;
}