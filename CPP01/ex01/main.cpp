/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:40:12 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/09 12:23:10 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define NUMBER 4	

int	main(void)
{
	Zombie	*Horde = zombieHorde(NUMBER, "david");

	for (int i = 0; i < NUMBER; i++)
		Horde[i].announce();
	delete [] Horde;
	Zombie	*otherHorde = zombieHorde(3, "santa");
	for (int i = 0; i < 3; i++)
		otherHorde[i].announce();
	delete [] otherHorde;
	return 0;
}