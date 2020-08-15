/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:43:01 by xtang             #+#    #+#             */
/*   Updated: 2020/08/13 21:10:38 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_isdigit_base(char c, int base)
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

int		ft_atoi_base(const char *str, int base)
{
	size_t			index;
	unsigned long	result;

	index = 0;
	result = 0;
	while (ft_isspace(str[index]))
		index++;
	if (base == 16)
		index = index + 2;
	while (ft_isdigit_base(str[index], base) >= 0)
	{
		result = result * base + ft_isdigit_base(str[index++], base);
	}
	return ((int)result);
}

void	free_split_arr(char **array)
{
	size_t	index;

	index = 0;
	while (array[index] != NULL)
	{
		free(array[index]);
		index++;
	}
	free(array);
}

void	create_a_node(char **line_arr, t_raw_dot **raw_dot, int i, int j)
{
	char		**z_color_arr;

	(*raw_dot) = (t_raw_dot *)malloc(sizeof(t_raw_dot));
	z_color_arr = ft_strsplit(line_arr[j], ',');
	(*raw_dot)->coord_z = ft_atoi(z_color_arr[0]);
	if (z_color_arr[1] == NULL)
		(*raw_dot)->coord_color = 0;
	else
		(*raw_dot)->coord_color = ft_atoi_base(z_color_arr[1], 16);
	(*raw_dot)->coord_x = i;
	(*raw_dot)->coord_y = j;
	(*raw_dot)->next = NULL;
	free_split_arr(z_color_arr);
}

void	add_to_list(t_raw_dot **raw_dots_list, t_raw_dot *raw_dot)
{
	t_raw_dot *pend;

	if (*raw_dots_list == NULL)
	{
		*raw_dots_list = raw_dot;
		pend = raw_dot;
	}
	else
	{
		pend = *raw_dots_list;
		while (pend->next != NULL)
			pend = pend->next;
		pend->next = raw_dot;
	}
}

int		read_from_file(t_raw_dot **raw_dots_list, const int fd,\
						int *row, int *column)
{
	char		*line;
	char		**line_arr;
	t_raw_dot	*raw_dot;
	int			i;
	int			j;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		line_arr = ft_strsplit(line, ' ');
		while (line_arr[j] != NULL)
		{
			create_a_node(line_arr, &raw_dot, i, j);
			add_to_list(raw_dots_list, raw_dot);
			j++;
		}
		i++;
		(*row) = i;
		(*column) = j;
		free_split_arr(line_arr);
		free(line);
	}
	return (0);
}

void	get_image_map(t_raw_dot *raw_dot_list, t_image_map **image_map,\
							int row, int column)
{
	int			i;
	int			dot_number;
	t_raw_dot	*tmp_list;

	dot_number = (row) * (column);
	*image_map = (t_image_map *)malloc(sizeof(t_image_map));
	(*image_map)->z_max = 0;
	(*image_map)->z_min = 0;
	(*image_map)->coords_arr = (int *)malloc(sizeof(int) * dot_number);
	(*image_map)->colors_arr = (int *)malloc(sizeof(int) * dot_number);
	i = 0;
	tmp_list = raw_dot_list;
	while (tmp_list != NULL)
	{
		if (tmp_list->coord_z >= (*image_map)->z_max)
			(*image_map)->z_max = tmp_list->coord_z;
		if (tmp_list->coord_z <= (*image_map)->z_min)
			(*image_map)->z_min = tmp_list->coord_z;
		(*image_map)->coords_arr[i] = tmp_list->coord_z;
		(*image_map)->colors_arr[i] = tmp_list->coord_color;
		i++;
		tmp_list = tmp_list->next;
	}
	(*image_map)->image_width = column;
	(*image_map)->image_height = row;
}
