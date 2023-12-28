/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:40:12 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/28 23:28:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	randomChump((std::string)"jose");
	Zombie	*nZombie = newZombie((std::string)"john");
	nZombie->announce();
	delete nZombie;
	return 0;
}