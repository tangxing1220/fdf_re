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
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Projection ISO      : I");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Projection parallel : P");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Exit  :  ESC");

    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Zoom in  : + digital pad");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Zoom out : - digital pad");

    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Flatten high : + main pad");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Flatten low  : - main pad");

    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Image move up    : Arrow up");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Image move down  : Arrow down");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Image move left  : Arrow left");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Image move right : Arrow right");

    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Rotate X-Axis : 2/8 digital pad");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Rotate Y-Axis : 4/6 digital pad");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR,  "Rotate Z-Axis : 1/9 digital pad");

    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 15, y += 35, MENU_COLOR, "MOUSE");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR, "Rotate: Press and Move");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR, "Zoom out : scroll up");
    mlx_string_put(fdf->mlx_ptr, fdf->mlx_ptr, 57, y += 35, MENU_COLOR, "Zoom in  : scroll down");
}


static void put_pixel(t_fdf *fdf, int x, int y, int color)
{
    int i;
    if ((x >= 0 && x < WIN_WIDTH) && (y >= 0 && y < WIN_HEIGHT))
    {
        i = (x * fdf->bits_per_pixel/8)+ (y * fdf->size_line);
        fdf->data_addr[i] = color;
        fdf->data_addr[++i] = color >> 8;
        fdf->data_addr[++i] = color >> 16;
    }
}

static void draw_line(t_pixel str, t_pixel end, t_fdf *fdf)
{
    t_pixel diff;
    t_pixel sign;
    t_pixel current;
    int     color;
    int     error1;
    int     error2;

    diff.pixel_x = (end.pixel_x - str.pixel_x > 0) ? (end.pixel_x - str.pixel_x) : (str.pixel_x - end.pixel_x); 
    diff.pixel_y = (end.pixel_y - str.pixel_y > 0) ? (end.pixel_y - str.pixel_y) : (str.pixel_y - end.pixel_y); 
    sign.pixel_x = (str.pixel_x < end.pixel_x) ? 1 : -1;
    sign.pixel_y = (str.pixel_y < end.pixel_y) ? 1 : -1;
    error1 = diff.pixel_x - diff.pixel_y;
    current = str;
    while(current.pixel_x != end.pixel_x || current.pixel_y != end.pixel_y)
    {
        color = get_color(current, str, end, diff);
        put_pixel(fdf, current.pixel_x, current.pixel_y, color);
        error2 = 2 * error1;
        if (error2 > (-1 * diff.pixel_y))
        {
            error1 = error1 - diff.pixel_y;
            current.pixel_x = + current.pixel_x + sign.pixel_x;
        }
        if (error2 < diff.pixel_x)
        {
            error1 = error1 + diff.pixel_x;
            current.pixel_y = current.pixel_y + sign.pixel_y;
        }
    }
}


t_pixel project(t_pixel pixel, t_fdf *fdf)
{
    pixel.pixel_x = fdf->camera->zoom;
    pixel.pixel_y = fdf->camera->zoom;
    pixel.pixel_z = fdf->camera->zoom / fdf->camera->z_divisor;

    pixel.pixel_x = pixel.pixel_x - fdf->map->width * fdf->camera->zoom /2;
    pixel.pixel_y = pixel.pixel_x - fdf->map->height * fdf->camera->zoom /2;

    rotate_x(&pixel.pixel_y, &pixel.pixel_z, fdf->camera->alpha);
    rotate_y(&pixel.pixel_x, &pixel.pixel_z, fdf->camera->beta);
    rotate_z(&pixel.pixel_x, &pixel.pixel_y, fdf->camera->gamma);

    if ( fdf-> camera->projection == ISO)
        iso(&pixel.pixel_x, &pixel.pixel_y, pixel.z);

    pixel.pixel_x = pixel.pixel_x +  WIN_WIDTH / 2 + fdf->camera->x_offset;
    pixel.pixel_y = pixel.pixel_y +  WIN_HEIGHT + fdf->map->height * fdf->camera->zoom / 2 + fdf->camera->y_offset;

    return (pixel);

}

t_pixel new_point(int x, int y, t_map *map)
{
    int i;
    t_pixel pixel;

    i = y * map->width + x;
    pixel.pixel_x = x;
    pixel.pixel_y = y;
    pixel.pixel_z = map->coords_arr[i];
    if (map->colors_arr[i] == -1)
        pixel.pixel_color = get_default_color(pixel.pixel_z, map);
    else
        pixel.pixel_color = map->colors_arr[i];
    return (pixel);
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



