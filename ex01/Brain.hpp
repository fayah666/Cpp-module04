/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:42:05 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/30 13:47:11 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>
# define IDEAS_COUNTS 100;
class Brain {
	privat :
		std::string ideas[IDEAS_COUNTS];
	public :
		Brain(void);
		Brain(const Brain& other);
		~Brain(void);

		Brain&	operator=(const Brain& other);
		const std::string*	getIdeas(void) const;
		void				stIdeas(const std::string* ideas);
};

#endif //BRAIN_HPP
