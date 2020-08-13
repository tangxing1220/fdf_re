/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:26:42 by xtang             #+#    #+#             */
/*   Updated: 2020/08/13 20:30:10 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_image_blackground(t_fdf *fdf)
{
	int *image;
	int i;

	ft_bzero(fdf->data_addr, IMAGE_WIDTH * IMAGE_HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < IMAGE_WIDTH * IMAGE_HEIGHT)
	{
		image[i] = COLOR_BACKGROUND;
		i++;
	}
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, 15, MENU_COLOR, "SHOW HELP MENU : press H key");
}

void	draw_image_menu(t_fdf *fdf)
{
	int y;

	y = 0;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, y += 35, MENU_COLOR, "KEYBOARD");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Projection ISO      : I");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Projection parallel : P");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Show help menu      : H");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Exit  :  ESC");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Zoom in  : + digital pad");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Zoom out : - digital pad");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Flatten high : + main pad");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Flatten low  : - main pad");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Image move up    : Arrow up");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Image move down  : Arrow down");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Image move left  : Arrow left");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Image move right : Arrow right");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Rotate X-Axis : 2/8 digital pad");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Rotate Y-Axis : 4/6 digital pad");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Rotate Z-Axis : 1/9 digital pad");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 15, y += 35, MENU_COLOR, "MOUSE");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Rotate: Press and Move");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Zoom out : scroll up");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 57, y += 35, MENU_COLOR, "Zoom in  : scroll down");
}

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int i;

	if ((x >= 0 && x < WIN_WIDTH) && (y >= 0 && y < WIN_HEIGHT))
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

void	draw_line(t_pixel str, t_pixel end, t_fdf *fdf)
{
	int		color;
	int		error1;
	int		error2;
	t_pixel diff;
	t_pixel sign;
	t_pixel current;

	diff.pixel_x = (end.pixel_x - str.pixel_x > 0) ? (end.pixel_x - str.pixel_x) : (str.pixel_x - end.pixel_x);
	diff.pixel_y = (end.pixel_y - str.pixel_y > 0) ? (end.pixel_y - str.pixel_y) : (str.pixel_y - end.pixel_y);
	sign.pixel_x = (str.pixel_x < end.pixel_x) ? 1 : -1;
	sign.pixel_y = (str.pixel_y < end.pixel_y) ? 1 : -1;
	error1 = diff.pixel_x - diff.pixel_y;
	current = str;
	while (current.pixel_x != end.pixel_x || current.pixel_y != end.pixel_y)
	{
		color = get_color(current, str, end);
		put_pixel(fdf, current.pixel_x, current.pixel_y, color);
		error2 = 2 * error1;
		if (error2 > (-1 * diff.pixel_y))
		{
			error1 = error1 - diff.pixel_y;
			current.pixel_x = current.pixel_x + sign.pixel_x;
		}
		if (error2 < diff.pixel_x)
		{
			error1 = error1 + diff.pixel_x;
			current.pixel_y = current.pixel_y + sign.pixel_y;
		}
	}
}

t_pixel	project(t_pixel pixel, t_fdf *fdf, t_ctler *ctler, t_image_map *image_map)
{
	pixel.pixel_x = pixel.pixel_x * ctler->camera_zoom;
	pixel.pixel_y = pixel.pixel_y * ctler->camera_zoom;
	pixel.pixel_z = pixel.pixel_z * ctler->camera_zoom / ctler->camera_z_divisor;
	pixel.pixel_x = pixel.pixel_x - (image_map->image_width * ctler->camera_zoom) / 2;
	pixel.pixel_y = pixel.pixel_y - (image_map->image_height * ctler->camera_zoom) / 2;
	rotate_x(&pixel.pixel_y, &pixel.pixel_z, ctler->camera_alpha);
	rotate_y(&pixel.pixel_x, &pixel.pixel_z, ctler->camera_beta);
	rotate_z(&pixel.pixel_x, &pixel.pixel_y, ctler->camera_gamma);
	if (ctler->projection_type == PROJECTION_ISO)
		iso(&pixel.pixel_x, &pixel.pixel_y, pixel.pixel_z);
	pixel.pixel_x = pixel.pixel_x + WIN_WIDTH / 2 + ctler->camera_offset_x;
	pixel.pixel_y = pixel.pixel_y + (WIN_HEIGHT + image_map->image_height * ctler->camera_zoom) / 2 + ctler->camera_offset_y;
	return (pixel);
}

t_pixel	new_point(int x, int y, t_image_map *image_map)
{
	int		i;
	t_pixel	pixel;

	i = y * image_map->image_width + x;
	pixel.pixel_x = x;
	pixel.pixel_y = y;
	pixel.pixel_z = image_map->coords_arr[i];
	if (image_map->colors_arr[i] == 0)
		pixel.pixel_color = default_color(pixel.pixel_z, image_map);
	else
		pixel.pixel_color = image_map->colors_arr[i];
	return (pixel);
}

void	draw_image(t_image_map *image_map, t_fdf *fdf, t_ctler *ctrler)
{
	int		dot_x;
	int		dot_y;
	t_pixel original;
	t_pixel original_x;
	t_pixel original_y;
	t_pixel pro_pixel;
	t_pixel pro_pixel_x;
	t_pixel pro_pixel_y;

	draw_image_blackground(fdf);
	if (ctrler->show_menu == 1)
		draw_image_menu(fdf);
	dot_y = 0;
	while (dot_y < image_map->image_height)
	{
		dot_x = 0;
		while (dot_x < image_map->image_width)
		{
			original = new_point(dot_x, dot_y, image_map);
			original_x = new_point(dot_x + 1, dot_y, image_map);
			original_y = new_point(dot_x, dot_y + 1, image_map);
			pro_pixel = project(original, fdf, ctrler, image_map);
			pro_pixel_x = project(original_x, fdf, ctrler, image_map);
			pro_pixel_y = project(original_y, fdf, ctrler, image_map);
			if (dot_x != image_map->image_width - 1)
				draw_line(pro_pixel, pro_pixel_x, fdf);
			if (dot_y != image_map->image_height - 1)
				draw_line(pro_pixel, pro_pixel_y, fdf);
			dot_x++;
		}
		dot_y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

void	redraw_init(t_redraw **redraw, t_image_map *image_map, t_fdf *fdf, t_ctler *ctler)
{
	*redraw = (t_redraw *)malloc(sizeof(t_redraw));
	(*redraw)->ctler = ctler;
	(*redraw)->fdf = fdf;
	(*redraw)->image_map = image_map;
}
