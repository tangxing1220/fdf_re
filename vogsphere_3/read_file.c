/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:43:01 by xtang             #+#    #+#             */
/*   Updated: 2020/08/10 13:49:43 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		ft_isdigit_base(char c, int base)
{
	const char	*digits = "0123456789ABCDEF";
	int			index;

	index = 0;
	while (index < base)
	{
		if (digits[index] == ft_toupper(c))
			return (index);
		index++;
	}
	return (-1);
}

static int		ft_atoi_base(const char *str, int base)
{
	size_t	index;
	int		result;

	index = 0;
	result = 0;
	while (ft_isspace(str[index]))
		index++;
	if (base == 16)
		index = index + 2;
	while (ft_isdigit_base(str[index], base) >= 0)
	{
		result = result * base + ft_isdigit_base(str[index++], base);
		return (result);
	}
	return (0);
}

int				read_from_file(t_raw_dot **raw_dots_list, const int fd, int *row, int *column)
{
	int			i;
	int			ret_val;
	char		*line;
	char		**line_arr;
	char		**z_color_arr;
	t_raw_dot	*raw_dot;
	t_raw_dot	*pend;

	*row = 0;
	*raw_dots_list = NULL;
	while ((ret_val = get_next_line(fd, &line)) == 1)
	{
		*column = 0;
		line_arr = ft_strsplit(line, ' ');
		while (line_arr[*column] != NULL)
		{
			raw_dot = (t_raw_dot *)malloc(sizeof(t_raw_dot));
			z_color_arr = ft_strsplit(line_arr[*column], ',');
			raw_dot->coord_z = ft_atoi(z_color_arr[0]);
			if (z_color_arr[1] == NULL)
				raw_dot->coord_color = 0;
			else
				raw_dot->coord_color = ft_atoi_base(z_color_arr[1], 16);
			raw_dot->coord_x = *row;
			raw_dot->coord_y = *column;
			raw_dot->next = NULL;
			if (*raw_dots_list == NULL)
			{
				*raw_dots_list = raw_dot;
				pend = raw_dot;
			}
			else
			{
				pend->next = raw_dot;
				pend = raw_dot;
			}
			(*column)++;
		}
		(*row)++;
	}
	return (0);
}


void   get_image_map(t_raw_dot *raw_dot_list, t_image_map **image_map, int *row, int *column)
{
	int	i;
	int  dot_number;
	t_raw_dot *tmp_list;
//	t_image_map *tmp_image_map;


	dot_number = (*row) * (*column);
	*image_map = (t_image_map *)malloc(sizeof(t_image_map));
	(*image_map)->coords_arr =  (int *)malloc(sizeof(int) * dot_number);
	(*image_map)->colors_arr =  (int *)malloc(sizeof(int) * dot_number);
	i = 0;

	tmp_list = raw_dot_list;
	while(tmp_list != NULL)
	{
		(*image_map)->coords_arr[i] = tmp_list->coord_z;
		(*image_map)->colors_arr[i] = tmp_list->coord_color;
		i++;
		tmp_list = tmp_list->next;
	}
	(*image_map)->image_width = *column;
	(*image_map)->image_height = *row;
//	*image_map = tmp_image_map;
}