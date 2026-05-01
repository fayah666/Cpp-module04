/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:11:30 by hfandres          #+#    #+#             */
/*   Updated: 2026/05/01 16:30:09 by hfandres         ###   ########.fr       */
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
		void	setBrainIdeas(size_t n, const std::string ideas);
		const	Brain& getBrain(void) const;
};

#endif //CAT_HPP
