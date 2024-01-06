/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:35:40 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/06 20:58:12 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(void): ClapTrap(){
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	this->name = "Default";
	this->_Name = std::string("Default") + "_clap_name";
	this->_Hp = 100;
	this->_Ep = 50;
	this->setAd(30);
}

DiamondTrap::DiamondTrap(std::string n): \
ClapTrap(std::string(n) + "_clap_name"), \
ScavTrap(std::string(n) + "_clap_name"), \
FragTrap(std::string(n) + "_clap_name"){
	std::cout << "Named DiamondTrap constructor called" << std::endl;
	this->name = n;
	this->_Hp = 100;
	this->_Ep = 50;
	this->setAd(30);
}

DiamondTrap::DiamondTrap(DiamondTrap& cpy): ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy){
	std::cout << "Copy DiamondTrap constructor called" << std::endl;
	*this = cpy;
}

DiamondTrap::DiamondTrap(std::string n, int ad): \
ClapTrap(std::string(n) + "_clap_name", ad), \
ScavTrap(std::string(n) + "_clap_name", ad), \
FragTrap(std::string(n) + "_clap_name", ad){
	std::cout << "Name/Ad " << n << " DiamondTrap constructor called" << std::endl;
	this->_Hp = 100;
	this->_Ep = 50;
}

DiamondTrap::~DiamondTrap(void){
	std::cout << "DiamondTrap " << this->getName() << " destructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap& s1){
	this->_Name = s1._Name;
	this->name = s1.name;
	this->_Hp = s1._Hp;
	this->_Ep = s1._Ep;
	this->_Ad = s1._Ad;
	return *this;
}

void	DiamondTrap::setDiamondName(std::string& n){
	this->name = n;
}

void	DiamondTrap::attack(std::string& target){
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void){
	std::cout << "This is " << this->name << " ClapTrap " << this->getName() << std::endl;
}