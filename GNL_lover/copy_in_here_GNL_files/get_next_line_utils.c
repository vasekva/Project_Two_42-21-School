/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 07:44:30 by jberegon          #+#    #+#             */
/*   Updated: 2020/12/04 11:39:20 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char			*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	str = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1 != NULL)
		while (s1[i])
		{
			str[j++] = s1[i];
			i++;
		}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = '\0';
	if (s1 != NULL)
		free(s1);
	return (str);
}

static int		ft_strlen_newline(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char			*ft_strdup_remainder(char *str)
{
	int		i;
	char	*str1;
	int		n;

	i = 0;
	n = 0;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	i = ft_strlen_newline(str);
	if (!(str1 = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1))))
	{
		free(str);
		return (NULL);
	}
	if (str[i])
		i++;
	while (str[i])
		str1[n++] = str[i++];
	str1[n] = '\0';
	free(str);
	return (str1);
}

char			*ft_strdup_line(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(tmp = (char *)malloc(sizeof(char) * i + 1)))
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
