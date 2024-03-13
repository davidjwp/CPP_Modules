/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:23:50 by djacobs           #+#    #+#             */
/*   Updated: 2024/03/13 02:46:16 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include "EC.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

Convert::Convert(){}

Convert::Convert(Convert& cpy){(void)cpy;}

Convert::Convert(std::ifstream& input_file){
	index = 0;
	CSV.open("data.csv");

	if (!CSV.is_open()){input_file.close(); throw EC::CannotOpenFile();}
	_Convert();

	std::string line;
	std::string file_val;
	std::string file_date;
	float	val;
	lint	dat;

	//get first line
	std::getline(input_file, line);
	while (input_file){
		std::getline(input_file, line);
	/*
		if (line[0]) {
			file_date = std::string(line.substr(0, line.find_first_of('|')));//input file date in string
			dat = eval_date(file_date, "input_file");//evaluate the date and encode it
			date_iterator p = std::find(date.begin(), date.end(), dat);//search for the date in the csv date vector
			file_val = std::string(line.substr(line.find_first_of('|') + 1, line.length()));//input file val in string
			val = atof(file_val.c_str());//file val int 

			if (!*p) p = std::min_element(date.begin(), date.end(), Smallest(dat));
			if (file_val.find_first_of("0123456789", 0) == std::string::npos) std::cout << "Error: no value" << std::endl;
			else if ((val < 0) || (val >= 1000.0)) std::cout << "Error: bad values" << std::endl;
			else std::cout << file_date << " => " << val << " = " << cal_values(p, val) << std::endl;
		}*/
		if (line[0]) {
			date_iterator p;
			file_date = std::string(line.substr(0, line.find_first_of('|')));
			dat = eval_date(file_date, "input_file");
			if (!*(p = std::find(date.begin(), date.end(), dat))) 
				p = std::min_element(date.begin(), date.end(), Smallest(dat));
			if ((file_val = std::string(line.substr(line.find_first_of('|') + 1, line.length()))).find_first_of("0123456789", 0) == std::string::npos) 
				std::cout << "Error: no value" << std::endl;
			val = atof(file_val.c_str());//

			if ((val < 0) || (val >= 1000.0)) std::cout << "Error: bad values" << std::endl;
			else std::cout << file_date << " => " << val << " = " << cal_values(p, val) << std::endl;
		}
	}
}

float Convert::cal_values(date_iterator& p, float val) const{ unsigned int index = p - date.begin(); 
return val * value[index];}

Convert::~Convert(){}

Convert& Convert::operator=(Convert& C){(void)C; return C;}

void Convert::reset_buffer(){CSV.clear(); CSV.seekg(0); index = 0;} 

lint	Convert::eval_date(std::string string_date, std::string File){
	sint	year, month, day;

	year = atoi(string_date.substr(0, string_date.find_first_of('-')).c_str());
	month = atoi(string_date.substr(string_date.find_first_of('-') + 1, string_date.find_last_of('-')).c_str());
	day = atoi(string_date.substr(string_date.find_last_of('-') + 1, string_date.length()).c_str());
	
	if (year > 10000 || year < 2009 ||
		month > 12 || month < 0 ||
		day > 31 || day < 0){
		if (!File.compare("CSV")) throw EC::FilebadDay(File);
		else {std::cout << "Error: bad input => " << year<<'-'<<month<<'-'<<day << std::endl; return 0;}}

	if ((month == 2 && day > 29) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
		{if (!File.compare("CSV")) throw EC::FilebadDay(File);
		 else {std::cout << "Error: bad date => " << year<<'-'<<month<<'-'<<day << std::endl; return 0;}}

	if (!File.compare("CSV"))
		date.push_back(Convert::encode(year, month, day));
	return Convert::encode(year, month, day);
}

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

lint	Convert::encode(sint year, sint month, sint day){return static_cast<lint>(year << 9) | (month << 5) | day;}
