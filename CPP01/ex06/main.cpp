/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:25:06 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/08 21:44:54 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2 || !*av[1]){
		std::cout << "no do it again like this\n" << "[DEBUG][INFO][WARNING][ERROR]" << std::endl;
		return 0;
	}

	Harl	harl;

	harl.complain(Harl::getIndex(av[1]));
	return 0;
}