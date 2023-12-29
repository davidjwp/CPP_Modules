/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:30:19 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 15:55:13 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class	Weapon{
	private:
		std::string	type;
	public:
		
		Weapon(void);
		Weapon(std::string w);
		~Weapon(void);
		const std::string	getType(void) const;
		void	setType(std::string val);
};

#endif