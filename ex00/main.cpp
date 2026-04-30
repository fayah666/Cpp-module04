/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:25:53 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/30 11:29:38 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

static void animalClassTest(void)
{
	Animal a;
	Animal b(a);
	Animal c = a;

	std::cout << a.getType() << std::endl;
	std::cout << b.getType() << std::endl;
	std::cout << c.getType() << std::endl;
}

int main(void) {
	animalClassTest();
	return (0);
}
