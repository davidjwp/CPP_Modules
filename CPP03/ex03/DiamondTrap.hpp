/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:35:49 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/06 19:54:20 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap: public ScavTrap, public FragTrap{

private:

	std::string	name;

public:

	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(std::string name, int ad);
	DiamondTrap(DiamondTrap& cpy);
	~DiamondTrap(void);

	DiamondTrap&	operator=(DiamondTrap& d1);
	void	setDiamondName(std::string& name);
	void	whoAmI(void);
	void	attack(std::string& target);
};

#endif