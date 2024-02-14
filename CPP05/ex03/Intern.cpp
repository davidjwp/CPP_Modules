/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:55:18 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/14 23:11:28 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){
	forms[0] = new PresidentialPardonForm();
	forms[1] = new RobotomyRequestForm();
	forms[2] = new ShrubberyCreationForm();
}

Intern::Intern(Intern& cpy)
{
	forms[0] = cpy.forms[0];
	forms[1] = cpy.forms[1];
	forms[2] = cpy.forms[2];
}

Intern::~Intern(){
	delete forms[0];
	delete forms[1];
	delete forms[2];
}

AForm* Intern::makeForm(const char* FormName, const char* TargetForm){
	std::string fStrings[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	std::string Name(FormName);

	int	i = 0;
	while (i < 3)
		Name.compare(fStrings[i]) ? i++ : throw Intern::FormDoesNotExist();

	std::cout << "Intern creates " << FormName << std::endl;
	return forms[i]->clone(TargetForm);
}

Intern& Intern::operator=(Intern& ok){
	(void)ok;
return *this;
}