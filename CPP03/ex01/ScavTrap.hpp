/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:48:46 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/05 22:16:20 by djacobs          ###   ########.fr       */
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
	ScavTrap(std::string& name, int ad);
	~ScavTrap(void);
	
	void	attack(std::string& target);
	ScavTrap& operator=(ScavTrap& s1);
};

#endif