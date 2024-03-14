/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:53:00 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/14 03:58:12 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <exception>
#include <string>

#define NUM "0123456789"
#define OP "/-+*"
#define SFAIL std::string::npos
#define FIND(str, chars) (str.find_first_of(chars))
#define FINDL(str, chars) (str.find_last_of(chars))

typedef short unsigned int suint;

class RPN{
private:
	std::stack<suint>	_values;
	//std::stack<char>	_operations;

	RPN();
	RPN(RPN&);

	RPN& operator=(RPN&);
	void op_num(std::string);

//	Exceptions //============================================================//
	class MalformedExpression: public std::exception{
	public:
		const char* what() const throw(){ return "Error: Malformed expression";}
	};
	class WrongInput: public std::exception{
	public:
		const char* what() const throw() { return "Error: Wrong input";}
	};
	class ValueTooHigh: public std::exception{
	public:
		const char* what() const throw() { return "Error: Values too high";}
	};
	class NegativeValue: public std::exception{
	public:
		const char* what() const throw() { return "Error: Negative value";}
	}; 
	class EmptyString: public std::exception{
	public:
		const char* what() const throw() { return "Error: Empty string";}
	};
	class MissingOperations: public std::exception{
	public:
		const char* what() const throw() { return "Error: Missing operations";}
	};
	class MissingOperands: public std::exception{
	public:
		const char* what() const throw() { return "Error: Missing operands";}	
	};
	class MissingSpace: public std::exception{
	public:
		const char* what() const throw() { return "Error: Missing space";}
	};

public:
	RPN(std::string);
	~RPN();
	
	void calculate();
	static bool is_op(char c);
};

#endif