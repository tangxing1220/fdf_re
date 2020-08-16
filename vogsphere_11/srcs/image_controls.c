/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 20:06:01 by xtang             #+#    #+#             */
/*   Updated: 2020/08/13 20:40:40 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		mouse_buttons_press(int button, int x, int y, void *param)
{
	t_redraw	*redraw;

	(void)x;
	(void)y;
	redraw = (t_redraw *)param;
	if (button == MLX_M_LEFT_BUTTON)
		redraw->ctler->mouse_key_pressed = true;
	else if (button == MLX_M_SCROLL_DOWN || button == MLX_M_SCROLL_UP)
		image_zoom(button, redraw);
	return (0);
}

int		mouse_buttons_release(int button, int x, int y, void *param)
{
	t_redraw	*redraw;

	(void)x;
	(void)y;
	(void)button;
	redraw = (t_redraw *)param;
	redraw->ctler->mouse_key_pressed = false;
	return (0);
}

int		mouse_movement(int x, int y, void *param)
{
	t_redraw *redraw;

	redraw = (t_redraw *)param;
	redraw->ctler->mouse_pre_x = redraw->ctler->mouse_x;
	redraw->ctler->mouse_pre_y = redraw->ctler->mouse_y;
	redraw->ctler->mouse_x = x;
	redraw->ctler->mouse_y = y;
	if (redraw->ctler->mouse_key_pressed)
	{
		redraw->ctler->camera_beta += (x - redraw->ctler->mouse_pre_x) * 0.002;
		redraw->ctler->camera_alpha += (y - redraw->ctler->mouse_pre_y) * 0.002;
		draw_image_blackground(redraw->fdf);
		draw_image(redraw->image_map, redraw->fdf, redraw->ctler);
		mlx_put_image_to_window(redraw->fdf->mlx_ptr,\
						redraw->fdf->win_ptr, redraw->fdf->img_ptr, 0, 0);
	}
	return (0);
}

int		keyboard_key_press(int key, void *param)
{
	t_redraw	*redraw;

	redraw = (t_redraw *)param;
	if (key == MLX_MAIN_PAD_ESC)
		exit(0);
	if (key == MLX_MAIN_PAD_PLUS || key == MLX_MAIN_PAD_MINUS)
		image_flatten(key, redraw);
	else if (key == MLX_MAIN_PAD_P || key == MLX_MAIN_PAD_I)
		image_projection(key, redraw);
	else if (key == MLX_NUM_PAD_PLUS || key == MLX_NUM_PAD_MINUS)
		image_zoom(key, redraw);
	else if (key == MLX_ARROW_UP || key == MLX_ARROW_DOWN
			|| key == MLX_ARROW_LEFT || key == MLX_ARROW_RIGHT)
		image_move(key, redraw);
	else if (key == MLX_NUM_PAD_2 || key == MLX_NUM_PAD_8
			|| key == MLX_NUM_PAD_4 || key == MLX_NUM_PAD_6
			|| key == MLX_NUM_PAD_1 || key == MLX_NUM_PAD_9)
		image_rotate(key, redraw);
	return (0);
}

/*
** In X11/X.h file
** Event names. Used in "type" field in XEvent structures.
** #define KeyPress       2
** #define ButtonPress    4
** #define ButtonRelease  5
** #define MotionNotify   6
** ...
*/

void	image_controls(t_fdf *fdf, t_redraw *redraw)
{
	mlx_hook(fdf->win_ptr, 4, 0, mouse_buttons_press, redraw);
	mlx_hook(fdf->win_ptr, 5, 0, mouse_buttons_release, redraw);
	mlx_hook(fdf->win_ptr, 6, 0, mouse_movement, redraw);
	mlx_hook(fdf->win_ptr, 2, 0, keyboard_key_press, redraw);
}
