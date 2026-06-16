CXX = c++

CXXFLAG = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = main.cpp \
		Ice.cpp \
		Cure.cpp \
		Character.cpp\
		AMateria.cpp \
		MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = materia

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
