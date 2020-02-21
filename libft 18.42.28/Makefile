# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 20:06:32 by xtang             #+#    #+#              #
#    Updated: 2020/02/14 14:28:23 by xtang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGES = -Wall -Werror -Wextra

INCLUDES = -I$(HEADER_DIR)
HEADER_DIR = ./includes/
HEADER_LST = libft.h \
				get_next_line.h
HEADERS = $(addprefix $(HEADER_DIR), $(HEADER_LST))

SRC_DIR = ./sources/
SRC_LST = ft_strlen.c \
		  ft_strdup.c \
		  ft_strcpy.c \
		  ft_isspace.c \
		  ft_atoi.c \
		  ft_bzero.c \
		  ft_memset.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memmove.c \
		  ft_memcpy_bwd.c \
		  ft_strcat.c \
		  ft_strchr.c \
		  ft_strcmp.c \
		  ft_strlcat.c \
		  ft_strncat.c \
		  ft_strncmp.c \
		  ft_strncpy.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strstr.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_memalloc.c \
		  ft_itoa.c \
		  ft_memdel.c \
		  ft_putchar.c \
		  ft_putchar_fd.c \
		  ft_putstr.c \
		  ft_putstr_fd.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_fd.c \
		  ft_strclr.c \
		  ft_strdel.c \
		  ft_strequ.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strnequ.c \
		  ft_strnew.c \
		  ft_strsplit.c \
		  ft_strsub.c \
		  ft_strtrim.c \
		  ft_lstnew.c \
		  ft_lstdel.c \
		  ft_lstdelone.c \
		  ft_lstadd.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  get_next_line.c

OBJ_DIR = objects/
OBJ_LST = $(patsubst %.c, %.o, $(SRC_LST))
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJ_LST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@echo "\n$(NAME) is created."
	@ranlib $(NAME)
	@echo "$(NAME) is indexed."

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(OBJ_DIR) was created."

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo ".\c"

clean:
	@rm -fr $(OBJ_DIR)
	@echo "$(OBJ_DIR) were deleted."
	@echo "object files were deleted."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) was deleted."

re: fclean all
