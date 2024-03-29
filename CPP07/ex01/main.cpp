/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:15:41 by davidjwp          #+#    #+#             */
/*   Updated: 2024/03/29 16:11:43 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

#define LEN 5

template <typename T>
void increase(T& val){val+=5;}

template <typename T>
void decrease(T& c){c -= 5;}

template <typename T>
void print(T& val){std::cout << val << " ";}

int	main(void)
{
	int		arr1[LEN] = {0, 1 , 2, 3, 4};
	char	arr2[LEN+1] = "01234";

	iter(arr1, LEN, increase);
	iter(arr1, LEN, print);
	std::cout << std::endl;
	iter(arr2, LEN, decrease);
	std::cout << arr2 << std::endl;
	return 0;
}