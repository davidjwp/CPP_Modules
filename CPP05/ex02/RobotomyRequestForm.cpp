/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:24:49 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/13 18:39:34 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("default Robot form", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(const char *N): AForm(N, 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& R): AForm(R){}

RobotomyRequestForm::~RobotomyRequestForm(void){}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& R){setAttributes(R.getName(), R.getSigned()); return *this;}

void	RobotomyRequestForm::action(std::string target)const{ 
	if (rand() >= (RAND_MAX / 2)){
		std::cout << "*** Dzzzzzzzzz... *** " << target << " has been robotomized successfully";
	}
	else{
		std::cout << "*** Dzzzzzzzzz... *** " << target << "'s robotomy has failed";
	}
}