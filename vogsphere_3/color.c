/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 19:52:44 by xtang             #+#    #+#             */
/*   Updated: 2020/08/11 19:52:47 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double precent_cal(int str, int end, int current)
{
    double place;
    double dist;

    place = current - str;
    dist = end - str;

    if (dist == 0)
        return (1.0);
    else
        return (place / dist);
}

int get_light(int str, int end, double precent)
{
    int result;
    result = (int)(str * (1 - precent) + end * precent); 
    return (result);
}

int get_color(t_pixel current, t_pixel str, t_pixel end)
{
    int red;
    int green;
    int blue;
    double precent;
    t_pixel diff;

    diff.pixel_x = (end.pixel_x - str.pixel_x > 0) ? (end.pixel_x - str.pixel_x) : (str.pixel_x - end.pixel_x); 
    diff.pixel_y = (end.pixel_y - str.pixel_y > 0) ? (end.pixel_y - str.pixel_y) : (str.pixel_y - end.pixel_y); 

    if (current.pixel_color == end.pixel_color)
        return (current.pixel_color);
    
    if (diff.pixel_x > diff.pixel_y)
        precent = precent_cal(str.pixel_x, end.pixel_x, current.pixel_x);
    else
        precent = precent_cal(str.pixel_y, end.pixel_y, current.pixel_y);

    red = get_light((str.pixel_color >> 16) & 0xFF, (end.pixel_color >> 16) & 0xFF, precent);    
    green = get_light((str.pixel_color >> 8) & 0xFF, (end.pixel_color >> 8) & 0xFF, precent);
    blue = get_light(str.pixel_color & 0xFF, end.pixel_color & 0xFF, precent);

    return (red << 16 | green << 8 | blue);
}
