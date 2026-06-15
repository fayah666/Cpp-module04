/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:37:35 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/15 13:56:02 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	std::cout << "Dog default constructor" << std::endl;
	_type = "Dog";
	_brain = new Brain();
	for (size_t i = 0; i < IDEAS_COUNTS; i++)
		_brain->setIdeas(i, "meat");
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Dog copy constructor" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor" << std::endl;
		delete _brain;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	delete _brain;
	this->_brain = new Brain(*other._brain);
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Ouuuf" << std::endl;
}

const	Brain& Dog::getBrain(void) const {
	return (*_brain);
}
