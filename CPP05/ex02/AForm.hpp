/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:28:15 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/14 20:40:56 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>

class Bureaucrat;

class AForm
{
	
private:

	const std::string target;
	const char* name;
	bool		Signed;
	const int	GradeToSign;
	const int	GradeToExecute;

public:

	AForm();
	AForm(AForm& F);
	AForm(const char* Target, const char *Name, const int GTS, const int GTE);
	virtual ~AForm();

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
		const char* what() const throw(){return "Error Grade lower than GradeToSign";}
	};
	class GTSTooHigh: public std::exception{
	public:
		const char* what() const throw(){return "Error GradeToSign too high";}
	};
	class GTETooLow: public std::exception{
	public:
		const char* what() const throw(){return "Error Grade lower than GradeToExecute";}
	};
	class GTETooHigh: public std::exception{
	public:
		const char* what() const throw(){return "Error GradeToExecute too high";}
	};
	class AlreadySigned: public std::exception{
	public:
		const  char* what() const throw(){return "Error form is already signed";}
	};
	class NotSigned: public std::exception{
	public:
		const char* what() const throw(){return "Error form is not signed";}
	};
	AForm& operator=(AForm& F);

	virtual char *getName() const;
	bool	getSigned();
	int	getGTS() const;
	int	getGTE() const;
	const std::string	getTarget() const;

	void	beSigned(Bureaucrat& B);
	void	signForm();

	static int evalGTS(const int grade);
	static int evalGTE(const int grade);
	void setAttributes(const char *N, bool Signed);
	void execute(Bureaucrat const & executor) const;
	virtual void action(std::string) const= 0;
};

std::ostream& operator<<(std::ostream& o, AForm& F);

#endif