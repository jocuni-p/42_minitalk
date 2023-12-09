# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 11:26:58 by jocuni-p          #+#    #+#              #
#    Updated: 2023/12/06 18:27:49 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#----------------VARIABLES--------------#

CC = cc

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

NAME_SERVER = server
NAME_CLIENT = client
#-------------------------
NAME_SERVER_BONUS = server
NAME_CLIENT_BONUS = client


SRC_SERVER = server.c
SRC_CLIENT = client.c
#--------------------------------
SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c


OBJ_DIR_SERVER = obj_server
OBJ_DIR_CLIENT = obj_client
#-------------------------------------
OBJ_DIR_SERVER_BONUS = obj_server_bonus
OBJ_DIR_CLIENT_BONUS = obj_client_bonus


OBJ_SERVER = $(addprefix $(OBJ_DIR_SERVER)/, $(SRC_SERVER:.c=.o))
OBJ_CLIENT = $(addprefix $(OBJ_DIR_CLIENT)/, $(SRC_CLIENT:.c=.o))
#---------------------------------------------------------------------------------
OBJ_SERVER_BONUS = $(addprefix $(OBJ_DIR_SERVER_BONUS)/, $(SRC_SERVER_BONUS:.c=.o))
OBJ_CLIENT_BONUS = $(addprefix $(OBJ_DIR_CLIENT_BONUS)/, $(SRC_CLIENT_BONUS:.c=.o))


#=====================================REGLAS===================================#


all: makelib $(OBJ_DIR_SERVER) $(NAME_SERVER) $(OBJ_DIR_CLIENT) $(NAME_CLIENT)


bonus: makelib $(OBJ_DIR_SERVER_BONUS)
	@make BONUS=1 $(NAME_SERVER) $(OBJ_DIR_CLIENT_BONUS) $(NAME_CLIENT)
#definimos aqui una var BONUS=1 para poder desviarlo hacia el segundo $(NAME_SERVER)
#y que asi nos cree el ejecutable 'server' del bonus, ya que tiene el mismo nombre que el sin bonus 


ifndef BONUS
$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) libft/libft.a -o $(NAME_SERVER) $(OBJ_SERVER)
$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) libft/libft.a -o $(NAME_CLIENT) $(OBJ_CLIENT)
else
$(NAME_SERVER): $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) libft/libft.a -o $(NAME_SERVER) $(OBJ_SERVER_BONUS)
$(NAME_CLIENT): $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) libft/libft.a -o $(NAME_CLIENT) $(OBJ_CLIENT_BONUS)
endif


$(OBJ_DIR_SERVER):
	mkdir $(OBJ_DIR_SERVER)
$(OBJ_DIR_CLIENT):
	mkdir $(OBJ_DIR_CLIENT)
#-------------------------
$(OBJ_DIR_SERVER_BONUS):
	mkdir $(OBJ_DIR_SERVER_BONUS)
$(OBJ_DIR_CLIENT_BONUS):
	mkdir $(OBJ_DIR_CLIENT_BONUS)


makelib:
	$(MAKE) -C libft/


$(OBJ_DIR_SERVER)/%.o : %.c  Makefile libft/libft.h libft/libft.a
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJ_DIR_CLIENT)/%.o : %.c  Makefile libft/libft.h libft/libft.a
	$(CC) -c $(CFLAGS) $< -o $@
#-------------------------------------------------------------------
$(OBJ_DIR_SERVER_BONUS)/%.o : %.c  Makefile libft/libft.h libft/libft.a
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJ_DIR_CLIENT_BONUS)/%.o : %.c  Makefile libft/libft.h libft/libft.a
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	$(MAKE) -C libft clean
	rm -f -r $(OBJ_DIR_SERVER) $(OBJ_DIR_CLIENT) $(OBJ_DIR_SERVER_BONUS) $(OBJ_DIR_CLIENT_BONUS)


fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)


re: fclean all


.PHONY: all clean fclean re makelib bonus
