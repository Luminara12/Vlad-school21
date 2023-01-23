/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptarrago <ptarrago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:21:47 by ptarrago          #+#    #+#             */
/*   Updated: 2022/06/11 12:56:11 by ptarrago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_read(int fd, char **buf)
{
	char	transfer[1024];
	char	*tempmem;
	int		i;

	i = 1;
	while ((ft_strchr(*buf, '\n') == 0) && i)
	{
		i = read(fd, transfer, 1024);
		transfer[i] = '\0';
		tempmem = *buf;
		*buf = ft_strjoin(tempmem, transfer);
		free(tempmem);
	}
	*transfer = 0;
	return (i);
}

static char	*ft_gnlsplit(char **buf)
{
	int		i;
	char	*line;
	char	*final;

	i = 0;
	line = 0;
	while ((*(*buf + i) != '\n') && (*(*buf + i) != '\0'))
		i++;
	if (*(*buf + i) == '\n')
	{
		line = ft_substr(*buf, i + 1, ft_strlen(*buf) - i - 1);
		final = ft_substr(*buf, 0, i + 1);
	}
	else
		final = ft_substr(*buf, 0, ft_strlen(*buf));
	free (*buf);
	*buf = line;
	return (final);
}

char	*get_next_line(int fd)
{
	int			l;
	static char	*buf;
	char		*final;

	if (fd < 0 || 1024 <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (buf == 0)
	{
		buf = ft_substr("", 0, 0);
		if (buf == 0)
			return (0);
	}
	l = ft_read(fd, &buf);
	final = ft_gnlsplit(&buf);
	if ((l == 0) && (*final == 0))
	{
		free(final);
		return (0);
	}
	return (final);
}
