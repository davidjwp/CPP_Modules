/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:24:49 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/14 23:08:12 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("default Robot target", "default Robot form", 72, 45){ target = std::string("john");}

RobotomyRequestForm::RobotomyRequestForm(const char* T): AForm(T, "RobotomyRequestForm", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& R): AForm(R){}

RobotomyRequestForm::~RobotomyRequestForm(void){}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& R){setAttributes(R.getName(), R.getSigned()); return *this;}

void	RobotomyRequestForm::action(std::string Target)const{ 
	srand(time(NULL));
	if (rand() > (RAND_MAX / 2)) {std::cout << "*** Dzzzzzzzzz... *** " << Target << " has been robotomized successfully" << std::endl;}
	else {std::cout << "*** Dzzzzzzzzz... *** " << Target << "'s robotomy has failed" << std::endl;}
}

AForm* RobotomyRequestForm::clone(const char* target){return new RobotomyRequestForm(target);}