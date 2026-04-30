/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wron WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:03:26 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/30 13:03:28 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public :
		WrongCat(void);
		WrongCat(const WrongCat& other);
		~WrongCat(void);
		WrongCat&	operator=(const WrongCat& other);
		void makeWrongSound(void) const;
};

#endif // WRONGCAT_HPP
