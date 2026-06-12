#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"
# define INVENTORY_SLOTS 4

class Character : public ICharacter
{

	public:

		Character();
		Character( Character const & src );
		~Character();

		Character &		operator=( Character const & rhs );
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
		bool isEmptySLot(int idx) const;

	private:
		AMateria* inventory[INVENTORY_SLOTS];
		bool inventorySlotsFull;

};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */
