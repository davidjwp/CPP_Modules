/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:16:04 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/06 15:26:43 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include <string>

class	FragTrap: public ClapTrap {

public:

	FragTrap(void);
	FragTrap(FragTrap& cpy);
	FragTrap(std::string name);
	FragTrap(std::string name, int ad);
	~FragTrap(void);
	
	void	attack(std::string &target);
	void	highFivesGuys(void);
	FragTrap& operator=(FragTrap& s1);
};


#endif