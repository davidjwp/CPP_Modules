/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:24:41 by djacobs           #+#    #+#             */
/*   Updated: 2023/12/24 16:02:54 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PhoneBook.class.hpp"
#include"Contact.class.hpp"

PhoneBook::PhoneBook(void){
	std::cout << "Construction" << std::endl;
	
	return;
}

PhoneBook::~PhoneBook(void){
	std::cout << "Destruction" << std::endl;
	return;
}