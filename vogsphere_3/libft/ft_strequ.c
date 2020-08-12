/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:32:17 by xtang             #+#    #+#             */
/*   Updated: 2019/10/28 11:07:24 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
			return (0);
	}
	if (*str1 == '\0' && *str2 == '\0')
		return (1);
	else
		return (0);
}
