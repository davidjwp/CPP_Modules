/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:43:45 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/28 19:55:26 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class	Zombie{
	private:
		std::string	name;
	public:
		Zombie::Zombie(void);
		Zombie::~Zombie(void);
		Zombie::Zombie(std::string n);
		void	announce( void );
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif