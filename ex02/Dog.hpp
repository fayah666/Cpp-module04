/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:35:45 by hfandres          #+#    #+#             */
/*   Updated: 2026/05/01 16:57:32 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private :
		Brain* _brain;
	public :
		Dog(void);
		Dog(const Dog& animal);
		~Dog(void);
		Dog&	operator=(const Dog& other);
		void	makeSound(void) const;
		const	Brain& getBrain(void) const;
};

#endif //DOG_HPP
