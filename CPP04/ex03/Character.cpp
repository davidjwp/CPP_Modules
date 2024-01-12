/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:18:46 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 20:06:18 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include <iostream>
#include <string>

Character::Character(void): _name(std::string("Default character")){
	//std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_items[i] = NULL;
}

Character::Character(Character& cpy){
	//std::cout << "Character copy constructor called" << std::endl;
	*this = cpy;
}

Character::~Character(void){
	//std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_items[i] != NULL)
			delete _items[i];
}

Character::Character(const char* name): _name(std::string(name)){
	//std::cout << "Character name constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_items[i] = NULL;
}

Character& Character::operator=(Character& C1){
	for (int i = 0; i < 4; i++)
		this->_items[i] = C1._items[i];
	return *this;
}

std::string const &Character::getName(void) const{
		return _name;
}

void	Character::equip(AMateria* m){
	if ((std::string("cure").compare(m->getType()) && std::string("ice").compare(m->getType())) || isFull()){
		if (isFull())
			std::cout << this->getName() << "'s Inventory is full" << std::endl;
		else
			std::cout << "Wrong materia" << std::endl;
		return ;
	}		
	for (int i = 0; i < 4; i++){
		if (_items[i] == NULL){
			_items[i] = m->clone();
			return ;
		}
	}
}

void	Character::unequip(int idx){
	_items[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target){
	if (idx < 4 && _items[idx] != NULL){
		_items[idx]->use(target);
		return ;
	}
	std::cout << "Bad items index used" << std::endl;
}

bool	Character::isFull(void) const{
	for (int i = 0; i < 4; i++)
		if (_items[i] == NULL)
			return false;
	return true;
}