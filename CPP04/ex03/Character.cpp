/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:18:46 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/10 23:11:21 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): _name(std::string("Default character")){
	for (int i = 0; i < 4; i++)
		this->_materias[i] = nullptr;
}

Character::Character(Character& cpy){
	*this = cpy; 
}

Character::~Character(void){}

Character::Character(const char* name): _name(std::string(name)){}

Character& Character::operator=(Character& C1){
	for (int i = 0; i < 4; i++)
		this->_materias[i] = C1._materias[i];
	return *this;
}

std::string const &Character::getName(void) const{
		return _name;
}

void	Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++)
		
}


//public:
	
//	Character(void);
//	Character(Character& cpy);
//	~Character(void);

//	virtual std::string const & getName(void) const;
//	virtual void equip(AMateria* m);
//	virtual void unequip(int idx);
//	virtual void use(int idx, ICharacter& target);
//	Character& operator=(Character& C1);
//};