/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:58:09 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/13 23:43:18 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>

RPN::RPN(){}

RPN::RPN(std::string op){
	op_num(op);
}

void RPN::calculate(void){
	if (values.size() <= operations.size()) throw MalformedExpression();

	while (!operations.empty()){
		
	}
}

RPN::RPN(RPN& cpy){(void)cpy;}

RPN& RPN::operator=(RPN& R){(void)R;}

const bool RPN::is_op(char c){return c == 47 || c == 45 || c == 43 || c == 42 ? true : false;}

//parsing through the input, throws an exception if and error is found
void RPN::op_num(std::string op){

	//first checks to make sure that the string is not empty and isn't missing anything
	if (!op.size() || FIND(op, "0123456789/+-*") == SFAIL) throw EmptyString();
	if (FIND(op, OP) == SFAIL) throw MissingOperations();
	if (FIND(op, NUM) == SFAIL) throw MissingOperands();

	//finds any non number or operation character
	for (std::string::iterator i = op.begin(); i != op.end(); i++)
		if(!(*i >= 48 && *i <= 57 || (*i == 47 || *i == 45 || *i == 43 || *i == 42 || *i == 32))) throw WrongInput();

	//if the first operation is the first character and the next one is a num or an operation then throw an exception 
	if ((FIND(op, OP) == 0) && (FIND(op, "0123456789/+-*") == 1)) throw MissingSpace();

	//find any operation touching a number, loop and 'cut' the string until no more operations are found 
	for (std::string str(op.substr(FIND(op, OP) - 1, op.size() - FIND(op, OP) - 1)); FIND(str, OP) != SFAIL; str = str.substr(FIND(str, OP) - 1, str.size() - FIND(str, OP) - 1))
		if (FIND(str, NUM) == 0 || FIND(str, NUM) == 2) throw MissingSpace();

	//if the number is a number is after an operation 
	if (op.find_last_of("0123456789") > FIND(op, OP)) throw NumberAfterOperation();

	int			val;
	while (op.size() != std::string::npos){
		std::string::iterator i = op.begin();
		op = op.substr(i - op.begin(), op.size() - (i - op.begin()));//cuts op by the i'th progress.

		std::string str(op, (i - op.begin()), FIND(op, OP) - 1);
		if (FIND(std, NUM) != SFAIL){
			val = atoi(str.c_str());
			if (val > 10) throw ValueTooHigh();
			if (val < 0) throw NegativeValue();
			else values.push(static_cast<suint>(val));
		}
		else if ()
		
	}
}

/*
all errors not handled 

" 1 2 3 + *"

"1+"things are separated by spaces
*/
RPN::~RPN(){}