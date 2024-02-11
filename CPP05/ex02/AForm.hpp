/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:28:15 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/11 21:20:33 by djacobs          ###   ########.fr       */
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

	const char* name;
	bool		Signed;
	const int	GradeToSign;
	const int	GradeToExecute;

public:

	AForm();
	AForm(AForm& F);
	AForm(const char *N, const int GTS, const int GTE);
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
	AForm& operator=(AForm& F);

	virtual char *getName() = 0;
	virtual bool	getSigned();
	virtual int	getGTS();
	virtual int	getGTE();

	virtual void	beSigned(Bureaucrat& B);
	virtual void	signForm();

	static int evalGTS(const int grade);
	static int evalGTE(const int grade);
	void setAttributes(const char *N, bool Signed);

};

std::ostream& operator<<(std::ostream& o, AForm& F);

#endif