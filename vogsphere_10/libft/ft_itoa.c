/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:56:11 by xtang             #+#    #+#             */
/*   Updated: 2019/10/24 15:11:06 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lengths(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while ((n / *weight) < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

char		*ft_itoa(int n)
{
	size_t	len;
	int		weight;
	size_t	cur;
	char	*str;

	lengths(n, &len, &weight);
	str = (char *)malloc(sizeof(str) * (len + 1));
	if (str == NULL)
		return (NULL);
	cur = 0;
	if (n < 0)
	{
		str[cur] = '-';
		cur++;
	}
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		str[cur++] = -((n / weight) % 10) + 48;
		weight /= 10;
	}
	str[cur] = '\0';
	return (str);
}
