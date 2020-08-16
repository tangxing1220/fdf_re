/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:34:21 by xtang             #+#    #+#             */
/*   Updated: 2020/08/06 17:10:50 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_line(char **bufstack, char **line)
{
	int		i;
	int		len;
	char	*tmpstack;

	i = 0;
	len = ft_strlen(*bufstack);
	while (bufstack[0][i] != '\0')
	{
		if (bufstack[0][i] == '\n')
		{
			if (i == (len - 1))
				tmpstack = NULL;
			else
				tmpstack = ft_strdup(*bufstack + i + 1);
			*line = ft_strsub(*bufstack, 0, i);
			ft_strdel(bufstack);
			*bufstack = tmpstack;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	read_to_end(int rd_result, char **bufstack, char **line)
{
	int result;

	if (rd_result == -1)
		result = -1;
	else if (rd_result == 0)
	{
		if (*bufstack != NULL)
		{
			*line = ft_strdup(*bufstack);
			ft_strdel(bufstack);
			result = 1;
		}
		else
			result = 0;
	}
	else
		result = 1;
	return (result);
}

static int	read_buff(int fd, char *bufheap, char **bufstack, char **line)
{
	int		rd_result;
	char	*temp_stack;
	int		status;
	int		aln;

	while ((rd_result = read(fd, bufheap, BUFF_SIZE)) > 0)
	{
		bufheap[rd_result] = '\0';
		if (*bufstack)
		{
			temp_stack = *bufstack;
			*bufstack = ft_strjoin(temp_stack, bufheap);
			free(temp_stack);
			temp_stack = NULL;
		}
		else
		{
			*bufstack = ft_strdup(bufheap);
		}
		aln = check_line(bufstack, line);
		if (aln == 1)
			return (1);
	}
	status = read_to_end(rd_result, bufstack, line);
	return (status);
}

int			get_next_line(const int fd, char **line)
{
	int			result;
	static char	*buf_stack;
	char		*buf_heap;

	if ((read(fd, buf_stack, 0) < 0))
		return (-1);
	if (!(buf_heap = (char *)malloc(BUFF_SIZE + 1)))
		return (-1);
	if (buf_stack)
	{
		if (check_line(&buf_stack, line))
		{
			free(buf_heap);
			return (1);
		}
	}
	result = read_buff(fd, buf_heap, &buf_stack, line);
	free(buf_heap);
	buf_heap = NULL;
	return (result);
}
