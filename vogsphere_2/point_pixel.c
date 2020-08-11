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


 void iso(int *x, int *y, int z)
 {
     int pre_x;
     int pre_y;

     pre_x = *x;
     pre_y = * y;

     *x = (pre_x - pre_y) * cis(0.523599);
     *y = (pre_x + pre_y) * sin(0.523599) - z;
 }

 void rotate_x(int *y, int *z, double alpha)
 {
     int pre_y;
     pre_y = *y;
     *y = pre_y * cos(alpha) + *z * sin(alpha);
     *z = *z * cos(alpha) - pre_y * sin(alpha);
 }

void rotate_y(int *x, int *z, double beta)
 {
     int pre_x;
     pre_x = *x;
     *x = pre_x * cos(beta) + *z * sin(beta);
     *z = *z * cos(beta) - pre_x * sin(beta);
 }

 void rotate_z(int *x, int *y, double gamma)
 {
     int pre_x;
     int pre_y;

     pre_x = *x;
     pre_y = *y;

     *x = pre_x * cos(gamma) -  pre_y * sin(gamma);
     *y = pre_x * sin(gamma) +  pre_y * cos(gamma);
 }

int default_color(int z, t_map *map)
{
    double  percent;

    if(percent < 0.2)
        return (COLOR_DISCO);
    else if (percent < 0.4)
        return (COLOR_BRICK_RED);
    else if (percent < 0.6)
        return (COLOR_FLAMING);
    else if (percent < 0.8)
        return (COLOR_JAFFA);
    else
        return (COLOR_SAFFRON);
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