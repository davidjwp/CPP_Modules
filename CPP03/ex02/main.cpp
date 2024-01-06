/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:14:57 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/06 15:41:43 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void){
	ClapTrap	george("George");
	ScavTrap	bill("bill");
	ScavTrap	d;
	FragTrap	john("John");

	std::cout << std::endl;
	george.attack(bill.getName());
	bill.takeDamage(george.getAd());
	bill.guardGate();
	bill.attack(george.getName());
	george.takeDamage(bill.getAd());
	bill.attack(d.getName());
	d.takeDamage(bill.getAd());
	d.setEp(0);
	d.beRepaired(100);
	john.attack(bill.getName());
	bill.takeDamage(john.getAd());
	d.setEp(3);
	d.attack(bill.getName());
	bill.takeDamage(d.getAd());
	bill.attack(john.getName());
	john.takeDamage(bill.getAd());
	john.attack(bill.getName());
	bill.takeDamage(john.getAd());
	d.attack(bill.getName());
	bill.takeDamage(d.getAd());
	john.highFivesGuys();
	std::cout << std::endl;
	return 0;
}