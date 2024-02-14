/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:22:15 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/14 23:34:14 by djacobs          ###   ########.fr       */
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
#include "Intern.hpp"


int	main(void)
{
	try {
		Intern	dude;
		AForm* rrf;

		rrf = dude.makeForm("RobotomyRequestForm", "Bender");
		delete rrf;
	}
	catch (std::exception& e){
		std::cout << "Error:  "<<  e.what() << std::endl;
	}
	return 0;
}