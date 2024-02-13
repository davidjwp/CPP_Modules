/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:38:32 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/13 18:38:45 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>


PresidentialPardonForm::PresidentialPardonForm(): AForm("default PresidentialPardonForm", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& cpy): AForm(cpy){}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& P){setAttributes(P.getName(), P.getSigned()); return *this;}

void PresidentialPardonForm::action(std::string target)const{
	std::cout << target << " has been pardoned by " << 
	"\033[103,93m" << "Zaphod Beeblebrox" << "\033[0m" << std::endl;
}