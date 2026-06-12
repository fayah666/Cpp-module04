/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:46:30 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/12 19:18:35 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice()
{
	std::cout << "Ice default constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice( const Ice & src ) : AMateria(src)
{
	std::cout << "Ice copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &	Ice::operator=( Ice const & rhs )
{
	std::cout << "Ice assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/
AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
