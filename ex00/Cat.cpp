/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:21:56 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/15 13:59:46 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	_type = "Cat";
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy" << std::endl;
}

Cat::~Cat(void){
	std::cout << "Cat destructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	_type = other.getType();
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Miaaou" << std::endl;
}
