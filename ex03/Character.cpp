/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 19:31:57 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/13 19:35:46 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() : ICharacter()
{
	for (int i = 0; i < INVENTORY_SLOTS; i++)
		inventory[i] = NULL;
	std::cout << "Character default constructor" << std::endl;
}

Character::Character(std::string const & name)
{
	for (int i = 0; i < INVENTORY_SLOTS; i++)
		inventory[i] = NULL;
	std::cout << "Character string constructor" << std::endl;
	this->name = name;
}

Character::Character( const Character & src ) : ICharacter(src)
{
    for (int i = 0; i < INVENTORY_SLOTS; i++)
        this->inventory[i] = NULL;
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	std::cout << "Character destroctor" << std::endl;
	for (int i = 0; i < INVENTORY_SLOTS; i++)
	{
		if (inventory[i] != NULL)
			delete (inventory[i]);
	}
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	o << i.getName();
	return o;
}

// Version pour l'interface (ICharacter*)
ICharacter & Character::operator=( ICharacter const & rhs )
{
    if ( this != &rhs )
    {
        this->_copyInventory(rhs);
    }
    return (*this);
}

// Version pour la classe concrète (Character)
Character & Character::operator=( Character const & rhs )
{
    if ( this != &rhs )
    {
        this->_copyInventory(rhs);
    }
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::_copyInventory( ICharacter const & rhs )
{
    // this->name = rhs.getName();

    // 1. Nettoyage de l'ancien inventaire
    for (int i = 0; i < INVENTORY_SLOTS; i++)
    {
        if (this->inventory[i] != NULL)
        {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }

    // 2. Copie profonde via le getter virtuel de l'interface
    for (int i = 0; i < INVENTORY_SLOTS; i++)
    {
        AMateria* m = rhs.getMateria(i);
        if (m != NULL)
        {
            this->inventory[i] = m->clone();
        }
    }
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < INVENTORY_SLOTS; i++)
	{
		if (inventory[i] == NULL)
		{
			std::cout << "equip :" << *m << "in : " << i << std::endl;
			inventory[i] = m->clone();
			return ;
		}
	}
	std::cout << "Buy 4 more slots for 2000000000$" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= INVENTORY_SLOTS)
    {
        std::cout << "Index out of bounds!" << std::endl;
        return ;
    }
    if (inventory[idx] == NULL)
    {
        std::cout << "Slot " << idx << " is already empty." << std::endl;
        return ;
    }
    std::cout << "unequip : " << idx << std::endl;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= INVENTORY_SLOTS)
    {
        std::cout << "Index out of bounds!" << std::endl;
        return ;
    }
    if (inventory[idx] == NULL)
    {
        std::cout << "No Materia equipped at slot " << idx << std::endl;
        return ;
    }
    inventory[idx]->use(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string const & Character::getName() const
{
	return (name);
}

AMateria* Character::getMateria(int idx) const
{
    if (idx >= 0 && idx < INVENTORY_SLOTS)
        return (this->inventory[idx]);
    return (NULL);
}
