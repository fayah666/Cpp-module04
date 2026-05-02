/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:05:10 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/30 13:05:12 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	WrongAnimal::setType("WrongCat");
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat copy" << std::endl;
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat Destruction" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "Surcharge 'operator='" << std::endl;
	if (this == &other)
		return (*this);
	setType(other.getType());
	return (*this);
}

void	WrongCat::makeWrongSound(void) const {
	std::cout << "......................." << std::endl;
}
