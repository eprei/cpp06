CXX = c++
# CXX = g++-12

NAME = identifiez_le_veritable_type

SRCS = main.cpp A.cpp B.cpp C.cpp Base.cpp

CFLAGS = -Werror -Wextra -Wall -std=c++98 -g #-pedantic

OBJ = $(SRCS:.cpp=.o)

.cpp.o:
	$(CXX) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
