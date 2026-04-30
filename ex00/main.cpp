/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:25:53 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/30 12:07:25 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"

static void animalClassTest(void)
{
	Animal a;
	Animal b(a);
	Animal c = a;

	std::cout << a.getType() << std::endl;
	std::cout << b.getType() << std::endl;
	std::cout << c.getType() << std::endl;
}

static void dogClassTest(void)
{
	const Animal* a = new Dog();

	std::cout << a->getType() << std::endl;
	a->makeSound();
	delete(a);
}

int main(void) {
	animalClassTest();
	dogClassTest();
	return (0);
}
