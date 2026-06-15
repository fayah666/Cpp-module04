/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:37:35 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/15 13:59:53 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	_type = "Dog";
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy" << std::endl;
}

Dog::~Dog(void){
	std::cout << "Dog destructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	_type = other.getType();
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Ouuuf" << std::endl;
}
