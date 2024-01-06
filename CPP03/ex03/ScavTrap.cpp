/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:48:24 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/06 15:39:18 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(void): ClapTrap(){
	std::cout << "Default ScavTrap constructor called" << std::endl;
	this->_Name = "Default";
	this->_Hp = 100;
	this->_Ep = 50;
	this->setAd(20);
}

ScavTrap::ScavTrap(std::string n): ClapTrap(n){
	std::cout << "Named ScavTrap constructor called" << std::endl;
	this->_Hp = 100;
	this->_Ep = 50;
	this->setAd(20);
}

ScavTrap::ScavTrap(ScavTrap& cpy): ClapTrap(cpy){
	std::cout << "Copy ScavTrap constructor called" << std::endl;
	*this = cpy;
}

ScavTrap::ScavTrap(std::string name, int ad): ClapTrap(name, ad){
	std::cout << "Name/Ad " << name << " ScavTrap constructor called" << std::endl;
	this->_Hp = 100;
	this->_Ep = 50;
}

ScavTrap::~ScavTrap(void){
	std::cout << "ScavTrap " << this->getName() << " destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap& s1){
	this->_Name = s1._Name;
	this->_Hp = s1._Hp;
	this->_Ep = s1._Ep;
	this->_Ad = s1._Ad;
	return *this;
}

void	ScavTrap::guardGate(void){
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(std::string& target){
	std::cout << "ScavTrap " << this->_Name << " attacks " << target << std::endl;
}