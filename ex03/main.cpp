/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:59:48 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/12 19:09:10 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

int main()
{
	// Ice ice;
	// std::cout << "Type: " << ice.getType() << std::endl;

	// Ice* iceClone = dynamic_cast<Ice*>(ice.clone());
	// if (iceClone)
	// {
	// 	std::cout << "Cloned Ice Type: " << iceClone->getType() << std::endl;
	// 	delete iceClone;
	// }
	// else
	// {
	// 	std::cerr << "Failed to clone Ice." << std::endl;
	// }
	AMateria* am = new Ice();
	std::cout << *am << std::endl;
	delete am;
	return 0;
}
