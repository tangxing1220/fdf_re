/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:46:02 by xtang             #+#    #+#             */
/*   Updated: 2019/10/31 14:38:34 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t len2;

	if (*needle == '\0')
		return ((char*)hay);
	len2 = ft_strlen(needle);
	while (*hay != '\0' && len-- >= len2)
	{
		if (*hay == *needle && ft_memcmp(hay, needle, len2) == 0)
			return ((char *)hay);
		hay++;
	}
	return (NULL);
}
