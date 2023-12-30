/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:25:06 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/30 19:26:28 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2 || !*av[1]){
		std::cout << "no, fuck off" << std::endl;
		return 0;
	}

	Harl	harl;

	harl.complain(Harl::getIndex(av[1]));
	return 0;
}