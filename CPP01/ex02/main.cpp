/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:40:12 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/08 15:43:18 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << &brain << '\n' << &(*stringPTR) << '\n' << &stringREF << std::endl;
	std::cout << brain << '\n' << *stringPTR << '\n' << stringREF << std::endl;

	stringREF = "OOPS WRONG BRAIN";
	std::cout << brain << '\n' << *stringPTR << '\n' << stringREF << std::endl;
	return 0;
}