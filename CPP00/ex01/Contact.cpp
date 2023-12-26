/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:21:16 by davidjwp          #+#    #+#             */
/*   Updated: 2023/12/26 20:14:56 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(int i): Index(i){
	this->set = false;
}

Contact::Contact(){
	this->set = false;
}

Contact::~Contact(void){
}

void	Contact::getCont(void) const
{
	std::cout << "First name: " << this->fname << std::endl;
	std::cout << "Last name: " << this->lname << std::endl;
	std::cout << "Nickname: " << this->nname << std::endl;
	std::cout << "Phone Number: " << this->pnumb << std::endl;
	std::cout << "Darkest Secret: " << this->dsecr << std::endl;
}

void	Contact::getInfo(void) const
{
	std::cout << std::setw(11) << this->Index << '|';
	std::cout << std::setw(11) << (this->fname.size() > 10 ? this->fname.substr(0, 9) + '.' : this->fname) << '|';
	std::cout << std::setw(11) << (this->lname.size() > 10 ? this->lname.substr(0, 9) + '.' : this->lname) << '|';
	std::cout << std::setw(11) << (this->nname.size() > 10 ? this->nname.substr(0, 9) + '.' : this->nname) << std::endl;
}

void	Contact::add (void)
{
	std::cout << "First name: ";
	std::cin >> this->fname;
	//std::cout << std::endl;	
	
	std::cout << "Last name: ";
	std::cin >> this->lname;
	std::cin.clear();
	//std::cout << std::endl;

	std::cout << "Nickname: ";
	std::cin >> this->nname;
	//std::cout << std::endl;
	std::cin.clear();

	std::cout << "Phone Number: ";
	std::cin >> this->pnumb;
	//std::cout << std::endl;
	
	
	std::cout << "Darkest Secret: ";
	std::cin >> this->dsecr;
	//std::cout << std::endl;
	
	this->set = true;
}
