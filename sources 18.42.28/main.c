/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:25:24 by xtang             #+#    #+#             */
/*   Updated: 2020/02/21 17:26:51 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fcntl.h>
#include <errno.h>
#include "error_message.h"

int main(int argc, char **argv)
{
    int fd;

    errno = 0;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
            terminate(ERR_MAP);






    }
    terminate(ERR_USAGE);
    return (0);





}
