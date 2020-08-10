/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:26:42 by xtang             #+#    #+#             */
/*   Updated: 2020/08/10 15:26:45 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void draw_image_blackground(t_fdf * fdf)
{
    int *image;
    int i;

    ft_bzero(fdf->data_addr, IMAGE_WIDTH * IMAGE_HEIGHT* (fdf->bits_per_pixel/8) );
    image = (int *)(fdf->data_addr);
    i = 0;
    while(i < IMAGE_WIDTH * IMAGE_HEIGHT)
    {
        image[i] = COLOR_BACKGROUND;
        i++; 
    }
}

void draw_image_menu(t_fdf *fdf)
{
    int y;

    y = 0;
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 15, y += 35, MENU_COLOR, "KEYBOARD");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Projection ISO: I");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Projection parallel: P");

    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Zoom out : -");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Zoom in  : +");

    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Image move up  :  Arrow up");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Image move down : Arrow down");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Image move left : Arrow left");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Image move right : Arrow right");

    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Rotate X-Axis : digital keyboard 2/8");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Rotate Y-Axis : digital keyboard 4/6");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Rotate Z-Axis : digital keyboard 1/9");

    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 15, y += 35, MENU_COLOR, "MOUSE");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR, "Rotate: Press and Move");

}

void draw_image(t_map *map, t_fdf *fdf)

{
    int pixel_x;
    int pixel_y;

    draw_image_blackground(fdf);
    draw_image_menu(fdf);
    pixel_y = 0;
    while(pixel_y < map->height)
    {
        pixel_x = 0;
        while(pixel_x < map->width)
        {/*
            if (x != fdf->map->width - 1)
				draw_line(project(new_point(x, y, map), fdf),
					project(new_point(x + 1, y, map), fdf), fdf);
			if (y != fdf->map->height - 1)
				draw_line(project(new_point(x, y, map), fdf),
					project(new_point(x, y + 1, map), fdf), fdf);
        */
            pixel_x++;
        }
        pixel_y++;
    }
    mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}



