/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:28:15 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/11 18:39:11 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>

class Bureaucrat;

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
	Form(const char *N, const int GTS, const int GTE);
	~Form();

	class GradeTooHighException: public std::exception{
	public:
		const char* what() const throw(){return "Error grade too high";}
	};
	class GradeTooLowException: public std::exception{
	public:
		const char* what() const throw(){return "Error grade too low";}
	};
	class GTSTooLow: public std::exception{
	public:
		const char* what() const throw(){return "Error GradeToSign too low";}
	};
	class GTSTooHigh: public std::exception{
	public:
		const char* what() const throw(){return "Error GradeToSign too high";}
	};
	class GTETooLow: public std::exception{
	public:
		const char* what() const throw(){return "Error GradeToExecute too low";}
	};
	class GTETooHigh: public std::exception{
	public:
		const char* what() const throw(){return "Error GradeToExecute too high";}
	};
	Form& operator=(Form& F);

	char *getName();
	bool	getSigned();
	int	getGTS();
	int	getGTE();

	void	beSigned(Bureaucrat& B);
	void	signForm();

	static int evalGTS(const int grade);
	static int evalGTE(const int grade);
};

std::ostream& operator<<(std::ostream& o, Form& F);

#endif