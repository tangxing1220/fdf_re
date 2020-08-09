/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:15:16 by xtang             #+#    #+#             */
/*   Updated: 2019/10/29 17:41:49 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cur;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cur = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (cur == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		cur[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		cur[i + j] = s2[j];
		j++;
	}
	cur[i + j] = '\0';
	return (cur);
}
