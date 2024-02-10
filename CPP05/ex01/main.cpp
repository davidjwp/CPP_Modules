/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:22:15 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/10 21:20:06 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int	main(void)
{
	try {
		Bureaucrat dude("john", 150);
		std::cout << dude << '\n' << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n' << std::endl;
	}
	try {
		Bureaucrat dude("pizza", 0);
		std::cout << dude << '\n' << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n'  << std::endl;
	}
	try {
		Bureaucrat dude("spaghetti", 151);
		std::cout << dude << '\n' << std::endl;
		Bureaucrat::increaseGrade(dude);
		std::cout << dude << '\n' << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n'  << std::endl;
	}
	try {
		Bureaucrat dude("corndogs", 1);
		Bureaucrat::increaseGrade(dude);
		std::cout << dude << '\n' << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n'  << std::endl;
	}
	try {
		Bureaucrat dude("falafel", 150);
		Bureaucrat::decreaseGrade(dude);
		std::cout << dude << '\n' << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n'  << std::endl;
	}
	
	return 0;
}