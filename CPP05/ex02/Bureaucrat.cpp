/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:24:56 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/14 20:25:22 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <exception>
#include <string>

Bureaucrat::Bureaucrat(void): name("john"), grade(0), target(std::string("default target")){}

Bureaucrat::~Bureaucrat(void){}

Bureaucrat::Bureaucrat(Bureaucrat& B): name(B.getName()), grade(Bureaucrat::getGrade(B)), target(std::string(B.target.c_str())){}

Bureaucrat::Bureaucrat(const char* name, int g): name(name)
{
	if (g < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (g > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = g;
}

const char* Bureaucrat::getName(void){return name;}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat& B){
	grade = B.grade;
	target = std::string(B.target.c_str());
	return *this;
}

int Bureaucrat::getGrade(Bureaucrat const& B){return B.grade;}

void Bureaucrat::increaseGrade(Bureaucrat& B){ 
	if (Bureaucrat::getGrade(B) > 1) B.grade -= 1;
	else throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade(Bureaucrat& B){
	if (Bureaucrat::getGrade(B) < 150) B.grade += 1;
	else throw Bureaucrat::GradeTooLowException();
}

bool Bureaucrat::threwException(void){ if (grade < 1 || grade > 150) return true; return false;}

std::ostream& operator<<(std::ostream& o, Bureaucrat& B){
	o << B.getName() << ", bureaucrat grade " << Bureaucrat::getGrade(B) << ".";
	return o;
}

void	Bureaucrat::signForm(AForm& F){
	if (Bureaucrat::getGrade(*this) <= F.getGTS()){
		F.beSigned(*this);
		std::cout << name << " signed " << F.getName() << std::endl;
	}
	else
		throw AForm::GTSTooLow();
}

void	Bureaucrat::executeForm(AForm const& form){
	try { 
		form.execute(*this);
		std::cout << getName() << " " << "executed " << form.getName() << std::endl;
	}
	catch (std::exception & E)
	{ 
		std::cout << "Exception: " << getName() << ": " << E.what() << "\n" << std::endl;
	}
}
