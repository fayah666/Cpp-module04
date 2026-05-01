/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:13:10 by hfandres          #+#    #+#             */
/*   Updated: 2026/05/01 11:10:38 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal {
	private :
		std::string	_type;
	public :
		Animal(void);
		Animal(const Animal& animal);
		virtual ~Animal();
		Animal&				operator=(const Animal& other);
		const std::string	getType(void) const;
		void				setType(const std::string& type);
		virtual void makeSound(void) const;
};

#endif //ANIMAL_HPP
