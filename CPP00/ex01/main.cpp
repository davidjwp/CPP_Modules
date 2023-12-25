/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:31:50 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/25 22:23:35 by davidjwp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <cstring>

int	main(void)
{
	PhoneBook	PB;
	std::string	input;

	while ("ok"){
		std::cin >> input, std::cout << std::endl;

		if (!std::strcmp(input.c_str(), "ADD")){
			PB.add(std::cin >> std::string name, std::cin);
		}
		else if (!strcmp((const char *)input, "SEARCH")){
			
		}
		else if (!strcmp((const char *)input, "EXIT"))
			break ;
		else
			std::cout << "\t\033[101mwrong input\033[0m\n\033[1;92mADD / SEARCH / EXIT\033[0m\n" << std::endl;
		
	}

	return (0);
}