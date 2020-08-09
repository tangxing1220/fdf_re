/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:43:01 by xtang             #+#    #+#             */
/*   Updated: 2020/08/09 13:43:07 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/*
static int ft_atoi_base(const char *str, int base)
{
    int index;
    int sign; 
    int result;

    index = 0;
    sign = 1;
    result = 0;
    while(ft_isspace)

} 
*/

int     read_from_file(t_coord_dot **raw_dots, const int fd)
{
    int i;
    int row;
    int column;
    int ret_val;
    char *line;
    char **line_arr;
    char **z_color_arr;

    i = 0;
    row = 0;
    column = 0;
    while((ret_val = get_next_line(fd, &line)) == 1)
    {        
        column = 0;
        line_arr = ft_strsplit(line, ' ');
        while(line_arr[i] != NULL)
        {
            *raw_dots = (t_coord_dot *)malloc(sizeof(t_coord_dot));
            z_color_arr = ft_strsplit(line_arr[i], ',');
            raw_dots->coord_z = ft_atoi(z_color_arr[0]);
            raw_dots->coord_color = 0;  /* ft_atoi_base(z_color_arr[1], 16); */
            raw_dots->coord_x = row;
            raw_dots->coord_y = column;
            raw_dots->next = NULL;

            i++;
        }
        row++;
    }
}