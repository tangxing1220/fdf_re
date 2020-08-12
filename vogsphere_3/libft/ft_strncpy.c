/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:00:17 by xtang             #+#    #+#             */
/*   Updated: 2019/10/23 17:02:04 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t cur;

	cur = 0;
	while (src[cur] != '\0' && cur < len)
	{
		dst[cur] = src[cur];
		cur++;
	}
	while (cur < len)
	{
		dst[cur] = '\0';
		cur++;
	}
	return (dst);
}
