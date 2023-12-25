/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:24:41 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/25 21:14:36 by davidjwp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PhoneBook.class.hpp"
#include"Contact.class.hpp"

PhoneBook::PhoneBook(void){
	std::cout << "Phonebook Constructed" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void){
	std::cout << "Phonebook Destroyed" << std::endl;
	return;
}

void PhoneBook::add(char *name, char *number){
	
}
