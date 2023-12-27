/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:21:16 by davidjwp          #+#    #+#             */
/*   Updated: 2023/12/27 15:21:34 by djacobs          ###   ########.fr       */
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
	std::cout << "First name: " << this->fname << std::endl;
	std::cout << "Last name: " << this->lname << std::endl;
	std::cout << "Nickname: " << this->nname << std::endl;
	std::cout << "Phone Number: " << this->pnumb << std::endl;
	std::cout << "Darkest Secret: " << this->dsecr << std::endl;
}

void	Contact::getInfo (void) const
{
	std::cout << std::setw(10) << this->Index << '|';
	std::cout << std::setw(10) << (this->fname.size() > 10 ? this->fname.substr(0, 9) + '.' : this->fname) << '|';
	std::cout << std::setw(10) << (this->lname.size() > 10 ? this->lname.substr(0, 9) + '.' : this->lname) << '|';
	std::cout << std::setw(10) << (this->nname.size() > 10 ? this->nname.substr(0, 9) + '.' : this->nname) << std::endl;
}

void	Contact::emptyContact (void)
{
	this->fname.clear();
	this->lname.clear();
	this->nname.clear();
	this->pnumb.clear();
	this->dsecr.clear();
	this->set = false;
	std::cout RED << "" << std::endl;
}

void	Contact::add (void)
{
	
	std::cout << "First name: ";
	std::getline(std::cin, this->fname);
	std::cout << "Last name: ";
	std::getline(std::cin, this->lname);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->nname);
	std::cout << "Phone Number: ";
	std::getline(std::cin, this->pnumb);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, this->dsecr);
	this->set = true;
	if (!*this->fname.c_str()|| \
		!*this->lname.c_str()|| \
		!*this->nname.c_str()||\
		!*this->pnumb.c_str()||\
		!*this->dsecr.c_str())
		this->emptyContact();
}
