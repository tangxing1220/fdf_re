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

#include "main.h"

void	free_link_list(t_raw_dot *raw_dot_list)
{
	t_raw_dot	*p_ptr;
	t_raw_dot	*q_ptr;

	p_ptr = raw_dot_list;
	while (p_ptr != NULL)
	{
		q_ptr = p_ptr->next;
		free(p_ptr);
		p_ptr = q_ptr;
	}
	raw_dot_list->next = NULL;
}

void	open_read_file(t_image_map **image_map, char *filename)
{
	int			fd;
	t_raw_dot	*raw_dot_list;
	int			row;
	int			column;

	raw_dot_list = NULL;
	fd = open(filename, O_RDONLY);
	read_from_file(&raw_dot_list, fd, &row, &column);
	get_image_map(raw_dot_list, image_map, row, column);
	free_link_list(raw_dot_list);
}

int		main(int argc, char **argv)
{
	t_image_map	*image_map;
	t_fdf		*fdf;
	t_ctler		*ctler;
	t_redraw	*redraw;

	if (argc == 2)
	{
		open_read_file(&image_map, argv[1]);
		controler_init(&ctler, image_map);
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		fdf->mlx_ptr = mlx_init();
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, \
			WIN_HEIGHT, "FDF xtang");
		fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, IMAGE_WIDTH, IMAGE_HEIGHT);
		fdf->data_addr = mlx_get_data_addr(fdf->img_ptr, \
				&(fdf->bits_per_pixel), &(fdf->size_line), &(fdf->endian));
		draw_image_blackground(fdf);
		draw_image(image_map, fdf, ctler);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
		redraw_init(&redraw, image_map, fdf, ctler);
		image_controls(fdf, redraw);
		mlx_loop(fdf->mlx_ptr);
	}
	return (0);
}
