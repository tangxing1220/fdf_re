make -C libft/ fclean && make -C libft/
gcc  main.c  read_file.c -L ./libft -lft -I ./libft/includes