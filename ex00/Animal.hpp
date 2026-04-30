/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:13:10 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/30 11:30:00 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

class Animal {
	private :
		std::string	_type;
	public :
		Animal(void);
		Animal(const std::string& type);
		Animal(const Animal& animal);
		~Animal(void);
		Animal&				operator=(const Animal& other);
		const std::string	getType(void) const;
		void				setType(std::string& type);
};

#endif //ANIMAL_HPP
