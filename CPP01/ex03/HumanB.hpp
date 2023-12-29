/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:37:04 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 17:10:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB{
	private:
		std::string	name;
		
	public:
		HumanB(void);
		~HumanB(void);
		void	attack(void) const;
		void	setWeapon(Weapon wp);
		
		Weapon	*w;
};

#endif