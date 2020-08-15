/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:23:45 by xtang             #+#    #+#             */
/*   Updated: 2019/10/23 17:29:56 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *c1;
	char *c2;

	if (n == 0 || dst == src)
		return (dst);
	c1 = (char *)dst;
	c2 = (char *)src;
	while (--n)
		*c1++ = *c2++;
	*c1 = *c2;
	return (dst);
}
