/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:59:48 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/13 19:34:30 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	{
		std::cout << "----- TESTING USE -----" << std::endl;
		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");
		std::cout <<  std::endl;
		AMateria* am = new Ice();
		std::cout << "AMateria/adress : " << *am << std::endl;
		am->use(*me);
		std::cout <<  std::endl;
		AMateria* am2 = new Cure();
		std::cout << "AMateria/adress : " << *am2 << std::endl;
		am2->use(*me);
		std::cout <<  std::endl;
		me->equip(am);
		me->equip(am2);
		me->equip(am2);
		me->equip(am2);
		me->equip(am2);
		// me->unequip(0);
		*bob = *me;
		std::cout << "\n----- VERIFICATION DE LA COPIE PROFONDE -----" << std::endl;
		std::cout << "Adresse de la Materia 0 de me  : " << me->getMateria(0) << std::endl;
		std::cout << "Adresse de la Materia 0 de bob : " << bob->getMateria(0) << std::endl;

		if (me->getMateria(0) != bob->getMateria(0) && bob->getMateria(0) != NULL)
		{
		    std::cout << "🔥 SUCCÈS : Les adresses sont différentes ! C'est une vraie Deep Copy." << std::endl;
		}
		else
		{
		    std::cout << "❌ ERREUR : Les adresses sont identiques ou NULL !" << std::endl;
		}
		bob->use (0, *me);
		bob->use (1, *me);
		bob->use (2, *me);
		bob->use (3, *me);
		bob->use (4, *me);

		std::cout << *me << std::endl;
		std::cout << *bob << std::endl;
		// *am = *am2; // ice = cure
		delete am;
		delete am2;
		delete me;
		delete bob;
	}
	std::cout << "..........................................." << std::endl;
	{
		std::cout << "----- TESTING CLONE -----" << std::endl;
		ICharacter* me =  new Character("me");
		std::cout <<  std::endl;
		AMateria* am = new Ice();
		std::cout <<  std::endl;
		AMateria* am2 = am->clone();
		am2->use(*me);
		std::cout <<  std::endl;
		std::cout << "AMateria/adress : " << *am << std::endl;
		std::cout << "AMateria/adress : " << *am2 << std::endl;
		std::cout <<  std::endl;
		delete am;
		delete am2;
		delete me;
	}
	std::cout << "..........................................." << std::endl;
	return 0;
}
