/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:28:15 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/10 21:44:37 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Form
{
	
private:

	const char* name;
	bool		Signed;
	const int	GradeToSign;
	const int	GradeToExecute;

public:

	Form();
	Form(Form& F);
	Form(const char *N, bool S, const int GTS, const int GTE);
	~Form();

	class GradeTooHighException: public std::exception{
	public:
		const char* what() const throw(){return "Error grade too high";}
	};
	class GradeTooLowException: public std::exception{
	public:
		const char* what() const throw(){return "Error grade too low";}
	};
	Form& operator=(Form& F);

	const char *getName();
	bool		getSigned();
	const int	getGTS();
	const int	getGTE();

	void	beSigned(Bureaucrat& B);


};

std::ostream& operator<<(std::ostream& o, Form& F);

#endif