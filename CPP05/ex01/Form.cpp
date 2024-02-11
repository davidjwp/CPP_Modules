/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:28:06 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/11 18:34:21 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(void): name("default form"), Signed(false), GradeToSign(0), GradeToExecute(0){}

Form::Form(Form& F): name(F.getName()), Signed(F.getSigned()), GradeToSign(F.getGTS()), GradeToExecute(F.getGTE()){}

Form::~Form(void){}

int Form::evalGTS(const int grade){
	if (grade < 1)
		throw Form::GTSTooHigh();
	else if (grade > 150)
		throw Form::GTSTooLow();
	return grade;
}

int Form::evalGTE(const int grade){
	if (grade < 1)
		throw Form::GTETooHigh();
	else if (grade > 150)
		throw Form::GTETooLow();
	return grade;
}

Form::Form(const char *N, const int GTS, const int GTE): name(N), 
GradeToSign(Form::evalGTS(GTS)), GradeToExecute(Form::evalGTE(GTE)){}

char * Form::getName(void){ return (char*)name;}

bool	Form::getSigned(void){ return Signed;}

int Form::getGTS(void){ return GradeToSign;}

int Form::getGTE(void){ return GradeToExecute;}

void	Form::beSigned(Bureaucrat& B){
	if (!Signed && B.getGrade() <= getGTS())
		Signed = true;
	else if ( B.getGrade() > getGTS())
		throw Form::GTSTooHigh();
}
