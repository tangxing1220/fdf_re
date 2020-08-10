/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:16:52 by xtang             #+#    #+#             */
/*   Updated: 2020/08/08 20:16:57 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "mlx.h"
#include <fcntl.h>
#include "main.h"

int main(int argc, char **argv)
{
    int                 fd;
    t_coord_dot       *raw_dots_list;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if(read_from_file(&raw_dots_list, fd) == -1)
            return (-2);



    }
    return (0);
}