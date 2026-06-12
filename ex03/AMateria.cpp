/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:40:04 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/12 19:35:48 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria( const AMateria & src )
{
	std::cout << "AMateria copy constructor called" << std::endl;
	if (this != &src)
		*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &	AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return (*this);
}

std::ostream &	operator<<( std::ostream & o, AMateria const & i )
{
	o << i.getType() << "/" << &i;
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria used on " << target << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::setType(std::string const & type)
{
	this->type = type;
}

/* ************************************************************************** */
