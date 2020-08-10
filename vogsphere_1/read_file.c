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

int				read_from_file(t_coord_dot **raw_dots_list, const int fd)
{
	int			i;
	int			row;
	int			column;
	int			ret_val;
	char		*line;
	char		**line_arr;
	char		**z_color_arr;
	t_coord_dot	*raw_dot;
	t_coord_dot	*pend;

	row = 0;
	column = 0;
	*raw_dots_list = NULL;
	while ((ret_val = get_next_line(fd, &line)) == 1)
	{
		column = 0;
		line_arr = ft_strsplit(line, ' ');
		while (line_arr[column] != NULL)
		{
			raw_dot = (t_coord_dot *)malloc(sizeof(t_coord_dot));
			z_color_arr = ft_strsplit(line_arr[column], ',');
			raw_dot->coord_z = ft_atoi(z_color_arr[0]);
			if (z_color_arr[1] == NULL)
				raw_dot->coord_color = 0;
			else
				raw_dot->coord_color = ft_atoi_base(z_color_arr[1], 16);
			raw_dot->coord_x = row;
			raw_dot->coord_y = column;
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
			column++;
		}
		row++;
	}
	return (0);
}


t_image_map  *get_image_map(t_raw_dot *raw_dot_list)
{
	
}