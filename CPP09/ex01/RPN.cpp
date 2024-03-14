/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:58:09 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/14 04:00:57 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

RPN::RPN(){}

RPN::RPN(std::string op){
	op_num(op);
}

RPN::RPN(RPN& cpy){(void)cpy;}

RPN& RPN::operator=(RPN& R){(void)R; return *this;}

bool RPN::is_op(char c){return c == 47 || c == 45 || c == 43 || c == 42 ? true : false;}

//parsing through the input, throws an exception if and error is found
void RPN::op_num(std::string op){

	//first checks to make sure that the string is not empty and isn't missing anything
	if (!op.size() || FIND(op, "0123456789/+-*") == SFAIL) throw EmptyString();
	if (FIND(op, OP) == SFAIL) throw MissingOperations();
	if (FIND(op, NUM) == SFAIL) throw MissingOperands();

	//finds any non number or operation character
	for (std::string::iterator i = op.begin(); i != op.end(); i++)
		if(!((*i >= 48 && *i <= 57) || (*i == 47 || *i == 45 || *i == 43 || *i == 42 || *i == 32))) throw WrongInput();

	//find any operation touching a number, loop and 'cut' the string until no more operations are found 
	//for (std::string str(op.substr(FIND(op, OP) - 1, op.size() - (FIND(op, OP) - 1))); FIND(str, OP) != SFAIL || !str.empty() ; str = str.substr(FIND(str, OP) + 1, str.size() - (FIND(str, OP) - 1)))
	//	if (FIND(str, NUM) == 0 || FIND(str, NUM) == 2) throw MissingSpace();
	
	//operators can be after a value but one thing is certain the operation MUST have at least two numbers at the beginning 
	//it MUST also not have the same amount of operators, the number of operators is always one less than the total number of numbers
	//the orde of the operators matters alot so you should push things on the stack in the order you see them in the operation
	//the two first elements must be numbers
	//READ THE RPN!!!

	//this loop will find the operators, cut them from the string and put them in the stack
	//then the string is cut from the last found num/op, this is done again for the numbers
	while (FIND(op, "0123456789/*-+") != SFAIL){		
		int len = op.size() - FINDL(op, "0123456789/*-+");
		//substring of the last thing
		std::string str = op.substr(FINDL(op, "0123456789/*-+"), len);

		//if there is an operation then push the operation to the stack, else same with values
		if (FINDL(op ,OP) != SFAIL) _operations.push(str.c_str()[FIND(str, OP)]);
		else if (FINDL(op, NUM) != SFAIL){
			int value = atoi(str.c_str());
			if (value > 10) throw ValueTooHigh();
			_values.push(value);
		}
		
		op.resize(op.size() - len);
	}
}

/*
all errors  

" 1 2 3 + *"

*/
RPN::~RPN(){}