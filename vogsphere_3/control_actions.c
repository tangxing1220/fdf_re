/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:43:20 by xtang             #+#    #+#             */
/*   Updated: 2020/08/11 16:43:23 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void image_zoom(int key, t_fdf *fdf)
{
    if (key == MLX_NUM_PAD_PLUS || MLX_MOUSE_SCROLL_UP)
        fdf->camera->zoom++;
    else if (key == MLX_NUM_PAD_MINUS || MLX_MOUSE_SCROLL_DOWN)
        fdf->camera->zoom--;

    if (fdf->camera->zoom < 1)
        fdf->camera->zoom = 1;
    draw(fdf->map, fdf);
}


void image_flatten(int key, t_fdf *fdf)
{
    if (key == MLX_MAIN_PAD_MINUS)
        fdf->camera->z_divisor = fdf->camera->z_divisor - 0.1;
    else if (key == MLX_MAIN_PAD_PLUS)
        fdf->camera->z_divisor = fdf->camera->z_divisor + 0.1;
    
    if (fdf->camera->z_divisor < 0.1)
        fdf->camera->z_divisor = 0.1;
    else if (fdf->camera->z_divisor > 10)
        fdf->camera->z_divisor = 10;
    draw(fdf->map, fdf);
}



void image_projection(int key, t_fdf *fdf)
{
    fdf->camera->alpha = 0;
    fdf->camera->beta = 0;
    fdf->camera->gamma = 0;
    if (key ==  MLX_MAIN_PAD_I)
        fdf->camera->projection = PROJECTION_ISO;
    else if (key == MLX_MAIN_PAD_P)
        fdf->camera->projection = PROJECTION_PARALLEL;
    draw(fdf->map, fdf);
}

void image_move(int key, t_fdf *fdf)
{
    if (key == MLX_ARROW_DOWN)
        fdf->camera->y_offset = fdf->camera->y_offset + 10;
    else if (key == MLX_ARROW_UP)
        fdf->camera->y_offset = fdf->camera->y_offset - 10;       
    else if (key == MLX_ARROW_RIGHT)
        fdf->camera->x_offset = fdf->camera->x_offset + 10;
    else if (key == MLX_ARROW_LEFT)
        fdf->camera->x_offset = fdf->camera->x_offset - 10;
    draw(fdf->map, fdf);
}


void image_rotate(int key, t_fdf *fdf)
{
    if (key == MLX_NUM_PAD_2)
        fdf->camera->alpha = fdf_camera->alpha + 0.05;
    else if (key == MLX_NUM_PAD_8)
        fdf->camera->alpha = fdf_camera->alpha - 0.05;
    else if (key == MLX_NUM_PAD_4)
        fdf->camera->beta = fdf_camera->beta + 0.05;
    else if (key == MLX_NUM_PAD_6)
        fdf->camera->beta = fdf_camera->beta - 0.05;
    else if (key == MLX_NUM_PAD_1)
        fdf->camera->gamma = fdf_camera->gamma + 0.05;
    else if (key == MLX_NUM_PAD_9)
        fdf->camera->gamma = fdf_camera->gamma - 0.05;
    draw(fdf->map, fdf);
}