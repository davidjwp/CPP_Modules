/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:22:15 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/28 20:50:35 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <exception>
#include <string>


int	main(void)
{
	try {
		Bureaucrat dude("john", 5);
		PresidentialPardonForm form(dude.getName());
		dude.signForm(form);
		dude.executeForm(form);
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n' << std::endl;
	}
	try {
		Bureaucrat dude("pizza", 121);
		ShrubberyCreationForm form("big");
		dude.signForm(form);
		dude.executeForm(form);
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n'  << std::endl;
	}
	try {
		Bureaucrat dude("spaghetti", 43);
		RobotomyRequestForm	form("gagaga");
		dude.signForm(form);
		dude.executeForm(form);
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n'  << std::endl;
	}
	try {
		Bureaucrat dude("corndogs", 23);
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n'  << std::endl;
	}
	try {
		Bureaucrat dude("falafel", 150);
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n'  << std::endl;
	}
	return 0;
}