/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:24:56 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/11 18:53:37 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

Bureaucrat::Bureaucrat(void): name("john"), grade(0){}

Bureaucrat::~Bureaucrat(void){}

Bureaucrat::Bureaucrat(Bureaucrat& B): name(B.getName()), grade(B.getGrade()){}

Bureaucrat::Bureaucrat(const char* name, int g): name(name)
{
	if (g < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (g > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = g;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat& B){
	grade = B.grade;
	return *this;
}

int Bureaucrat::getGrade(void){return grade;}

const char* Bureaucrat::getName(void){return name;}

void Bureaucrat::increaseGrade(Bureaucrat& B){ 
	if (B.getGrade() > 1) B.grade -= 1;
	else throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade(Bureaucrat& B){
	if (B.getGrade() < 150) B.grade += 1;
	else throw Bureaucrat::GradeTooLowException();
}

bool Bureaucrat::threwException(void){ if (grade < 1 || grade > 150) return true; return false;}

std::ostream& operator<<(std::ostream& o, Bureaucrat& B){
	o << B.getName() << ", bureaucrat grade " << B.getGrade() << ".";
	return o;
}

void	Bureaucrat::signForm(Form& F){
	if (!F.getSigned() && F.getGTS() >= getGrade()){
		F.beSigned(*this);
		std::cout << name << " signed " << F.getName() << std::endl;
	}
	else
		std::cout << name << " couldn't sign " << F.getName() << " because " << 
		(!(F.getGTS() >= getGrade()) ? "the grade is not high enough " : "the form is already signed") << std::endl;
}
