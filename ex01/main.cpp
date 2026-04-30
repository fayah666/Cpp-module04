/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:25:53 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/30 13:27:48 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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
	Dog a;
	Dog b(a);
	Dog c = a;

	std::cout << a.getType() << std::endl;
	std::cout << b.getType() << std::endl;
	std::cout << c.getType() << std::endl;
}

static void catClassTest(void)
{
	Cat a;
	Cat b(a);
	Cat c = a;

	std::cout << a.getType() << std::endl;
	std::cout << b.getType() << std::endl;
	std::cout << c.getType() << std::endl;
}

int main(void) {
	std::cout << "___Canonical form test___" << std::endl;
	std::cout << "---Animal Class---" << std::endl;
	animalClassTest();
	std::cout << "--Dog Class---" << std::endl;
	dogClassTest();
	std::cout << "--Cat Class--" << std::endl;
	catClassTest();
	{
		std::cout << "___Polymorphisme test__" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete(meta);
		delete(i);
		delete(j);
	}
	{
		std::cout << "___Wrong test__" << std::endl;
		WrongAnimal* meta = new WrongAnimal();
		WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << std::endl;
		i->makeWrongSound();
		meta->makeWrongSound();
		delete(meta);
		delete(i);
	}
	return (0);
}
