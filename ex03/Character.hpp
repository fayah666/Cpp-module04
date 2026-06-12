/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:08:56 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/12 21:30:36 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# define INVENTORY_SLOTS 4

class AMateria;

class Character : public ICharacter
{

	public:

		Character();
		Character( Character const & src );
		Character(std::string const & name);
		~Character();

		Character &		operator=( Character const & rhs );
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		// bool isEmptySLot(int idx) const;

	private:
		AMateria* inventory[INVENTORY_SLOTS];
		bool inventorySlotsFull;

};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */

/*

[0][0][0][0]

*/
