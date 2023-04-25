# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ageels <ageels@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/20 15:31:35 by ageels        #+#    #+#                  #
#    Updated: 2023/04/25 20:48:09 by ageels        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =  Serena_my_love

FLAGS = -I. -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

SRC = main.cpp\
	ClapTrap.cpp\
	ScavTrap.cpp
	
OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -fr $(OBJ_DIR)
	
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re