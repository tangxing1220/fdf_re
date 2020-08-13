#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xtang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 18:00:46 by xtang             #+#    #+#              #
#    Updated: 2019/10/22 15:46:09 by xtang            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAG = -Wall -Wextra -Werror -Iincludes

NAME = libft.a

SRC = ft_strlen.c \
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


OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all
