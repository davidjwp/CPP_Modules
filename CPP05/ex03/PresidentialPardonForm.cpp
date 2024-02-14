/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:38:32 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/14 23:08:20 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>


PresidentialPardonForm::PresidentialPardonForm(): AForm("default PresidentialPardonForm target", "default PresidentialPardonForm", 25, 5){target = std::string("john");}

PresidentialPardonForm::PresidentialPardonForm(const char* T): AForm(T, "PresidentialPardonForm", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& cpy): AForm(cpy){}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& P){setAttributes(P.getName(), P.getSigned()); return *this;}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::action(std::string Target)const{
	std::cout << Target << " has been pardoned by " << 
	"\033[103,93m" << "Zaphod Beeblebrox" << "\033[0m" << std::endl;
}

AForm* PresidentialPardonForm::clone(const char* target){return new PresidentialPardonForm(target);}