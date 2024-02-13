/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:25:13 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/13 18:16:55 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <exception>
# include <iostream>

class Bureaucrat
{

public:
	const char* name;
	int	grade;
	std::string target;

	Bureaucrat(void);
	Bureaucrat(int g);
	Bureaucrat(Bureaucrat&);
	Bureaucrat(const char *name, int g);
	~Bureaucrat(void);

	Bureaucrat& operator=(Bureaucrat& B1);

	const char* getName(void);
	static int	getGrade(Bureaucrat const& B);

	class GradeTooHighException: public std::exception {
	public:
		const char* what() const throw(){ return "Error grade too high";}
	};
	class GradeTooLowException: public std::exception {
	public:
		const char * what() const throw(){ return "Error grade too low";}
	};

	static void	increaseGrade(Bureaucrat& B);
	static void decreaseGrade(Bureaucrat& B);

	bool	threwException(void);

	void	signForm(AForm& F);
	void	executeForm(AForm const&);
};

std::ostream& operator<<(std::ostream& o, Bureaucrat& instance);

#endif