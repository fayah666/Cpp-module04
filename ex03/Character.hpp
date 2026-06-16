/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:08:56 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/16 11:32:17 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
public:
	Character();
	Character(Character const &src);
	Character(std::string const &name);
	~Character();

	Character &operator=(Character const &rhs);

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
	AMateria* getMateria(int idx) const;
private:
	AMateria *inventory[4];
	std::string name;
};

std::ostream &operator<<(std::ostream &o, Character const &i);

#endif /* ******************************************************* CHARACTER_H */
