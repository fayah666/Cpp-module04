/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:18:16 by hfandres          #+#    #+#             */
/*   Updated: 2026/05/01 17:34:16 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Carnivorous") {
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy" << std::endl;
	if (this != &other)
		*this = other;
}
Animal::~Animal(void){
	std::cout << "Animal Destruction" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Surcharge 'operator='" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other.getType();
	return (*this);
}

const std::string	Animal::getType(void) const {
	return (this->_type);
}

void	Animal::setType(const std::string& type) {
	this->_type = type;
}

void	Animal::makeSound(void) const {
	std::cout << "Grrrrrrrrrrrrrr........." << std::endl;
}

const	Brain& Animal::getBrain(void) const {
	static Brain brain;
	return (brain);
}
