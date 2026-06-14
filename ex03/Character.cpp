/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 19:31:57 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/14 00:00:00 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : name("default")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &src) : name(src.getName())
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	*this = src;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

Character & Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.getName();
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (rhs.inventory[i])
				inventory[i] = rhs.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, ICharacter const &i)
{
	o << i.getName();
	return o;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m->clone();
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !inventory[idx])
		return;
	inventory[idx]->use(target);
}

std::string const &Character::getName() const
{
	return (name);
}

AMateria *Character::getMateria(int idx) const
{
	if (idx >= 0 && idx < 4)
		return (this->inventory[idx]);
	return (NULL);
}
