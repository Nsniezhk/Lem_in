# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/27 12:54:36 by nsniezhk          #+#    #+#              #
#    Updated: 2018/06/27 12:54:38 by nsniezhk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = bfs.c comands_and_comments.c del.c\
		errors.c graph_init.c links_useful.c\
		lists_funcs.c tmp.c main.c\
		nodes.c parse_farm_1.c parse_farm_2.c path.c\
		path_cross.c project_useful.c push_ants.c queue.c\
		rooms_useful.c rooms_useful_2.c 
CC = gcc
CFLAGS	=	-Wall	-Wextra	-Werror

OBJ 	= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
.SILENT:

SRC_DIR	=	./src/
INC_DIR	=	./header/
OBJ_DIR	=	./obj/

FT	=	./libft
LIB_FT	= $(addprefix $(FT), libft.a)
PRINTF	= -I ./libft/ft_printf/header
LIB_INC	=	-I ./libft/
LIB_LNK	=	-L ./libft -l ft

all: obj $(LIB_FT) $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(PRINTF) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<

$(LIB_FT):
	make -C $(FT)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "LibFT created"

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB_LNK) -lm -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Lem_in compilation completed!"

clean:
	rm -rf $(OBJ_DIR)
	make -C $(FT) clean
	printf '\0\x1b[36m[ ✔ ] %s\n\033[0m' "Cleaned"

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean
	printf '\0\x1b[36m[ ✔ ] %s\n\033[0m' "Fcleaned"

re: fclean all
