/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:24:41 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/26 18:59:25 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void){
	for (int i = 0; i < 8; i++)
		cont[i] = Contact(i);
	std::cout << "Phonebook Constructed" << std::endl;
}

PhoneBook::~PhoneBook(void){}

void PhoneBook::Search(void) const
{
	std::string Index;
	
	//writing the contacts info 
	std::cout << "   Index  |First Name| Last Name| Nickname " << std::endl;	
	for (int i = 0; i < 8; i++){
		if (this->cont->set)
			this->cont[i].getInfo();
	}

	std::cout << GRE << "Enter Index: " << RES;
	std::cin >> Index;
	std::cout << std::endl;

	//checking the index
	for (int i = 0; Index.c_str()[i]; i++){
		if (Index.c_str()[0] == '-'){
			std::cout << '\t' << RED << "Error negative index" << RES << std::endl;
			return;
		}
		else if (!std::isdigit(Index.c_str()[i])){
			std::cout << '\t' << RED << "Error bad index" << RES << std::endl;
			return;
		}			
	}
	int	nIndex = atoi(Index.c_str());
	if (nIndex > 8){
		std::cout << '\t' << RED << "Error index too high" << RES << std::endl;
		return;
	}

	this->cont[nIndex].getCont();
}

/*
   Index  |First Name| Last Name| Nickname 
          |          |          |          
*/