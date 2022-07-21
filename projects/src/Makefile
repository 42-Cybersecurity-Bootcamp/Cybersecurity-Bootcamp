# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 09:31:18 by dugonzal          #+#    #+#              #
#    Updated: 2022/07/20 21:40:03 by dugonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corsair.a

SRC = corsair.c

#OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

SANITIZE = -fsanitize=address -fsanitize=undefined

CC = gcc

all:
		@$(CC) $(FLAGS)  $(SANITIZE) $(SRC) -o $(NAME) && ./corsair.a
	@echo "clave publica y privada creadas"
clean :
	@rm -f $(NAME) $(OBJ)
	@echo "Clean done"
cifrar_mensaje:
	 @openssl rsautl -encrypt -pubin -inkey keys/public.key -in mensaje/mensaje.txt -out encrypt/mensaje.enc
	 @echo "Mensaje cifrado"
decifrar_mensaje:
	openssl rsautl -decrypt -inkey keys/private.key -in encrypt/mensaje.enc -out decencriptado/mensaje.dec
fclean : clean
	@rm -f $(NAME)
	@echo "Full clean done"
re : clean fclean all
	@echo "Re-compilation done"

