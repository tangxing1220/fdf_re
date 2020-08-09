/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:16:30 by xtang             #+#    #+#             */
/*   Updated: 2020/08/08 20:16:37 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H

# define  MAIN_H

# include <stddef.h>
# include <stdlib.h>
# include "libft.h"

typedef struct              s_coord_point
{
    int                     coord_x;
    int                     coord_y;
    int                     coord_z;
    int                     coord_color;
    struct s_coord_point    *next;
}                           t_coord_dot;           

int     read_from_file(t_coord_dot **raw_dots, const int fd);

#endif
