/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:15:00 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/14 00:00:00 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	std::cout << "--- TEST 1: Subject Case ---" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << "\n--- TEST 2: Inventory Limits & Unset Slots ---" << std::endl;
	Character* char2 = new Character("Warrior");
	AMateria* ice = new Ice();
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Equipping " << i << " ";
		char2->equip(ice);
	}
	char2->use(4, *bob); // Should do nothing (out of bounds)
	char2->unequip(0);
	AMateria* cure = new Cure();
	char2->equip(cure); // Should fill the first empty slot (0)
	
	std::cout << "\n--- TEST 3: Deep Copy Character ---" << std::endl;
	Character* clone = new Character(*char2);
	std::cout << "Clone name: " << clone->getName() << std::endl;
	
	std::cout << "\n--- TEST 4: MateriaSource unknown type ---" << std::endl;
	MateriaSource* source = new MateriaSource();
	AMateria* unknown = source->createMateria("fire");
	if (unknown == NULL)
		std::cout << "Correctly returned NULL for unknown type" << std::endl;

	delete clone;
	delete char2;
	delete ice;
	delete source;

	return 0;
}
