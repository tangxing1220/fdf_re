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

void	diff_sign(t_pixel str, t_pixel end, t_pixel *diff, t_pixel *sign)
{
	diff->x = (end.x - str.x > 0) ? (end.x - str.x) : (str.x - end.x);
	diff->y = (end.y - str.y > 0) ? (end.y - str.y) : (str.y - end.y);
	sign->x = (str.x < end.x) ? 1 : -1;
	sign->y = (str.y < end.y) ? 1 : -1;
}

void	draw_line(t_pixel str, t_pixel end, t_fdf *fdf)
{
	int		err_a;
	int		err_b;
	t_pixel diff;
	t_pixel sign;
	t_pixel current;

	diff_sign(str, end, &diff, &sign);
	err_a = diff.x - diff.y;
	current = str;
	while (current.x != end.x || current.y != end.y)
	{
		put_pixel(fdf, current.x, current.y, get_color(current, str, end));
		err_b = 2 * err_a;
		if (err_b > (-1 * diff.y))
		{
			err_a = err_a - diff.y;
			current.x = current.x + sign.x;
		}
		if (err_b < diff.x)
		{
			err_a = err_a + diff.x;
			current.y = current.y + sign.y;
		}
	}
}

t_pixel	dot_to_pixel(int x, int y, t_ctler *ctler, t_image_map *image_map)
{
	int		i;
	t_pixel	pixel;

	i = y * image_map->image_width + x;
	pixel.x = x;
	pixel.y = y;
	pixel.z = image_map->coords_arr[i];
	if (image_map->colors_arr[i] == 0)
		pixel.color = default_color(pixel.z, image_map);
	else
		pixel.color = image_map->colors_arr[i];
	pixel.x = pixel.x * ctler->camera_zoom;
	pixel.y = pixel.y * ctler->camera_zoom;
	pixel.z = pixel.z * ctler->camera_zoom / ctler->camera_z_divisor;
	pixel.x = pixel.x - (image_map->image_width * ctler->camera_zoom) / 2;
	pixel.y = pixel.y - (image_map->image_height * ctler->camera_zoom) / 2;
	rotate_x(&pixel.y, &pixel.z, ctler->camera_alpha);
	rotate_y(&pixel.x, &pixel.z, ctler->camera_beta);
	rotate_z(&pixel.x, &pixel.y, ctler->camera_gamma);
	if (ctler->projection_type == PRO_ISO)
		iso(&pixel.x, &pixel.y, pixel.z);
	pixel.x = pixel.x + WIN_WIDTH / 2 + ctler->camera_offset_x;
	pixel.y = pixel.y + (WIN_HEIGHT + image_map->image_height\
					* ctler->camera_zoom) / 2 + ctler->camera_offset_y;
	return (pixel);
}

void	draw_image(t_image_map *image_map, t_fdf *fdf, t_ctler *ctrler)
{
	int		dot_x;
	int		dot_y;
	t_pixel pro_pixel;
	t_pixel pro_pixel_x;
	t_pixel pro_pixel_y;

	dot_y = 0;
	while (dot_y < image_map->image_height)
	{
		dot_x = 0;
		while (dot_x < image_map->image_width)
		{
			pro_pixel = dot_to_pixel(dot_x, dot_y, ctrler, image_map);
			pro_pixel_x = dot_to_pixel(dot_x + 1, dot_y, ctrler, image_map);
			pro_pixel_y = dot_to_pixel(dot_x, dot_y + 1, ctrler, image_map);
			if (dot_x != image_map->image_width - 1)
				draw_line(pro_pixel, pro_pixel_x, fdf);
			if (dot_y != image_map->image_height - 1)
				draw_line(pro_pixel, pro_pixel_y, fdf);
			dot_x++;
		}
		dot_y++;
	}
}
