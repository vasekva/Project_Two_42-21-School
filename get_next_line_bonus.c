/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:30:42 by jberegon          #+#    #+#             */
/*   Updated: 2020/12/04 13:30:49 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static long int	ft_check_buff(long int size)
{
	if (size > 8000000)
		return (8000000);
	return (size);
}

static int		ft_has_line(char *remainder)
{
	if (remainder == NULL)
		return (0);
	while (*remainder)
	{
		if (*remainder++ == '\n')
			return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*remainder[256];
	int			c_w_r;
	char		buff[ft_check_buff(BUFFER_SIZE) + 1];

	if (read(fd, buff, 0) < 0)
		return (-1);
	if ((BUFFER_SIZE < 1 || !line || fd < 0))
	{
		return (-1);
	}
	c_w_r = 1;
	while (c_w_r != 0 && ft_has_line(remainder[fd]) == 0)
	{
		if ((c_w_r = read(fd, buff, BUFFER_SIZE)) < 0)
			return (-1);
		buff[c_w_r] = '\0';
		if (!(remainder[fd] = ft_strjoin(remainder[fd], buff)))
			return (-1);
	}
	if (!(*line = ft_strdup_line(remainder[fd])))
		return (-1);
	if (!(remainder[fd] = ft_strdup_remainder(remainder[fd])) && c_w_r)
		return (-1);
	return (c_w_r ? 1 : 0);
}
