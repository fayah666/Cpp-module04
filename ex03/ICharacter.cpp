/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 20:44:13 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/13 19:19:08 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

// ICharacter::ICharacter()
// {
// 	std::cout << "ICharacter default constructor called" << std::endl;
// }

// ICharacter::ICharacter( const ICharacter & src )
// {
// 	std::cout << "ICharacter copy constructor called" << std::endl;
// 	if (this != &src)
// 		*this = src;
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ICharacter::~ICharacter()
{
	std::cout << "ICharacter destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// ICharacter &				ICharacter::operator=( ICharacter const & rhs )
// {
// 	(void)rhs;
// 	return (*this);
// }

std::ostream &			operator<<( std::ostream & o, ICharacter const & i )
{
	o << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
