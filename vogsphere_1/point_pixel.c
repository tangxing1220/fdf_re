/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:24:48 by xtang             #+#    #+#             */
/*   Updated: 2020/08/10 16:24:51 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int default_color(int z, t_map *map)
{
    double  percent;

    if(percent < 0.2)
        return (COLOR);
    else if (percent < 0.4)
        return (COLOR);
    else if (percent < 0.6)
        return (COLOR);
    else if (percent < 0.8)
        return (COLOR);
    else
        return (COLOR);
}



t_pixel new_point(int x, int y, t_map  *map)
{
    int     index;
    t_pixel pixel;

    index = y * map->width + x;
    pixel.pixel_x = x;
    pixel.pixel_y = y;
    pixel.pixel_z = map->coords_arrs[index];
    pixel.pixel_color = map->colors_arr[index];
    if (map->colors_arr[index] = - 1)
            pixel.pixel_color = default_color();
    return(pixel);
}