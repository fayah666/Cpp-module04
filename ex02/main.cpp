/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:25:53 by hfandres          #+#    #+#             */
/*   Updated: 2026/05/02 07:51:11 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#define N 6

int main(void) {
	{
		std::cout << "-----------------------------" << std::endl;
		std::cout << "|        Test constructors   |" << std::endl;
		std::cout << "-----------------------------" << std::endl;
		Animal* meta[N];
		for (int i = 0; i < N; ++i)
		{
			if (i % 2 == 0)
				meta[i] = new Dog();
			else
				meta[i] = new Cat();
		}
		for (size_t i = 0; i < N; i++)
			delete meta[i];
	}
	{
		std::cout << "-----------------------------" << std::endl;
		std::cout << "|         Test deep copy     |" << std::endl;
		std::cout << "-----------------------------" << std::endl;
		Dog* a = new Dog();
		Dog* b = new Dog(*a);
		Dog* e = new Dog(*b);
		std::cout << "a's brain address: " << &a->getBrain() << std::endl;
		std::cout << "b's brain address: " << &b->getBrain() << std::endl;
		std::cout << "e's brain address: " << &e->getBrain() << std::endl;
		Cat* c = new Cat();
		Cat* d = new Cat(*c);
		Cat* f = new Cat(*d);
		std::cout << "c's brain address: " << &c->getBrain() << std::endl;
		std::cout << "d's brain address: " << &d->getBrain() << std::endl;
		std::cout << "f's brain address: " << &f->getBrain() << std::endl;
		delete a;
		delete b;
		delete c;
		delete d;
		delete e;
		delete f;
	}
	// {
	// 	Animal* animal = new Animal(); // This line will cause a compilation error because Animal is an abstract class
	// 	delete animal;
	// }
	return (0);
}
