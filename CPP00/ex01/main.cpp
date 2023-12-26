/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:31:50 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/26 19:37:05 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	PhoneBook	PB;
	std::string	input;
	int	nLastAdd = 0;

	std::cout << GRE << "Input: " << RES;
	while (std::cin >> input){
		if (!std::strcmp(input.c_str(), "ADD")){
			PB.cont[nLastAdd].add();
			nLastAdd++;
		}
		else if (!std::strcmp(input.c_str(), "SEARCH")){
			PB.Search();
		}
		else if (!std::strcmp(input.c_str(), "EXIT"))
			break ;
		else
			std::cout << '\t' << RED << "wrong input" << RES << '\n' << GRE << "ADD / SEARCH / EXIT\n" << RES << std::endl;
		if (nLastAdd == 8)
			nLastAdd = 0;
		std::cout << GRE << "Input: " << RES;
	}

	return (0);
}