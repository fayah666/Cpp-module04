CXX = g++

CXXFLAG = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		Brain.cpp
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
