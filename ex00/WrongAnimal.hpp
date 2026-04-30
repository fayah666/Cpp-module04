/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:43:12 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/30 13:23:23 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>

class WrongAnimal {
	private :
		std::string _type;
	public :
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& other);
		~WrongAnimal(void);

		WrongAnimal& operator=(const WrongAnimal& other);
		const std::string	getType(void) const;
		void				setType(const std::string& type);
		void				makeWrongSound(void);
};

#endif //WRONGANIMAL_HPP
