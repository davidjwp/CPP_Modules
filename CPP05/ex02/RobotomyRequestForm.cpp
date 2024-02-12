/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:24:49 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/12 17:39:06 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("default Robot form", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(const char *N): AForm(N, 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& R): AForm(R){}

RobotomyRequestForm::~RobotomyRequestForm(void){}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& R){setAttributes(R.getName(), R.getSigned());}

const void	RobotomyRequestForm::RobotDrill(const char *target) const{ std::cout << ;}