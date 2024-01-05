/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:19:08 by djacobs           #+#    #+#             */
/*   Updated: 2024/01/05 13:32:16 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>

//if you have multiple inheritances on the same class
//if you want some things to be derived and some things not to be
//


ClapTrap::ClapTrap(void){}

ClapTrap::ClapTrap(std::string &n): Name(n){}

ClapTrap