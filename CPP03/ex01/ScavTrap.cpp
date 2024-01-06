/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:48:24 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/06 00:07:24 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(void){
	std::cout << "Default ScavTrap created" << std::endl;
	this->_Name = "Default";
	this->_Hp = 100;
	this->_Ep = 50;
	this->setAd(20);
}

ScavTrap::ScavTrap(ScavTrap& cpy){
	std::cout << "Copy ScavTrap created" << std::endl;
	*this = cpy;
}

ScavTrap::ScavTrap(std::string name, int ad): _Name(name), _Ad(ad){
	std::cout << "Name/ad ScavTrap created" << std::endl;
	this->_Hp = 10;
	this->_Ep = 10;
}

ScavTrap::~ScavTrap(void){
	std::cout << "ScavTrap destroyed" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap& s1){
	this->_Name = s1._Name;
	this->_Hp = s1._Hp;
	this->_Ep = s1._Ep;
	this->_Ad = s1._Ad;
	return *this;
}

void	ScavTrap::guardGate(void){
	std::cout << "ScavTrap is now in Gate keeper mode"
}

void	ScavTrap::attack(std::string& target){
	std::cout << "ScavTrap " << this->_Name << " attacks " << target << std::cout;
}