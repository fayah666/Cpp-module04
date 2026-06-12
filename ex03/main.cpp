/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:59:48 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/12 21:42:41 by hfandres         ###   ########.fr       */
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
		ICharacter* bob = new Character("me");
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
		me->unequip(0);
		me->use (0, *bob);
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
