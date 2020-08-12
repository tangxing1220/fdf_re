/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 20:06:01 by xtang             #+#    #+#             */
/*   Updated: 2020/08/10 20:06:04 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int     mouse_buttons_press(int button, int x, int y, void *param)
{
    t_fdf   *fdf;
    
    (void)x;
    (void)y;
    fdf = (t_fdf *)param;
    if (button == MLX_MOUSE_LEFT_BUTTON)
        fdf->mouse->is_pressed = true; 
    else if (button == MLX_MOUSE_SCROLL_DOWN || button == MLX_MOUSE_SCROLL_UP)
       image_zoom(button, fdf);
    return (0);
}

int     mouse_buttons_release(int button, int x, int y, void *param)
{
    t_fdf   *fdf;
    
    (void)x;
    (void)y;
    (void)button;
    fdf = (t_fdf *)param;
    fdf->mouse->is_pressed = true; 
    return (0);
}

int     mouse_movement(int x, int y, void *param)
{
    t_fdf   *fdf;
    t_ctler *ctler;
    
    fdf = (t_fdf *)param;
    ctler->mouse_pre_x = ctler->mouse_x;
    ctler->mouse_pre_y = ctler->mouse_y;
    ctler->mouse_x = x;
    ctler->mouse_y = y;
    if (ctler->mouse_key_pressed)
    {
        ctler->camera_beta += (x - ctler->mouse_pre_x) * 0.002;
        ctler->camera_alpha += (y - ctler->mouse_pre_y) * 0.002;
 //   ????    draw(fdf->map, fdf);
    }
    return (0);
}

int     keyboard_key_press(int key, void *param)
{
    t_fdf   *fdf;

    fdf = (t_fdf *)param;
    if (key == MLX_MAIN_PAD_ESC)
        exit(0);

    if (key == MLX_MAIN_PAD_PLUS || key == MLX_MAIN_PAD_MINUS)
        image_flatten(key,fdf);
    else if (key == MLX_MAIN_PAD_P || key == MLX_MAIN_PAD_I)
        image_projection(key, fdf);
    else if(key == MLX_NUM_PAD_PLUS || key == MLX_NUM_PAD_MINUS)
        image_zoom(key, fdf);
    else if (key == MLX_ARROW_UP || key == MLX_ARROW_DOWN
            || MLX_ARROW_LEFT || MLX_ARROW_RIGHT)
        image_move(key,fdf);
    else if (key == MLX_NUM_PAD_2 || key == MLX_NUM_PAD_8
        || key == MLX_NUM_PAD_4 || key == MLX_NUM_PAD_6
        || key == MLX_NUM_PAD_1 || key == MLX_NUM_PAD_9)
        image_rotate(key, fdf);
    return (0);

}

/*
** In X11/X.h file
** /* Event names. Used in "type" field in XEvent structures.
** #define KeyPress       2
** #define ButtonPress    4
** #define ButtonRelease  5
** #define MotionNotify   6
** ...
*/

void image_controls(t_fdf *fdf)
{
    mlx_hook(fdf->win_ptr, 4, 0, mouse_buttons_press, fdf);
    mlx_hook(fdf->win_ptr, 5, 0, mouse_buttons_release, fdf);
    mlx_hook(fdf->win_ptr, 6, 0, mouse_movement, fdf );
    mlx_hook(fdf->win_ptr, 2, 0, keyboard_key_press, fdf);
}
