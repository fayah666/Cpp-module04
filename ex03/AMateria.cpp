/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:40:04 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/15 17:33:24 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::AMateria( const AMateria & src )
{
	if (this != &src)
		*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &	AMateria::operator=( AMateria const & rhs )
{
	(void)rhs;
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
	(void)target;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string const & AMateria::getType() const
{
	return (this->type);
}

/* ************************************************************************** */
