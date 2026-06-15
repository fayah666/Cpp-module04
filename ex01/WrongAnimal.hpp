/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:43:12 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/15 13:56:46 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>

class WrongAnimal {
	protected :
		std::string _type;
	public :
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& other);
		~WrongAnimal(void);

		WrongAnimal& operator=(const WrongAnimal& other);
		const std::string	getType(void) const;
		void				makeWrongSound(void) const;
};

#endif //WRONGANIMAL_HPP
