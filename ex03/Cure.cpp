/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:46:30 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/13 17:08:59 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
	this->type = "cure";
}

Cure::Cure( const Cure & src ) : AMateria(src)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type)
{
	this->type = "cure";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &	Cure::operator=( Cure const & rhs )
{
	std::cout << "Cure assignment operator called" << std::endl;
	AMateria::operator=(rhs);
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/
AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target << "’s wounds *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
