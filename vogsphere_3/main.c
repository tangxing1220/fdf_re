/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:16:52 by xtang             #+#    #+#             */
/*   Updated: 2020/08/10 13:26:08 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "main.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_raw_dot	*raw_dot_list;
	t_image_map	*image_map;
	t_fdf		*fdf;
	t_ctler		*ctler;
	int			row;
	int			column;	

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		read_from_file(&raw_dot_list, fd, &row, &column);
		get_image_map(raw_dot_list, &image_map, &row, &column);
		controler_init(&ctler, row, column);
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		fdf->mlx_ptr = mlx_init();
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF xtang");
		fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, IMAGE_WIDTH, IMAGE_HEIGHT);
		fdf->data_addr = mlx_get_data_addr(fdf->img_ptr, &(fdf->bits_per_pixel), &(fdf->size_line), &(fdf->endian));
		draw_image(image_map, fdf, ctler);
		image_controls(fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	return (0);
}
