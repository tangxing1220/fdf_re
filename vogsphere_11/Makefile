# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/16 10:00:53 by xtang             #+#    #+#              #
#    Updated: 2020/08/16 10:00:57 by xtang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Werror -Wextra

INC_PATH = incl
SRC_PATH = srcs
OBJ_PATH = objs

SOURCES = main.c \
		color.c \
		control_actions.c \
		control_init.c \
		draw_image.c \
		image_controls.c \
		point_pixel.c \
		read_file.c \
		read_list.c \
		draw_init.c

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

MLX = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

.PHONY: all libft tmp clean fclean re

all: libft tmp $(NAME)

$(NAME): $(OBJS)
	@echo "create project $(NAME) file"
	@gcc $(FLAGS) -o $@ $^ -L libft/ -lft -I $(INC_PATH)/ $(MLX)


$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c 
	@echo "Create object files in objs folder"
	@gcc $(FLAGS) -c -o $@ $< -I $(INC_PATH)/ -I libft/includes

libft:
	@echo "Create libft library"
	@make -C libft/ clean
	@make -C libft/

tmp:
	@mkdir	-p objs

clean:
	@echo "Delte library files"
	@make clean -C libft/
	@rm -rf objs/

fclean:
	@echo "Delte library files and target file"
	@make clean -C libft/
	@rm -rf objs/
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all -j