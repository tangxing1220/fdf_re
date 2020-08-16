/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:25:27 by xtang             #+#    #+#             */
/*   Updated: 2020/08/16 12:25:32 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
