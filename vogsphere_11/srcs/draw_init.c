/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:51:54 by xtang             #+#    #+#             */
/*   Updated: 2020/08/16 12:51:58 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	redraw_init(t_redraw **redraw, t_image_map *image_map,\
									t_fdf *fdf, t_ctler *ctler)
{
	*redraw = (t_redraw *)malloc(sizeof(t_redraw));
	(*redraw)->ctler = ctler;
	(*redraw)->fdf = fdf;
	(*redraw)->image_map = image_map;
}

void	draw_image_blackground(t_fdf *fdf)
{
	int *image;
	int i;

	ft_bzero(fdf->data_addr, IMAGE_WIDTH * IMAGE_HEIGHT\
								* (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < IMAGE_WIDTH * IMAGE_HEIGHT)
	{
		image[i] = COLOR_BACKGROUND;
		i++;
	}
}
