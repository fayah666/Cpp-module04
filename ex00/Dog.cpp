/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:37:35 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/30 12:11:20 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	Animal::setType("Dog");
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy" << std::endl;
	// if (this != &other)
	// 	*this = other;
}

Dog::~Dog(void){
	std::cout << "Dog Destruction" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Surcharge 'operator='" << std::endl;
	if (this == &other)
		return (*this);
	setType(other.getType());
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Ouuuf" << std::endl;
}
