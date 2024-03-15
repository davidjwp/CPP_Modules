/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:53:00 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/15 02:33:15 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <exception>
#include <string>

#define NUMOP "0123456789/-+*"
#define NUM "0123456789"
#define OP "/-+*"
#define SFAIL std::string::npos
#define IT_INDEX(str, i) (std::distance(str.begin(), i))
#define FIND(str, chars) (str.find_first_of(chars))
#define FINDL(str, chars) (str.find_last_of(chars))
#define ATOI_STR(str, i) (atoi(str.substr(i - str.begin(), num_len(i)).c_str()))

class RPN{
private:
	std::stack<size_t>	_table;
	//std::stack<char>	_operation;

	RPN();
	RPN(RPN&);

	RPN& operator=(RPN&);
	void parsing(std::string);

	size_t bottom(std::stack<size_t>) const;
	size_t operation(size_t, char, size_t) const;
	char find_op() const;
	bool is_operation(char) const;
	size_t num_len(std::string::iterator) const;

//	Exceptions //============================================================//
	class WrongInput: public std::exception{
	public:
		const char* what() const throw() { return "Error: Wrong input";}
	};
	class ValueTooHigh: public std::exception{
	public:
		const char* what() const throw() { return "Error: Values too high";}
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

public:
	RPN(std::string);
	~RPN();
	
	void calculate();
	bool is_op(char c);
};

#endif