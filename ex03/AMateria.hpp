#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{

	public:

		AMateria();
		AMateria( AMateria const & src );
		~AMateria();

		AMateria &		operator=( AMateria const & rhs );
		std::string const & getType() const;
		void setType(std::string const & type);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected :
		std::string type;

};

std::ostream &			operator<<( std::ostream & o, AMateria const & i );

#endif /* ******************************************************** AMATERIA_H */
