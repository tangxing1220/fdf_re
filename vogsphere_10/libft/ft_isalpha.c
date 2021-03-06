/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:20:30 by xtang             #+#    #+#             */
/*   Updated: 2019/10/22 18:25:37 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z'))
	{
		return (true);
	}
	return (false);
}
