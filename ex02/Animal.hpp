/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:13:10 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/15 13:57:33 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal {
	protected :
		std::string	_type;
	public :
		Animal(void);
		Animal(const Animal& animal);
		virtual ~Animal();
		Animal&				operator=(const Animal& other);
		const std::string	getType(void) const;
		virtual void 		makeSound(void) const = 0;
		virtual const	Brain& getBrain(void) const = 0;
};

#endif //ANIMAL_HPP
