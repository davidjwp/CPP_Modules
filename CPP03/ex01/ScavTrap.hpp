/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:48:46 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/06 00:07:50 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <string>

class	ScavTrap: public ClapTrap {

public:

	ScavTrap(void);
	ScavTrap(ScavTrap& cpy);
	ScavTrap(std::string name, int ad);
	~ScavTrap(void);
	
	void	attack(std::string &target);
	void	guardGate(void);
	ScavTrap& operator=(ScavTrap& s1);
};

#endif