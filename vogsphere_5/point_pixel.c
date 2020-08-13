/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:24:48 by xtang             #+#    #+#             */
/*   Updated: 2020/08/13 20:59:51 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	iso(int *x, int *y, int z)
{
	int pre_x;
	int pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = (pre_x - pre_y) * cos(0.523599);
	*y = (pre_x + pre_y) * sin(0.523599) - z;
}

void	rotate_x(int *y, int *z, double alpha)
{
	int pre_y;

	pre_y = *y;
	*y = pre_y * cos(alpha) + *z * sin(alpha);
	*z = *z * cos(alpha) - pre_y * sin(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int pre_x;

	pre_x = *x;
	*x = pre_x * cos(beta) + *z * sin(beta);
	*z = *z * cos(beta) - pre_x * sin(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int pre_x;
	int pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = pre_x * cos(gamma) - pre_y * sin(gamma);
	*y = pre_x * sin(gamma) + pre_y * cos(gamma);
}

int		default_color(int z, t_image_map *image_map)
{
	double	percent_val;
	double	placement;
	double	distance;

	placement = z - image_map->z_min;
	distance = image_map->z_max - image_map->z_min;
	if (distance == 0)
		percent_val = 1.0;
	else
		percent_val = placement / distance;
	if (percent_val < 0.2)
		return (COLOR_DISCO);
	else if (percent_val < 0.4)
		return (COLOR_BRICK_RED);
	else if (percent_val < 0.6)
		return (COLOR_FLAMINGO);
	else if (percent_val < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}
