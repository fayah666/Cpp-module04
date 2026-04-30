/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:47:32 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/30 13:26:34 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("mammal") {
	std::cout << "Wrong Animal Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "Copy assignment" << std::endl;
	if (this != &other)
		*this = other;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "Wrong Animal Destruction" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "Surcharge 'operator='" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

void	WrongAnimal::makeWrongSound(void) {
	std::cout << "Grrrrrrrrr....ouuufps" <<  std::endl;
}

const std::string	WrongAnimal::getType(void) const {
	return (this->_type);
}

void	WrongAnimal::setType(const std::string& type) {
	this->_type = type;
}
