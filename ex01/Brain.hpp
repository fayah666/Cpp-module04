/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:42:05 by hfandres          #+#    #+#             */
/*   Updated: 2026/05/01 10:38:24 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>
# define IDEAS_COUNTS 100
class Brain {
	private :
		std::string _ideas[IDEAS_COUNTS];
	public :
		Brain(void);
		Brain(const Brain& other);
		~Brain(void);

		Brain&	operator=(const Brain& other);
		const std::string&	getIdeas(std::size_t index) const;
		void			setIdeas(std::size_t index , const std::string& ideas);
};

#endif //BRAIN_HPP
