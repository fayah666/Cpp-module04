/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:11:30 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/15 10:56:14 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal {
	public :
		Cat(void);
		Cat(const Cat& animal);
		~Cat(void);
		Cat&	operator=(const Cat& other);
		void makeSound(void) const;
};

#endif //CAT_HPP
