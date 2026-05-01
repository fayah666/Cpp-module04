/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:01:48 by hfandres          #+#    #+#             */
/*   Updated: 2026/05/01 10:53:59 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain Default constructor" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain Copy assignement" << std::endl;
	if (this != &other)
		*this = other;
}

Brain::~Brain(void) {
	std::cout << "Braim Destruction" << std::endl;
}

Brain&	Brain::operator=(const Brain& other) {
	std::cout << "Brain operator=" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
		setIdeas(i, other.getIdeas(i));
	return (*this);
}

const std::string&	Brain::getIdeas(std::size_t index) const {
	return (_ideas[index]);
}

void	Brain::setIdeas(std::size_t index , const std::string& ideas) {
	_ideas[index] = ideas;
}
