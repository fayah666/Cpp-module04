/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:21:56 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/16 10:02:19 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	_type = "Cat";
	std::cout << "Cat default constructor" << std::endl;
	_brain = new Brain();
	for (size_t i = 0; i < IDEAS_COUNTS; i++)
		_brain->setIdeas(i, "Dog");
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor" << std::endl;
	*this = other;
}

Cat::~Cat(void) {
	std::cout << "Cat Destruction" << std::endl;
		delete _brain;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other.getType();
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		std::cerr << "Error: Memory allocation failed for Brain" << std::endl;
		return (*this);
	}
	*this->_brain = other.getBrain();
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Miaaou" << std::endl;
}

const	Brain& Cat::getBrain(void) const {
	return (*_brain);
}
