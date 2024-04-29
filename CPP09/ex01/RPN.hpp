/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:53:00 by djacobs           #+#    #+#             */
/*   Updated: 2024/04/29 21:56:57 by djacobs          ###   ########.fr       */
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
#define IT_INDEX(str, i) (static_cast<long unsigned int>(std::distance(str.begin(), i)))
#define FIND(str, chars) (str.find_first_of(chars))
#define FINDL(str, chars) (str.find_last_of(chars))
#define ATOI_STR(str, i) (atof(str.substr(i - str.begin(), num_len(i)).c_str()))

class RPN{
private:
	std::stack<float>	_table;

	RPN();
	RPN(RPN&);

	RPN& operator=(RPN&);
	void parsing(std::string);

	float bottom(std::stack<float>) const;
	float operand(std::stack<float>) const;
	float operation(float, char, float) const;
	char find_op() const;
	bool is_operation(char) const;
	float num_len(std::string::iterator) const;

public:
	RPN(std::string);
	~RPN();
	
	void calculate();
	bool is_op(char c);
};

class Error: std::exception{
private:
	std::string _msg;

public:
	Error();
	virtual ~Error() throw();
	Error(const char*);
	Error(const Error&);
	
	Error& operator=(const Error&);
	const char* what() const throw();
};

#endif