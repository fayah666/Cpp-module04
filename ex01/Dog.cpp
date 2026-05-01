/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:37:35 by hfandres          #+#    #+#             */
/*   Updated: 2026/05/01 18:19:08 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	std::cout << "Dog default constructor" << std::endl;
	Animal::setType("Dog");
	_brain = new Brain();
	for (size_t i = 0; i < IDEAS_COUNTS; i++)
		_brain->setIdeas(i, "meat");
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy" << std::endl;
	*this = other;
}

Dog::~Dog(void) {
	std::cout << "Dog Destruction" << std::endl;
		delete _brain;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Surcharge 'operator='" << std::endl;
	if (this == &other)
		return (*this);
	this->setType(other.getType());
	this->_brain = new Brain(other.getBrain());
	if (this->_brain == NULL)
	{
		std::cerr << "Error: Memory allocation failed for Brain" << std::endl;
		return (*this);
	}
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Ouuuf" << std::endl;
}

const	Brain& Dog::getBrain(void) const {
	return (*_brain);
}
