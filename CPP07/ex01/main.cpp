/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:15:41 by davidjwp          #+#    #+#             */
/*   Updated: 2024/02/20 14:27:39 by davidjwp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

#define LEN 5

void increase(int& val){val+=5;}

void change(char& c){c += 5;}

void print(int& val){std::cout << val << " ";}

int	main(void)
{
	int		arr1[LEN] = {0, 1 , 2, 3, 4};
	char	arr2[LEN+1] = "01234";

	iter(arr1, LEN, increase);
	iter(arr1, LEN, print);
	std::cout << std::endl;
	iter(arr2, LEN, change);
	std::cout << arr2 << std::endl;
	return 0;
}