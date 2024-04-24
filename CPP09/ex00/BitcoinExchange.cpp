/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:23:50 by djacobs           #+#    #+#             */
/*   Updated: 2024/04/24 17:49:11 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <list>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(BitcoinExchange& cpy){(void)cpy;}

//both constructor for the object and the "main" function.
BitcoinExchange::BitcoinExchange(std::ifstream& input_file){
	unsigned short int l_num = 0;
	CSV.open("data.csv");

	//checks if the file is open properly
	if (!CSV.is_open()){input_file.close(); throw CannotOpenFile();}
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
		if (line[0] && (dat = eval_date(file_date = std::string(line.substr(0, line.find_first_of('|'))), "input_file", l_num)) != 0) {
			
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
lint	BitcoinExchange::eval_date(std::string string_date, std::string File, unsigned short int l_num){
	sint	year, month, day;

	year = atoi(string_date.substr(0, string_date.find_first_of('-')).c_str());
	month = atoi(string_date.substr(string_date.find_first_of('-') + 1, string_date.find_last_of('-')).c_str());
	day = atoi(string_date.substr(string_date.find_last_of('-') + 1, string_date.length()).c_str());
	
	if (year < 0 || month > 12 || month < 0 ||
		day > 31 || day < 0){
		if (!File.compare("CSV")) throw FilebadDay(File);
		else if (!l_num) return 0;
		else {std::cerr << "Error: bad input => " << year<<'-'<<month<<'-'<<day << std::endl; return 0;}}

	if ((month == 2 && day > 29) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
		{if (!File.compare("CSV")) throw FilebadDay(File);
		 else if (!l_num) return 0;
		 else {std::cerr << "Error: bad date => " << year<<'-'<<month<<'-'<<day << std::endl; return 0;}}

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
			eval_date(line.substr(0, line.find_first_of(',')), "CSV", l_num);

			line = line.substr(line.find_first_of(',') + 1, line.length());
			if (!line[0] || line[0] == 32) throw FileBadValue(file);
			float tval = atof(line.c_str());
			if (tval < 0 || tval >= 2147483647.0) throw FileBadValue(file);
			value.push_back(tval);
			l_num++;
		}
	}
	reset_buffer();
}

//encode the dates into a long int type for the date vector to save space and go faster.
lint	BitcoinExchange::encode(sint year, sint month, sint day){return static_cast<lint>(year << 9) | (month << 5) | day;}
