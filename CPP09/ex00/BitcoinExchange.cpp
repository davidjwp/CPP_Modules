/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:23:50 by djacobs           #+#    #+#             */
/*   Updated: 2024/04/29 21:47:57 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <list>

Smallest::Smallest(){}

Smallest::~Smallest(){}

Smallest::Smallest(const Smallest& cpy): _target(cpy._target){}

Smallest& Smallest::operator=(const Smallest& as){_target = as._target; return *this;}

Smallest::Smallest(const lint target): _target(target){}

bool Smallest::operator()(lint A, lint B) const{ return std::abs(A - _target) < std::abs(B - _target);}

const char* Error::what() const throw() {return _msg.c_str();}

Error::Error(): _msg(std::string("Error: ")){}

Error::Error(const char* msg): _msg(std::string("Error: ") + msg){}

Error::Error(const Error& cpy): _msg(cpy._msg){}

Error::~Error() throw() {}

Error& Error::operator=(const Error& as){_msg = as._msg; return *this;}

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(BitcoinExchange& cpy){(void)cpy;}

//both constructor for the object and the "main" function.
BitcoinExchange::BitcoinExchange(std::ifstream& input_file){
	unsigned short int l_num = 0;
	CSV.open("data.csv");

	//checks if the file is open properly
	if (!CSV.is_open()){input_file.close(); throw Error("could not open file");}
	//this function creates the date and value vector from the csv file, it also throws.
	_BitcoinExchange();

	//creating the variables for the line, the input file values and date, the float and long int of the value and date.
	std::string line;
	std::string file_val;
	std::string file_date;
	float	val;
	lint	dat;
	std::list<lint>::iterator p;//the iterator for the date vector corresponding to the input file date or the closest from it.

	//std::getline(input_file, line);
	while (input_file && !input_file.eof()){
		std::getline(input_file, line);

		//if there is a line and the date evaluation isn't 0 meaning that the date is correct.
		if (line[0] && (dat = eval_date(file_date = std::string(line.substr(0, line.find_first_of('|'))), "input_file")) != 0) {
			
			//create the date iterator using find, if the date is not found then look the closest date using a functor
			if ((p = std::find(date.begin(), date.end(), dat)) == date.end()) 
				p = std::min_element(date.begin(), date.end(), Smallest(dat));
			
			//check that the input file value has numbers and therefore is there
			if ((file_val = std::string(line.substr(line.find_first_of('|') + 1, line.length()))).find_first_of("0123456789", 0) == std::string::npos) 
				std::cerr << "Error: no value." << std::endl;
			
			//check the value and print if good
			val = atof(file_val.c_str());
			if (val < 0) std::cerr << "Error: not a positive number." << std::endl;
			else if (val >= 1000.0) std::cerr << "Error: too large a number." << std::endl;
			else std::cerr << file_date << " => " << val << " = " << cal_values(p, val) << std::endl;
			l_num++;
		}
	}
	std::distance(date.begin(), date.end());
}

//using the date list iterator to find the corresponding position in the value list the result of the input file value times the csv value is calculated.
float BitcoinExchange::cal_values(std::list<lint>::iterator p, float val) { 
	size_t dis = std::distance(date.begin(), p);
	std::list<float>::iterator i = value.begin();
	std::advance(i, dis);
	return val * *i;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& C){(void)C; return C;}

//resets the file buffer, this isn't really needed tbh.
void BitcoinExchange::reset_buffer(){CSV.clear(); CSV.seekg(0); /*index = 0;*/} 

/*
evaluates the date in string format and returns the encoded version, in case of an error throws an exception for the "CSV" file
and returns 0 for the "input_file".
*/
lint	BitcoinExchange::eval_date(std::string string_date, std::string File){
	sint	year, month, day;

	year = atoi(string_date.substr(0, string_date.find_first_of('-')).c_str());
	month = atoi(string_date.substr(string_date.find_first_of('-') + 1, string_date.find_last_of('-')).c_str());
	day = atoi(string_date.substr(string_date.find_last_of('-') + 1, string_date.length()).c_str());
	
	if (!File.compare("CSV"))
		date.push_back(BitcoinExchange::encode(year, month, day));
	return BitcoinExchange::encode(year, month, day);
}

//create the date and value vector from the csv file, throws an exception if the csv file is bad.
void BitcoinExchange::_BitcoinExchange(){
	unsigned int short l_num = 0;
	std::string file("CSV");
	std::string	line;
	
	std::getline(CSV, line);

	while (CSV){
		std::getline(CSV, line);
		if (line[0]) {
			eval_date(line.substr(0, line.find_first_of(',')), "CSV");

			line = line.substr(line.find_first_of(',') + 1, line.length());
			if (!line[0] || line[0] == 32) throw Error("File has bad values");
			float tval = atof(line.c_str());
			if (tval < 0 || tval >= 2147483647.0) throw Error("File has bad values");
			value.push_back(tval);
			l_num++;
		}
	}
	reset_buffer();
}

//encode the dates into a long int type for the date vector to save space and go faster.
lint	BitcoinExchange::encode(sint year, sint month, sint day){return static_cast<lint>(year << 9) | (month << 5) | day;}
