CXX = c++

CXXFLAG = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = animal

all : $(NAME)

$(OBJS) : %.o : %.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAG) -o $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
