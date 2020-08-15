/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:57:24 by xtang             #+#    #+#             */
/*   Updated: 2019/10/22 18:50:35 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	char	*cur;
	int		result;

	result = 0;
	cur = (char *)str;
	while (ft_isspace(*cur))
		cur++;
	sign = (*cur == '-') ? -1 : 1;
	cur = (*cur == '+' || *cur == '-') ? cur + 1 : cur;
	while (*cur >= '0' && *cur <= '9')
	{
		result = result * 10 + *cur - 48;
		cur++;
	}
	result *= sign;
	return (result);
}
