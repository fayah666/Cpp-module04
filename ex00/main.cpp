/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:25:53 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/15 13:42:48 by hfandres         ###   ########.fr       */
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
	std::cout << "POLYMORPHISME\n" << std::endl;
	std::cout << "---Animal Class---\n" << std::endl;
	animalClassTest();
	std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,," << std::endl;
	std::cout << "--Dog Class---\n" << std::endl;
	dogClassTest();
	std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,," << std::endl;
	std::cout << "--Cat Class--\n" << std::endl;
	catClassTest();
	std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,," << std::endl;
	{
		std::cout << "___Polymorphisme test___\n" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "i = " << i->getType() << std::endl;
		std::cout << "j = " << j->getType() << std::endl;
		std::cout << "meta = " << meta->getType() << std::endl;
		std::cout << "i makeSound = ";
		i->makeSound();
		std::cout << "j makeSound = ";
		j->makeSound();
		std::cout << "meta makeSound = ";
		meta->makeSound();
		delete(meta);
		delete(i);
		delete(j);
	}
	std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,," << std::endl;
	{
		std::cout << "___Wrong test___\n" << std::endl;
		WrongAnimal* meta = new WrongAnimal();
		WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << std::endl;
		i->makeWrongSound();
		meta->makeWrongSound();
		delete(meta);
		delete(i);
		{
			std::cout << "___Wrong test 2___\n" << std::endl;
			WrongCat* j = new WrongCat();
			std::cout << j->getType() << std::endl;
			j->makeWrongSound();
			delete(j);
		}
	}
	return (0);
}
