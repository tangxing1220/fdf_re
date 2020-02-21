/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:42:42 by xtang             #+#    #+#             */
/*   Updated: 2020/02/21 17:42:46 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <libft.h>

void terminate(char *s)
{
    if (errno == 0)
        ft_putendl_fd(s, 2);
    else
        perror(s);
    exit(1);    
    
}
