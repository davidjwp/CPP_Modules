/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:40:12 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/29 15:14:17 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define NUMBER 12	

int	main(void)
{
	Zombie	*Horde = zombieHorde(NUMBER, "david");
	for (int i = 0; i < NUMBER; i++)
		Horde[i].announce();
	delete [] Horde;
	return 0;
}