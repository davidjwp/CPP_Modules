/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:53:01 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/14 22:50:07 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <exception>


class Intern
{
public:
	AForm *forms[3];

	Intern();
	Intern(Intern&);
	~Intern();
	
	class FormDoesNotExist: public std::exception {
	public:
		const char* what() const throw(){ return "This form does not exist";}
	};

	AForm* makeForm(const char* NameForm, const char* TargetForm);
	Intern& operator=(Intern&);
};

#endif