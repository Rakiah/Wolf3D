# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/18 21:30:01 by bkabbas           #+#    #+#              #
#    Updated: 2016/07/26 21:17:33 by Rakiah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
PATH_SRC = src/
PATH_HEADERS = -I includes/ \
			   -I libft/includes/ \
			   -I rlists/includes/ \
			   -I SDL2/includes/ \
			   -I ~/.brew/include/SDL2/
PATH_INPUT = $(PATH_SRC)input/
SRC = $(PATH_SRC)main.c $(PATH_SRC)raycaster.c $(PATH_SRC)tools.c $(PATH_SRC)loaders.c $(PATH_SRC)events.c $(PATH_SRC)floor_ceiling.c
SRC += $(PATH_INPUT)mouse_motion.c $(PATH_INPUT)focus_handler.c $(PATH_INPUT)key_down.c $(PATH_INPUT)key_up.c $(PATH_INPUT)mouse_down.c $(PATH_INPUT)mouse_up.c $(PATH_INPUT)mouse_pos.c $(PATH_INPUT)internal_behavior.c $(PATH_INPUT)mlx_to_r3d.c $(PATH_INPUT)mlx_to_r3d_alphabet.c $(PATH_INPUT)mlx_to_r3d_keypad.c $(PATH_INPUT)mlx_to_r3d_special.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CLIBS_PATH =	-L libft/ \
				-L rlists/ \
				-L ~/.brew/lib/
CLIBS =		-l ft \
		-l rlists \
		-l m \
		-l SDL2
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C rlists/
	$(CC) $(CFLAGS) $(CLIBS_PATH) -o $(NAME) $(OBJ) $(CLIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(PATH_HEADERS) -o $@ -c $<

nolib: $(NAME)
	$(CC) $(CFLAGS) $(CLIBS_PATH) -o $(NAME) $(OBJ) $(CLIBS)

clean:
	@rm -f $(OBJ)
	make -C libft/ clean
	make -C rlists/ clean
	@echo removed binary files

fclean: clean
	@rm -f $(NAME)
	make -C libft/ fclean
	make -C rlists/ fclean
	@echo removed library

re: fclean all

.PHONY: all clean fclean re nolib
