/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:23:50 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/13 18:14:59 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include "EC.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

Convert::Convert(){}

Convert::Convert(Convert& cpy){(void)cpy;}

//both constructor for the object and the "main" function.
Convert::Convert(std::ifstream& input_file){
	index = 0;
	CSV.open("data.csv");

	//checks if the file is open properly
	if (!CSV.is_open()){input_file.close(); throw EC::CannotOpenFile();}
	//this function creates the date and value vector from the csv file, it also throws.
	_Convert();

	//creating the variables for the line, the input file values and date, the float and long int of the value and date.
	std::string line;
	std::string file_val;
	std::string file_date;
	float	val;
	lint	dat;
	date_iterator p;//the iterator for the date vector corresponding to the input file date or the closest from it.

	std::getline(input_file, line);
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
			else std::cout << file_date << " => " << val << " = " << cal_values(p, val) << std::endl;
		}
	}
}

//using the date vector iterator to find the corresponding position in the value vector the result of the input file value times the csv value is calculated.
float Convert::cal_values(date_iterator& p, float val) const{ unsigned int index = p - date.begin(); return val * value[index];}

Convert::~Convert(){}

Convert& Convert::operator=(Convert& C){(void)C; return C;}

//resets the file buffer, this isn't really needed tbh.
void Convert::reset_buffer(){CSV.clear(); CSV.seekg(0); index = 0;} 

/*
evaluates the date in string format and returns the encoded version, in case of an error throws an exception for the "CSV" file
and returns 0 for the "input_file".
*/
lint	Convert::eval_date(std::string string_date, std::string File){
	sint	year, month, day;

	year = atoi(string_date.substr(0, string_date.find_first_of('-')).c_str());
	month = atoi(string_date.substr(string_date.find_first_of('-') + 1, string_date.find_last_of('-')).c_str());
	day = atoi(string_date.substr(string_date.find_last_of('-') + 1, string_date.length()).c_str());
	
	if (year > 10000 || year < 2009 ||
		month > 12 || month < 0 ||
		day > 31 || day < 0){
		if (!File.compare("CSV")) throw EC::FilebadDay(File);
		else {std::cerr << "Error: bad input => " << year<<'-'<<month<<'-'<<day << std::endl; return 0;}}

	if ((month == 2 && day > 29) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
		{if (!File.compare("CSV")) throw EC::FilebadDay(File);
		 else {std::cerr << "Error: bad date => " << year<<'-'<<month<<'-'<<day << std::endl; return 0;}}

	if (!File.compare("CSV"))
		date.push_back(Convert::encode(year, month, day));
	return Convert::encode(year, month, day);
}

//create the date and value vector from the csv file, throws an exception if the csv file is bad.
void Convert::_Convert(){
	std::string file("CSV");
	std::string	line;
	
	std::getline(CSV, line);

	while (CSV){
		std::getline(CSV, line);
		if (line[0]) {
			eval_date(line.substr(0, line.find_first_of(',')), "CSV");
			
			line = line.substr(line.find_first_of(',') + 1, line.length());
			if (!line[0] || line[0] == 32) throw EC::FileBadValue(file);
			float tval = atof(line.c_str());
			if (tval < 0 || tval >= 2147483647.0) throw EC::FileBadValue(file);
			value.push_back(tval);
			index++;
		}
	}
	reset_buffer();
	len = index;
}

//encode the dates into a long int type for the date vector to save space and go faster.
lint	Convert::encode(sint year, sint month, sint day){return static_cast<lint>(year << 9) | (month << 5) | day;}
