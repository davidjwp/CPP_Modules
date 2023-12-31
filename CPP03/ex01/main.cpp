/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:14:57 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/06 15:12:55 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void){
	ClapTrap	george("George", 4);
	ScavTrap	bill("bill", 53);
	ScavTrap	d;

	george.attack(bill.getName());
	bill.takeDamage(george.getAd());
	bill.guardGate();
	bill.attack(george.getName());
	george.takeDamage(bill.getAd());
	bill.attack(d.getName());
	d.takeDamage(bill.getAd());
	d.setEp(0);
	d.beRepaired(100);

	return 0;
}