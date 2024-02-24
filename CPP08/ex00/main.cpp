/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:49:46 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/24 21:05:44 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <iostream>
#include <exception>
#include <iterator>
#include "easyfind.hpp"

# define VECTOR {1, 2, 3, 4, 0, 6};

int	main(void){
	int	arr[] = VECTOR
	
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	std::deque<int> que(arr, arr + sizeof(arr) / sizeof(int));
	try{
		std::cout << "Element " << *easyfind(vec, 0) << " found" << std::endl;
		vec.pop_back();
		//std::cout << "Element " << *easyfind(vec, 6) << " found" << std::endl;
		std::cout << "Element " << *easyfind(que, 3)  << " found" << std::endl;
	}
	catch (std::exception& E){
		std::cout << "Exception: " << E.what() << std::endl;
	}
	return 0;
}