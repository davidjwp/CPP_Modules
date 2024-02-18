/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:55:44 by djacobs           #+#    #+#             */
/*   Updated: 2024/02/18 21:40:42 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base{
public:
	Base*	generate(void);

	virtual ~Base();
};

class A: public Base{};
class B: public Base{};
class C: public Base{};

#endif