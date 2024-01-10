/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:10:53 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/10 19:11:16 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main(void){
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;
	const Animal* t[4];
	for (int i = 0; i < 2; i++)
		t[i] = new Dog();
	for (int i = 2; i < 4; i++)
		t[i] = new Cat();
	for (int i = 0; i < 4; i++)
		t[i]->think();
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		delete t[i];
	return 0;
}
