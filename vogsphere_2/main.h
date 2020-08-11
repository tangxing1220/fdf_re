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

# define PROJECTION_ISO			1
# define PROJECTION_PARALLEL	2

/*
** Useful link, you can get key event return valaue 
** https://css-tricks.com/snippets/javascript/javascript-keycodes/
*/


# define COLOR_BACKGROUND	0x222222
# define MENU_COLOR			0xEAEAEA

# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

# define MLX_MOUSE_LEFT_BUTTON	1
# define MLX_MOUSE_SCROLL_UP    4
# define MLX_MOUSE_SCROLL_DOWN  5

# define MLX_ARROW_LEFT			123
# define MLX_ARROW_RIGHT		124
# define MLX_ARROW_DOWN			125
# define MLX_ARROW_UP			126

# define MLX_NUM_PAD_1			83
# define MLX_NUM_PAD_2			84
# define MLX_NUM_PAD_4			86
# define MLX_NUM_PAD_6			88
# define MLX_NUM_PAD_8			91
# define MLX_NUM_PAD_9			92
# define MLX_NUM_PAD_PLUS		69
# define MLX_NUM_PAD_MINUS		78

# define MLX_MAIN_PAD_ESC		53
# define MLX_MAIN_PAD_I			34
# define MLX_MAIN_PAD_P			35
# define MLX_MAIN_PAD_MINUS		27
# define MLX_MAIN_PAD_PLUS		24


typedef struct				s_raw_point
{
	int                     coord_x;
	int                     coord_y;
	int                     coord_z;
	int                     coord_color;
	struct s_coord_point	*next;
}							t_raw_dot;

typedef struct				s_pixel
{
	int						pixel_x;
	int						pixel_y;
	int						pixel_z;
	int						pixel_color;
}							t_pixel;

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

typedef struct				s_ctler
{
	int 					projection_type;

	char					mouse_key_pressed;
	int						mouse_x;
	int						mouse_y;
	int						mouse_pre_x;
	int						mouse_pre_y;
	
	int						camera_zoom;
	double					camera_alpha;
	double					camera_beta;
	double					camera_gamma;
	float					camera_z_divisor;
	int						camera_offset_x;
	int						camera_offset_y;
}							t_ctler;

typedef struct				s_image_map
{
	int 					image_width;
	int						image_height;
	int						*coords_arr;
	int						*colors_arr;
	int						z_min;
	int						z_max;
}							t_image_map;

int		read_from_file(t_raw_dot **raw_dots, const int fd);

t_fdf	*fdf_map_init(t_map *map);

void 	draw_image(t_map *map, t_fdf *fdf);

t_image_map  *get_image_map(t_raw_dot *raw_dot_list);

void image_controls(t_fdf *fdf);

#endif
