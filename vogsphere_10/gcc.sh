make -C libft/ fclean && make -C libft/
gcc -Werror -Wall -Wextra -o fdf color.c control_actions.c control_init.c draw_image.c image_controls.c main.c point_pixel.c read_file.c -L ./libft -lft -I ./libft/includes -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
