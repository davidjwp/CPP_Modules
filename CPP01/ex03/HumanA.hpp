/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:40:54 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 18:02:53 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA{
	private:
		std::string	name;
		
	public:
		HumanA(void);
		HumanA(std::string name, Weapon &wp);
		~HumanA(void);
		void	attack(void) const;
		
		Weapon	&w1;
};

#endif