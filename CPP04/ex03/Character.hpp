/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:45:51 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/12 21:37:15 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character: public ICharacter{

private:
	AMateria *_items[4];
	std::string _name;

public:
	
	Character(void);
	Character(Character& cpy);
	Character(const char* name);
	~Character(void);

	virtual std::string const & getName(void) const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
	bool	isFull(void) const;
	Character& operator=(Character& C1);
};

#endif
