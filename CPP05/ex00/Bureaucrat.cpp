/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:24:56 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/08 20:25:28 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

Bureaucrat::Bureaucrat(void): name("john"){
	grade = 0;
}

Bureaucrat::~Bureaucrat(void){}

Bureaucrat::Bureaucrat(Bureaucrat& B): name(B.getName()), grade(B.getGrade()){}

Bureaucrat::Bureaucrat(const char* name, int g): name(name)
{
	if (g < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (g > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat& B){
	grade = B.grade;
	return *this;
}

const char* Bureaucrat::what() const throw(){return "ok";}

bool	Bureaucrat::GradeIsBad(int &g) const{return g < 1 || g > 150 ? true : false;}

int Bureaucrat::getGrade(void){return grade;}

const char* Bureaucrat::getName(void){return name;}
