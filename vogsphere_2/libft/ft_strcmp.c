/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:19:31 by xtang             #+#    #+#             */
/*   Updated: 2019/10/29 15:21:40 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	char *c1;
	char *c2;

	c1 = (char *)s1;
	c2 = (char *)s2;
	while (*c1 != '\0' && *c2 != '\0')
	{
		if (*c1 != *c2)
			return ((unsigned char)*c1 - (unsigned char)*c2);
		c1++;
		c2++;
	}
	return ((unsigned char)*c1 - (unsigned char)*c2);
}
