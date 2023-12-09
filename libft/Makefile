# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 16:15:05 by jocuni-p          #+#    #+#              #
#    Updated: 2023/07/10 10:51:09 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

#nom del programa-binari que crearem


LIB = ar -rcs

#'ar' es una utilitat per crear i mantenir grups d'arxius combinats en un sol
#arxu i l'usarem  per crear la llibreria
#'r' la reeemplasara si existeix ja i la creara si no existeix
#'c' fa que es silencii el missatge de la creacio de ar
#'s' escriu un index d'arxius objecte a dins per el seu control intern


SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	  ft_strlen.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c\
	  ft_strncmp.c ft_atoi.c ft_memset.c ft_bzero.c ft_memchr.c\
	  ft_memcpy.c ft_memcmp.c ft_memmove.c ft_strlcpy.c ft_strnstr.c\
	  ft_calloc.c ft_strdup.c ft_strlcat.c ft_substr.c ft_strjoin.c\
	  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	  ft_putnbr_fd.c


#arxius source que utilitzarem per crear el programa
#no inclou el .h perque el llegeix sense compilar-lo


SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c


OBJ = $(SRC:.c=.o)

#aqui detallem nom dels objects
#genera una llista de noms d'arxius .o a partir de la lista de noms .c


DEPS=$(SRC:.c=.d) 


OBJ_BONUS = $(SRC_BONUS:.c=.o)


#---------------------------REGLAS---------------------------------------#

all: $(NAME)

#al fer make la primera regla que trova es la que executa, sino s'especifica
#una altre


norm: 
	norminette


bonus: .bonus

-include $(DEPS)


$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)


#usem 'ar' per crear una llibreria
#si volguessim crear un programa seria 	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
#compara les dates de modificacio de de NAME i de OBJ, si NAME es posterior NO ho torna a compilar'


.bonus: $(OBJ) $(OBJ_BONUS)
	$(LIB) $(NAME) $(OBJ) $(OBJ_BONUS)
	@touch .bonus


#el 'touch .bonus' crea un arxiu ocult i es nomes per indicar que la regla .bonus ha sigut executada i la seva presencia s'utiliza com una marca per evitar que es torni a executar innecessariament al tornar a fer 'make'


%.o : %.c  Makefile
	$(CC) -c $(CFLAGS) -MMD -MP $< -o $@


#crea els .o a partir dels .c i de la libft.h
#amb cc crea els arxius de codi objecte (-c).
#La var automatica $< agafa el nom del .c (src) i $@ el dona al .o (target)


clean:
	rm -f $(OBJ) $(OBJ_BONUS) $(DEPS)


#borra els arxius creats .o (OBJ),els .bonus (OBJ_BONUS) i els .d (DEPS)
# amb -f ignorem els arxius que no existeixen, borrats ja previament


fclean: clean
	rm -f $(NAME)

#fa un 'make clean' seguit d'un 'make all' borrant el binari executable


re: fclean all

rebonus: fclean bonus

.PHONY: clean fclean re all bonus rebonus

#amb el PHONY TARGET (falso objetivo) avisem al make que aquests no son arxius
#que hagi de generar sino instruccions/reglas
