# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vscode <vscode@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 09:31:18 by dugonzal          #+#    #+#              #
#    Updated: 2022/07/31 15:08:15 by vscode           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corsair.a

SRC = corsair.c corsair_utils.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

SANITIZE = fsanitize-all-undefined -fno-sanitize-recover=all

CC = gcc

all:
		@$(CC) -I/usr/include/openssl/ $(FLAGS)  $(SRC) -o $(NAME) -lcrypto -ldl -lssl && ./$(NAME)
#keys:
#		@$(CC) -I/usr/include/openssl/ $(FLAGS)  $(SRC) -o $(NAME) -lcrypto -ldl  && ./corsair.a
	@echo "\n                    compilacion done"
clean :
	@rm -f $(NAME) $(OBJ)
	@echo "Clean done"

fclean : clean
	@rm -f $(NAME)
	@echo "Full clean done"

re : clean fclean all
	@echo "Re-compilation done"
out:
	./$(NAME)
	@echo "output done"
