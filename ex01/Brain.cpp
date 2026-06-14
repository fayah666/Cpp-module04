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
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < IDEAS_COUNTS; ++i)
		_ideas[i] = other._ideas[i];
	std::cout << "Brain copy constructor" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor" << std::endl;
}

Brain&	Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < IDEAS_COUNTS; i++)
		_ideas[i] = other._ideas[i];
	return (*this);
}

const std::string&	Brain::getIdeas(std::size_t index) const {
	return (_ideas[index]);
}

void	Brain::setIdeas(std::size_t index , const std::string& ideas) {
	_ideas[index] = ideas;
}
