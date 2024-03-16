/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:58:09 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/16 04:31:16 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iterator>
#include <stack>
#include <algorithm>
#include <climits>

RPN::RPN(){}

RPN::RPN(std::string op){parsing(op);}

RPN::RPN(RPN& cpy){(void)cpy;}

RPN& RPN::operator=(RPN& R){(void)R; return *this;}


float RPN::num_len(std::string::iterator i) const { 
	if (is_operation(*i)) i++;
	std::string::iterator len = i; 
	while (*len == 32) std::advance(len, 1);
	while ((*len >= 48 && *len <= 57)) std::advance(len, 1);
	float siz = len - i;
	(void)siz;
	return len - i;
}

bool RPN::is_operation(char c) const{return c == 47 || c == 45 || c == 43 || c == 42 ? true : false;}

char RPN::find_op() const{ for(std::stack<float> cpy(_table); !cpy.empty(); cpy.pop()) if (cpy.top() > 10) return cpy.top(); return 0;}

float RPN::operation(float A, const char c, float B) const{
	if (c == 47 && (A != 0 && B != 0)) return A / B; 
	if (c == 45) return A - B; 
	if (c == 43) return A + B; 
	if (c == 42) return A * B; 
	return 0;}

float RPN::operand(std::stack<float> stack_result) const{ std::stack<float> cpy(stack_result); cpy.pop(); return cpy.top();}

void RPN::calculate(){
	std::stack<float> stack_result;

	while (find_op()){

		if (_table.size() == 1 && _table.top() < 10) throw WrongInput();//check last one

		if (stack_result.size() >= 2 && is_operation(_table.top())) {
			char op = _table.top(); _table.pop();
			//float operand = stack_result.top();
			float result = operation(operand(stack_result), op, stack_result.top()); 
			stack_result.pop();	stack_result.pop();
			stack_result.push(result); op = 11;}
		else {stack_result.push(_table.top()); _table.pop();}
	}

	//print in reverse by making a reversed copy of the result
	std::stack<float> cpy;

	while (!stack_result.empty()) {cpy.push(stack_result.top()); stack_result.pop();}
	
	while (!cpy.empty()) {std::cout << cpy.top() << ' '; 
	cpy.pop();}
	std::cout << std::endl;
}
//"1 1  -2 / 2 1 1 1  - - - 3 3 + -"
//"  1 1 4 -  /"

//parsing through the input, throws an exception if and error is found
void RPN::parsing(std::string op){
	
	std::string str(op);

	//first checks to make sure that the string is not empty and isn't missing anything
	if (!op.size() || FIND(op, NUMOP) == SFAIL) throw EmptyString();
	if (FIND(op, OP) == SFAIL || (op[FIND(op, OP) + 1] >= 48 && op[FIND(op, OP) + 1] <= 57)) throw MissingOperations();//this is causing a problem, don't count negatives as operation
	if (FIND(op, NUM) == SFAIL) throw MissingOperands();

	//finds any non number or operation character
	for (std::string::iterator i = op.begin(); i != op.end(); i++)
		if(!((*i >= 48 && *i <= 57) || (*i == 47 || *i == 45 || *i == 43 || *i == 42 || *i == 32))) throw WrongInput();

	//put operation in the stack _table by starting at the end and progressively erasing the string, if a value is too high throws an exception
	//this stack creator is ordered meaning the top element is the first element in the operation 
	for (std::string::iterator i = str.end() - 1; FIND(str, NUMOP) != SFAIL; i = str.end() - 1){
		while (*i == 32) i--;
		if (is_operation(*i)) { _table.push(static_cast<float>(*i));    i--;}
		else { while ((i != str.begin() && *i >= 48 && *i <= 57 )|| (*i == 45 && i != str.begin())) i--;
			if (is_operation(*i)) {float val = ATOI_STR(str, i + 1);    val > 10 ? throw ValueTooHigh() : _table.push(val);}
			else {float val = ATOI_STR(str, i);    val > 10 ? throw ValueTooHigh() : _table.push(val);}}
		i == str.begin() ? str.erase(IT_INDEX(str, i)) : str.erase(IT_INDEX(str, i) + 1);
	}

	//this checks that the ratio of operators to operands is good 
	if (_table.size() < 3) throw WrongInput();
	float	ops = 0;
	float	val = 0;
	float	i = 0;
	for (std::stack<float> cpy(_table); !cpy.empty(); cpy.pop()){
		if (i < 3 && ops) throw WrongInput();
		if (cpy.top() > 10) ops++;
		else val++;
		i++;
	}
	if (ops >= val) throw WrongInput();
}

RPN::~RPN(){}

//handle negative numbers 