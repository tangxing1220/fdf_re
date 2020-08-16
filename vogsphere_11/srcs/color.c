/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 19:52:44 by xtang             #+#    #+#             */
/*   Updated: 2020/08/13 19:34:33 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	precent_cal(int str, int end, int current)
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

int		get_light(int str, int end, double precent)
{
	int result;

	result = (int)(str * (1 - precent) + end * precent);
	return (result);
}

int		get_color(t_pixel current, t_pixel str, t_pixel end)
{
	int		red;
	int		green;
	int		blue;
	double	precent;
	t_pixel	diff;

	diff.x = (end.x - str.x > 0) ? (end.x - str.x) : (str.x - end.x);
	diff.y = (end.y - str.y > 0) ? (end.y - str.y) : (str.y - end.y);
	if (current.color == end.color)
		return (current.color);
	if (diff.x > diff.y)
		precent = precent_cal(str.x, end.x, current.x);
	else
		precent = precent_cal(str.y, end.y, current.y);
	red = get_light((str.color >> 16) & 0xFF, \
			(end.color >> 16) & 0xFF, precent);
	green = get_light((str.color >> 8) & 0xFF, \
			(end.color >> 8) & 0xFF, precent);
	blue = get_light(str.color & 0xFF, end.color & 0xFF, precent);
	return ((red << 16) | (green << 8) | blue);
}
