/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:43:20 by xtang             #+#    #+#             */
/*   Updated: 2020/08/13 19:45:47 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	image_zoom(int key, t_redraw *redraw)
{
	if (key == MLX_NUM_PAD_PLUS || key == MLX_MOUSE_SCROLL_UP)
		redraw->ctler->camera_zoom++;
	else if (key == MLX_NUM_PAD_MINUS || key == MLX_MOUSE_SCROLL_DOWN)
		redraw->ctler->camera_zoom--;
	if (redraw->ctler->camera_zoom < 1)
		redraw->ctler->camera_zoom = 1;
	draw_image(redraw->image_map, redraw->fdf, redraw->ctler);
}

void	image_flatten(int key, t_redraw *redraw)
{
	if (key == MLX_MAIN_PAD_MINUS)
		redraw->ctler->camera_z_divisor = redraw->ctler->camera_z_divisor - 0.1;
	else if (key == MLX_MAIN_PAD_PLUS)
		redraw->ctler->camera_z_divisor = redraw->ctler->camera_z_divisor + 0.1;
	if (redraw->ctler->camera_z_divisor < 0.1)
		redraw->ctler->camera_z_divisor = 0.1;
	else if (redraw->ctler->camera_z_divisor > 10)
		redraw->ctler->camera_z_divisor = 10;
	draw_image(redraw->image_map, redraw->fdf, redraw->ctler);
}

void	image_projection(int key, t_redraw *redraw)
{
	redraw->ctler->camera_alpha = 0;
	redraw->ctler->camera_beta = 0;
	redraw->ctler->camera_gamma = 0;
	if (key == MLX_MAIN_PAD_I)
		redraw->ctler->projection_type = PROJECTION_ISO;
	else if (key == MLX_MAIN_PAD_P)
		redraw->ctler->projection_type = PROJECTION_PARALLEL;
	draw_image(redraw->image_map, redraw->fdf, redraw->ctler);
}

void	image_move(int key, t_redraw *redraw)
{
	if (key == MLX_ARROW_DOWN)
		redraw->ctler->camera_offset_y = redraw->ctler->camera_offset_y + 10;
	else if (key == MLX_ARROW_UP)
		redraw->ctler->camera_offset_y = redraw->ctler->camera_offset_y - 10;
	else if (key == MLX_ARROW_RIGHT)
		redraw->ctler->camera_offset_x = redraw->ctler->camera_offset_x + 10;
	else if (key == MLX_ARROW_LEFT)
		redraw->ctler->camera_offset_x = redraw->ctler->camera_offset_x - 10;
	draw_image(redraw->image_map, redraw->fdf, redraw->ctler);
}

void	image_rotate(int key, t_redraw *redraw)
{
	if (key == MLX_NUM_PAD_2)
		redraw->ctler->camera_alpha = redraw->ctler->camera_alpha + 0.05;
	else if (key == MLX_NUM_PAD_8)
		redraw->ctler->camera_alpha = redraw->ctler->camera_alpha - 0.05;
	else if (key == MLX_NUM_PAD_4)
		redraw->ctler->camera_beta = redraw->ctler->camera_beta + 0.05;
	else if (key == MLX_NUM_PAD_6)
		redraw->ctler->camera_beta = redraw->ctler->camera_beta - 0.05;
	else if (key == MLX_NUM_PAD_1)
		redraw->ctler->camera_gamma = redraw->ctler->camera_gamma + 0.05;
	else if (key == MLX_NUM_PAD_9)
		redraw->ctler->camera_gamma = redraw->ctler->camera_gamma - 0.05;
	draw_image(redraw->image_map, redraw->fdf, redraw->ctler);
}

void	image_show_menu(int key, t_redraw *redraw)
{
	if (key == MLX_MAIN_PAD_H)
	{
		if (redraw->ctler->show_menu == 1)
		{
			redraw->ctler->show_menu = 0;
		}
		else
		{
			redraw->ctler->show_menu = 1;
		}
	}
	draw_image(redraw->image_map, redraw->fdf, redraw->ctler);
}
