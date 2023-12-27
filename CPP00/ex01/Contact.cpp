/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:21:16 by davidjwp          #+#    #+#             */
/*   Updated: 2023/12/27 18:53:20 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact (int i): Index(i){
	this->set = false;
}

Contact::Contact (){
	this->set = false;
}

Contact::~Contact (void){
}

void	Contact::getCont (void) const
{
	std::cout << "First name: " << this->_fname << std::endl;
	std::cout << "Last name: " << this->_lname << std::endl;
	std::cout << "Nickname: " << this->_nname << std::endl;
	std::cout << "Phone Number: " << this->_pnumb << std::endl;
	std::cout << "Darkest Secret: " << this->_dsecr << std::endl;
}

void	Contact::getInfo (void) const
{
	std::cout << std::setw(10) << this->Index << '|';
	std::cout << std::setw(10) << (this->_fname.size() > 10 ? this->_fname.substr(0, 9) + '.' : this->_fname) << '|';
	std::cout << std::setw(10) << (this->_lname.size() > 10 ? this->_lname.substr(0, 9) + '.' : this->_lname) << '|';
	std::cout << std::setw(10) << (this->_nname.size() > 10 ? this->_nname.substr(0, 9) + '.' : this->_nname) << std::endl;
}

void	Contact::emptyContact (void)
{
	this->_fname.clear();
	this->_lname.clear();
	this->_nname.clear();
	this->_pnumb.clear();
	this->_dsecr.clear();
	this->set = false;
	std::cout <<  RED << "Error empty Contact info" << RES << std::endl;
}

void	Contact::add (void)
{
	
	std::cout << "First name: ";
	std::getline(std::cin, this->_fname);
	std::cout << "Last name: ";
	std::getline(std::cin, this->_lname);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->_nname);
	std::cout << "Phone Number: ";
	std::getline(std::cin, this->_pnumb);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, this->_dsecr);
	this->set = true;
	if (!*this->_fname.c_str()|| \
		!*this->_lname.c_str()|| \
		!*this->_nname.c_str()||\
		!*this->_pnumb.c_str()||\
		!*this->_dsecr.c_str())
		this->emptyContact();
}
