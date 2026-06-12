/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 20:26:53 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/12 21:35:46 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
# include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() : ICharacter()
{
	std::cout << "Character default constructor" << std::endl;
}

Character::Character(std::string const & name)
{
	std::cout << "Character string constructor" << std::endl;
	this->name = name;
}

Character::Character( const Character & src ) : ICharacter(src)
{
	std::cout << "Character copy constructor" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	std::cout << "Character destroctor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
		this->name = rhs.getName();
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void Character::equip(AMateria* m)
{
	std::cout << "equip :" << *m << std::endl;
}

void Character::unequip(int idx)
{
	std::cout << "unequip : " << idx << std::endl;
}
void Character::use(int idx, ICharacter& target)
{
	std::cout << "use : "<< idx << "/" << target << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string const & Character::getName() const
{
	return (name);
}

/* ************************************************************************** */
