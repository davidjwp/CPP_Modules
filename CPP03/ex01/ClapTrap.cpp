/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:19:08 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/06 15:39:35 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(void){
	std::cout << "Default ClapTrap constructor called" << std::endl;
	this->_Name = "Default";
	this->_Hp = 10;
	this->_Ep = 10;
	this->_Ad = 0;
}

ClapTrap::ClapTrap(std::string n): _Name(n){
	std::cout << "Named ClapTrap constructor called" << std::endl;
	this->_Hp = 10;
	this->_Ep = 10;
	this->setAd(0);
}

ClapTrap::ClapTrap(std::string n, int ad): _Name(n), _Ad(ad){
	std::cout << "Name/Ad " << n << " ClapTrap constructor called" << std::endl;
	this->_Hp = 10;
	this->_Ep = 10;
}

ClapTrap::ClapTrap(ClapTrap& src){
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap " << this->getName() << " destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap& c1){
	this->_Name = c1._Name;
	this->_Hp = c1._Hp;
	this->_Ep = c1._Ep;
	this->_Ad = c1._Ad;
	return *this;
}

void	ClapTrap::setAd(int ad){
	this->_Ad = ad;
}

void	ClapTrap::setEp(int ep){
	this->_Ep = ep;
}

void	ClapTrap::attack(const std::string& target){
	if (this->_Hp && this->_Ep) {
		this->_Ep--;
		std::cout << "ClapTrap " << this->_Name << " attacks " << target << std::endl;
	}
	else
		std::cout << this->_Name << " tries to attack " << target << \
		(!this->_Hp ? " but it is dead" : " but it has no energy") << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (this->_Hp) {
		std::cout << this->_Name << " takes " << amount << " points of damage" << std::endl;
		if ((int)(this->_Hp - amount) <= 0)
			ClapTrap::killClap(*this);
		else
			this->_Hp -= amount;
	}
	else {
		std::cout << this->_Name << " is already dead" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_Hp && this->_Ep) {
		(this->_Hp + amount > 10 ? this->_Hp = 10 : this->_Hp += amount);
		this->_Ep++;
		std::cout << this->_Name << " repairs " << amount << " health points" << std::endl;
	}
	else
		std::cout << this->_Name << " tries to repair itself but it " << \
		(!this->_Hp ? "is dead" : "has no energy") << std::endl;
}

std::string&	ClapTrap::getName(void){
	return this->_Name;
}

int	ClapTrap::getAd(void){
	return this->_Ad;
}

void	ClapTrap::killClap(ClapTrap& clap){
	clap._Hp = 0;
	clap._Ep = 0;
	clap._Ad = 0;
	std::cout << clap._Name << " is dead" << std::endl;
}