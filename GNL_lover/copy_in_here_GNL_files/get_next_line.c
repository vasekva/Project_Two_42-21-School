/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 04:11:58 by jberegon          #+#    #+#             */
/*   Updated: 2020/12/04 11:39:06 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static int		ft_clear_all(char *buff, char *remainder)
{
	if (buff)
		free(buff);
	if (remainder)
		free(remainder);
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	static char	*remainder;
	int			c_w_r;
	char		*buff;

	if ((BUFFER_SIZE < 1 || !line || fd < 0) ||
		!(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (read(fd, buff, 0) < 0)
		return (-1);
	c_w_r = 1;
	while (c_w_r != 0 && ft_has_line(remainder) == 0)
	{
		if ((c_w_r = read(fd, buff, BUFFER_SIZE)) < 0)
			return (ft_clear_all(buff, remainder));
		buff[c_w_r] = '\0';
		if (!(remainder = ft_strjoin(remainder, buff)))
			return (ft_clear_all(buff, remainder));
	}
	free(buff);
	if (!(*line = ft_strdup_line(remainder)))
		return (ft_clear_all(buff, remainder));
	if (!(remainder = ft_strdup_remainder(remainder)) && c_w_r)
		return (ft_clear_all(buff, remainder));
	return (c_w_r ? 1 : 0);
}
