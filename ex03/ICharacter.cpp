#include "ICharacter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ICharacter::ICharacter() : name("Default Name")
{
	std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter( const ICharacter & src )
{
	std::cout << "ICharacter copy constructor called" << std::endl;
	if (this != &src)
		*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ICharacter::~ICharacter()
{
	std::cout << "ICharacter destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ICharacter &				ICharacter::operator=( ICharacter const & rhs )
{
	if ( this != &rhs )
		this->name = rhs.getName();
	return (*this);
}

std::ostream &			operator<<( std::ostream & o, ICharacter const & i )
{
	o << "Value = " << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string const & ICharacter::getName() const
{
	return (this->name);
}

/* ************************************************************************** */
