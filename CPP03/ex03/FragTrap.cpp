/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:18:42 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/06 15:42:11 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(void): ClapTrap(){
	std::cout << "Default FragTrap constructor called" << std::endl;
	this->_Name = "Default";
	this->_Hp = 100;
	this->_Ep = 100;
	this->setAd(30);
}

FragTrap::FragTrap(FragTrap& cpy): ClapTrap(cpy){
	std::cout << "Copy FragTrap constructor called" << std::endl;
	*this = cpy;
}

FragTrap::FragTrap(std::string n): ClapTrap(n){
	std::cout << "Named FragTrap constructor called" << std::endl;
	this->_Hp = 100;
	this->_Ep = 100;
	this->setAd(30);
}

FragTrap::FragTrap(std::string name, int ad): ClapTrap(name, ad){
	std::cout << "Name/Ad " << name << " FragTrap constructor called" << std::endl;
	this->_Hp = 100;
	this->_Ep = 100;
}

FragTrap::~FragTrap(void){
	std::cout << "FragTrap " << this->getName() << " destructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap& s1){
	this->_Name = s1._Name;
	this->_Hp = s1._Hp;
	this->_Ep = s1._Ep;
	this->_Ad = s1._Ad;
	return *this;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "Yeeeaaah can i get a high five over here !" << std::endl;
}

void	FragTrap::attack(std::string& target){
	std::cout << "FragTrap " << this->_Name << " attacks " << target << std::endl;
}