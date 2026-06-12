/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:59:48 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/12 19:39:56 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"

int main()
{
	{
		std::cout << "----- TESTING USE -----" << std::endl;
		ICharacter character;
		std::cout <<  std::endl;
		AMateria* am = new Ice();
		std::cout << "AMateria/adress : " << *am << std::endl;
		am->use(character);
		std::cout <<  std::endl;
		AMateria* am2 = new Cure();
		std::cout << "AMateria/adress : " << *am2 << std::endl;
		am2->use(character);
		std::cout <<  std::endl;
		delete am;
		delete am2;
	}
	std::cout << "..........................................." << std::endl;
	{
		std::cout << "----- TESTING CLONE -----" << std::endl;
		ICharacter character;
		std::cout <<  std::endl;
		AMateria* am = new Ice();
		std::cout <<  std::endl;
		AMateria* am2 = am->clone();
		am2->use(character);
		std::cout <<  std::endl;
		std::cout << "AMateria/adress : " << *am << std::endl;
		std::cout << "AMateria/adress : " << *am2 << std::endl;
		std::cout <<  std::endl;
		delete am;
		delete am2;
	}
	std::cout << "..........................................." << std::endl;
	return 0;
}
