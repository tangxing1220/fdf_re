 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:16:30 by xtang             #+#    #+#             */
/*   Updated: 2020/08/10 13:33:07 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define  MAIN_H

# include <stddef.h>
# include <stdlib.h>
# include "libft.h"

# define FT_MAX   500
# define FT_MIN	  50
# define WIN_HEIGHT		1080
# define WIN_WIDTH		1920
# define IMAGE_HEIGHT		1080
# define IMAGE_WIDTH		1920


# define COLOR_BACKGROUND	0x222222
# define MENU_COLOR			0xEAEAEA

typedef struct				s_raw_point
{
	int                     coord_x;
	int                     coord_y;
	int                     coord_z;
	int                     coord_color;
	struct s_coord_point	*next;
}							t_raw_dot;

typedef struct				s_fdf
{
	void					*mlx_ptr;
	void					*win_ptr;
	void 					*img_ptr;
	char					*data_addr;
	int						bits_per_pixel;
	int 					size_line;
	int						endian;
}							t_fdf;

typedef struct 				s_mouse_ctl
{
	char					key_pressed;
	int						mouse_x;
	int						mouse_y;
	int						pre_mouse_x;
	int						pre_mouse_y;
}							t_mouse_ctl;

typedef struct				s_camera
{
	int 					projection_type;
	int						zoom;
	double					alpha;
	double					beta;
	double					gamma;
	float					zdivisor;
	int						x_offset;
	int						y_offset;
}							t_camera_ctl;



typedef struct				s_control
{
	t_camera_ctl			*camera;
	t_map					*map;
	t_mouse_ctl				*mouse;
}							t_control;

typedef struct				s_image_map
{
	int 					image_width;
	int						image_height;
	int						*coords_arr;
	int						*colors_arr;
	int						z_min;
	int						z_max;
}							t_image_map;

typedef struct				s_pixel
{
	int						pixel_x;
	int						pixel_y;
	int						pixel_z;
	int						pixel_color;
}							t_pixel;

int		read_from_file(t_raw_dot **raw_dots, const int fd);
t_fdf	*fdf_map_init(t_map *map);

void 	draw_image(t_map *map, t_fdf *fdf);

t_image_map  *get_image_map(t_raw_dot *raw_dot_list);

#endif
