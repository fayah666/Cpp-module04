/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:21:56 by hfandres          #+#    #+#             */
/*   Updated: 2026/05/01 11:54:27 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	Animal::setType("Cat");
	std::cout << "Cat default constructor" << std::endl;
	_brain = new Brain();
	for (size_t i = 0; i < IDEAS_COUNTS; i++)
		_brain->setIdeas(i, "Dog");
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat Destruction" << std::endl;
		delete _brain;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Surcharge 'operator='" << std::endl;
	if (this == &other)
		return (*this);
	setType(other.getType());
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Miaaou" << std::endl;
}

void	Cat::fillBrain(size_t n, const std::string ideas) {
	for (size_t i = 0; i < n; i++)
		_brain->setIdeas(i, ideas);
}

const	Brain& Cat::getBrain(void) const {
	return (*_brain);
}
