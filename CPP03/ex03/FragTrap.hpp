/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:16:04 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/06 17:35:18 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include <string>

class	FragTrap: virtual public ClapTrap {

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