/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:21:56 by hfandres          #+#    #+#             */
/*   Updated: 2026/05/01 17:35:51 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	Animal::setType("Cat");
	std::cout << "Cat default constructor" << std::endl;
	_brain = new Brain();
	for (size_t i = 0; i < IDEAS_COUNTS; i++)
		_brain->setIdeas(i, "fish");
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Cat copy constructor" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor" << std::endl;
		delete _brain;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	delete _brain;
	this->_brain = new Brain(*other._brain);
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Miaaou" << std::endl;
}

const	Brain& Cat::getBrain(void) const {
	return (*_brain);
}
