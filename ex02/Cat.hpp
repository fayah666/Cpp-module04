/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:11:30 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/15 13:46:01 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private :
		Brain* _brain;
	public :
		Cat(void);
		Cat(const Cat& animal);
		~Cat(void);
		Cat&	operator=(const Cat& other);
		void makeSound(void) const;
		const	Brain& getBrain(void) const;
};

#endif //CAT_HPP
