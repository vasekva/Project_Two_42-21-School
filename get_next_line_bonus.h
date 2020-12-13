/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:31:07 by jberegon          #+#    #+#             */
/*   Updated: 2020/12/04 13:32:20 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup_line(char *s1);
char	*ft_strdup_remainder(char *s1);

#endif
