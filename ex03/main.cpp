/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:15:00 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/16 12:40:52 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
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
	}
	{
		std::cout << "\n--- TEST 2: Inventory Limits & Unset Slots ---" << std::endl;
		Character* char2 = new Character("Warrior");
		ICharacter* bob = new Character("bob");
		IMateriaSource* source = new MateriaSource();
		source->learnMateria(new Ice());
		AMateria* ice = source->createMateria("ice");
		char2->equip(ice);
		std::cout << "char2: " << *char2 << std::endl;
		char2->use(0, *bob);
		char2->unequip(0);
		std::cout << "char2: " << *char2 << std::endl;
		std::cout << "Attempting to use unequipped slot (should do nothing):" << std::endl;
		char2->use(0, *bob);

		std::cout << "Equipping multiple materia:" << std::endl;
		char2->equip(new Cure());
		char2->equip(new Cure());
		char2->equip(ice);
		char2->equip(new Ice());
		std::cout << "char2: " << *char2 << std::endl;
		std::cout << "Attempting to equip a 5th materia (should fail):" << std::endl;
		char2->equip(new Cure());
		std::cout << "char2: " << *char2 << std::endl;

		std::cout << "\nUsing equipped materia:" << std::endl;
		char2->use(0, *bob);
		char2->use(1, *bob);
		char2->use(2, *bob);
		char2->use(3, *bob);
		std::cout << "Attempting to use an out-of-bounds slot (should do nothing):" << std::endl;
		char2->use(4, *bob);
		char2->use(-1, *bob);

		std::cout << "\n--- TEST 3: Deep Copy Character ---" << std::endl;
		Character* clone = new Character(*char2);
		delete ice;
		char2->unequip(2);
		std::cout << "clone: " << *clone << std::endl;
		std::cout << "char2: " << *char2 << std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout << "clone inventory["<< i << "] address: "
					<< clone->getMateria(i)
					<< ", char2 inventory["<< i << "] address: "
					<< char2->getMateria(i)
					<< std::endl;
		}

		std::cout << "\n--- TEST 3: Deep Copy Materia ---" << std::endl;
		MateriaSource s2;
		s2.learnMateria(new Ice());
		s2.learnMateria(new Cure());
		s2.learnMateria(new Ice());
		s2.learnMateria(new Cure());

		MateriaSource s3 = s2;
		std::cout << "s2: " << s2 << std::endl;
		std::cout << "s3: " << s3 << std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout << "s3 template["<< i << "] address: "
					<< s3.getMateria(i)
					<< ", s2 template["<< i << "] address: "
					<< s2.getMateria(i)
					<< std::endl;
		}

		std::cout << "\n--- TEST 4: MateriaSource unknown type ---" << std::endl;
		MateriaSource* s = new MateriaSource();
		AMateria* unknown = s->createMateria("fire");
		if (unknown == NULL)
			std::cout << "Correctly returned NULL for unknown type" << std::endl;

		delete clone;
		delete char2;
		delete source;
		delete bob;
		delete s;
		delete unknown;
	}
	return 0;
}
