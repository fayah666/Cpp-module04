#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>

class MateriaSource
{

	public:

		MateriaSource();
		MateriaSource( MateriaSource const & src );
		~MateriaSource();

		MateriaSource &		operator=( MateriaSource const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, MateriaSource const & i );

#endif /* *************************************************** MATERIASOURCE_H */