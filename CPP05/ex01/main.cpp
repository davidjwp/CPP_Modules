/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:22:15 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/11 18:57:16 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

int	main(void)
{
	Form	F1("B12", 16, 12);

	try {
		Form	F1("B12", 16, 12);
		Bureaucrat dude("john", 3);
		std::cout << dude << '\n' << std::endl;
		dude.signForm(F1);
		dude.signForm(F1);
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n' << std::endl;
	}
	try {
		Form	F1("B12", 0, 12);
		Bureaucrat dude("pizza", 0);
		std::cout << dude << '\n' << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n'  << std::endl;
	}
	try {
		Form	F1("B12", 160, 12);
		Bureaucrat dude("spaghetti", 151);
		std::cout << dude << '\n' << std::endl;
		Bureaucrat::increaseGrade(dude);
		std::cout << dude << '\n' << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n'  << std::endl;
	}
	try {
		Form	F1("B12", 16, 12);
		Bureaucrat dude("corndogs", 1);
		Bureaucrat::increaseGrade(dude);
		std::cout << dude << '\n' << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n'  << std::endl;
	}
	try {
		Form	F1("B12", 16, 12);
		Bureaucrat dude("falafel", 150);
		Bureaucrat::decreaseGrade(dude);
		std::cout << dude << '\n' << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n'  << std::endl;
	}
	
	return 0;
}