/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:14:57 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/06 21:03:41 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

	std::cout << std::endl;
	DiamondTrap	bigDiamond("bigDiamond");
	bigDiamond.whoAmI();
	std::cout << std::endl;

	bigDiamond.attack(bill.getName());
	bill.takeDamage(bigDiamond.getAd());
	bigDiamond.attack(john.getName());
	bigDiamond.attack(d.getName());
	bigDiamond.attack(bill.getName());
	john.takeDamage(bigDiamond.getAd());
	d.takeDamage(bigDiamond.getAd());
	bill.takeDamage(bigDiamond.getAd());
	

	std::cout << std::endl;
	return 0;
}