/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:13:29 by xtang             #+#    #+#             */
/*   Updated: 2020/08/10 14:13:32 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "libft.h"

t_fdf	*fdf_map_init(t_map *map)
{
    t_map   *tmp_map;
    t_fdf   *tmp_fdf;

    tmp_map = (t_map *)malloc(sizeof(t_map));
    tmp_map->image_width = 0;
    tmp_map->image_height = 0;
    tmp_map->coords_arr = NULL;
    tmp_map->coords_arr = NULL;
    tmp_map->z_min = FT_MIN;
    tmp_map->z_max = FT_MAX;


    tmp_fdf = (t_fdf *)malloc(sizeof(t_fdf));

    tmp_fdf->mlx_ptr = mlx_init();

    tmp_fdf->win_ptr = mlx_new_window(tmp_fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF xtang");

    tmp_fdf->img_ptr = mlx_new_image(tmp_fdf->mlx_ptr, WIDTH, HEIGHT);

    tmp_fdf->data_addr = mlx_get_data_addr(tmp_fdf->img_ptr, &(tmp_fdf->bits_per_pixel), &(tmp_fdf->size_line),&(tmp_fdf->endian));

    tmp_fdf->map = tmp_map;

    return (tmp_fdf);
}
