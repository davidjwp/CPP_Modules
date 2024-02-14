/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:28:06 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/14 23:05:50 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

//default constructor
AForm::AForm(void): target(std::string("default target")), name("default form"), Signed(false), GradeToSign(0), GradeToExecute(0){}

//copy constructor
AForm::AForm(AForm& F): target(F.getTarget()), name(F.getName()), Signed(F.getSigned()), GradeToSign(F.getGTS()), GradeToExecute(F.getGTE()){}

//destructor
AForm::~AForm(void){}

//throw exception if gradetosign isn't right
int AForm::evalGTS(const int grade){
	if (grade < 1)
		throw AForm::GTSTooHigh();
	else if (grade > 150)
		throw AForm::GTSTooLow();
	return grade;
}

//throw exception if gradetoexecute isn't right
int AForm::evalGTE(const int grade){
	if (grade < 1)
		throw AForm::GTETooHigh();
	else if (grade > 150)
		throw AForm::GTETooLow();
	return grade;
}

//assignement constructor, throw exception if bad values
AForm::AForm(const char* T, const char *N, const int GTS, const int GTE): target(std::string(T)), name(N), Signed(false), 
GradeToSign(AForm::evalGTS(GTS)), GradeToExecute(AForm::evalGTE(GTE)){}

//getter name
char * AForm::getName(void) const{ return (char*)name;}

//getter signed
bool	AForm::getSigned(void){ return Signed;}

//getter gradetosign
int AForm::getGTS(void) const{ return GradeToSign;}

//getter gradetoexecute
int AForm::getGTE(void) const{ return GradeToExecute;}

//getter target
const std::string AForm::getTarget(void) const{ return target;}

//throw exception if Bureaucrat grade is too low or alreadysigned
void	AForm::beSigned(Bureaucrat& B){
	if (Signed)
		throw AForm::AlreadySigned();
	if (Bureaucrat::getGrade(B) <= getGTS())
		Signed = true;
	else
		throw AForm::GTSTooLow();
}

void	AForm::setAttributes(const char *N, bool S){
	if (N)
		name = N;
	else
		name = "(null)";
	Signed = S;
}

void	AForm::execute(Bureaucrat const &B) const{
	if (!Signed)
		throw AForm::NotSigned();
	if (Bureaucrat::getGrade(B) <= getGTE())
		action(target);
	else throw AForm::GTETooLow();
}
