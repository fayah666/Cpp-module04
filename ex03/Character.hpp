/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:08:56 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/13 19:31:38 by hfandres         ###   ########.fr       */
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
        virtual ~Character();

        // Les deux surcharges nécessaires
        virtual ICharacter & operator=( ICharacter const & rhs );
        Character &          operator=( Character const & rhs );

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        AMateria* getMateria(int idx) const;

    private:
        AMateria *inventory[INVENTORY_SLOTS];

        // Méthode utilitaire privée pour centraliser la copie profonde
        void _copyInventory( ICharacter const & rhs );
};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */

/*

[0][0][0][0]

*/
