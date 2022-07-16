# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 09:31:18 by dugonzal          #+#    #+#              #
#    Updated: 2022/07/14 14:18:56 by ciclo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corsair.a

SRC = corsair.c utils.c

#OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

SANITIZE = -fsanitize=address -fsanitize=undefined

CC = gcc

all:
		@$(CC) $(FLAGS)  $(SANITIZE) $(SRC) -o $(NAME) && ./corsair.a
	@echo "Compilation done"
clean :
	@rm -f $(NAME) $(OBJ)
	@echo "Clean done"

fclean : clean
	@rm -f $(NAME)
	@echo "Full clean done"
re : clean fclean all
	@echo "Re-compilation done"

